#include "ff/evdw.h"
#include "ff/image.h"
#include "ff/spatial.h"
#include "ff/switch.h"
#include "math/switch.h"
#include "seq/add.h"
#include "seq/launch.h"
#include "seq/pair_hal.h"
#include "seq/triangle.h"

namespace tinker {
__global__
void ehalReduceXyz_cu1(int n, const int* restrict ired, const real* restrict kred,
   const real* restrict x, const real* restrict y, const real* restrict z, real* restrict xred,
   real* restrict yred, real* restrict zred)
{
   for (int i = ITHREAD; i < n; i += STRIDE) {
      auto iv = ired[i];
      auto rdn = kred[i];
      auto xi = x[i], xiv = x[iv];
      auto yi = y[i], yiv = y[iv];
      auto zi = z[i], ziv = z[iv];
      xred[i] = rdn * (xi - xiv) + xiv;
      yred[i] = rdn * (yi - yiv) + yiv;
      zred[i] = rdn * (zi - ziv) + ziv;
   }
}

void ehalReduceXyz_cu()
{
   launch_k1s(g::s0, n, ehalReduceXyz_cu1, n, ired, kred, x, y, z, xred, yred, zred);
}

__global__
void ehalResolveGradient_cu1(int n, const int* restrict ired, const real* restrict kred,
   const grad_prec* restrict gxred, const grad_prec* restrict gyred,
   const grad_prec* restrict gzred, grad_prec* restrict devx, grad_prec* restrict devy,
   grad_prec* restrict devz)
{
   for (int ii = ITHREAD; ii < n; ii += STRIDE) {
      auto grx = gxred[ii];
      auto gry = gyred[ii];
      auto grz = gzred[ii];
      auto iv = ired[ii];
      if (ii == iv) {
         atomic_add(grx, devx, ii);
         atomic_add(gry, devy, ii);
         atomic_add(grz, devz, ii);
      } else {
         auto fx = toFloatGrad<real>(grx);
         auto fy = toFloatGrad<real>(gry);
         auto fz = toFloatGrad<real>(grz);
         auto redii = kred[ii];
         auto rediv = 1 - redii;
         atomic_add(fx * redii, devx, ii);
         atomic_add(fy * redii, devy, ii);
         atomic_add(fz * redii, devz, ii);
         atomic_add(fx * rediv, devx, iv);
         atomic_add(fy * rediv, devy, iv);
         atomic_add(fz * rediv, devz, iv);
      }
   }
}

void ehalResolveGradient_cu()
{
   launch_k1s(g::s0, n, ehalResolveGradient_cu1, //
      n, ired, kred, gxred, gyred, gzred, devx, devy, devz);
}
}

/**
 * Overheads:
 *    - Different vcouple methods.
 *    - PBC type in image().
 *    - Random access to the "i" parameters and gradients.
 *    - (If not hard-coded) ghal, dhal, scexp, scalpha.
 */

/**
 * Kernel ehal_cu1 on GTX 1070 for DHFR2
 * 7 angstroms cutoff and 10 % buffer
 *
 * unsorted (a) | generic image (b) | decouple vlambda (c) | 1e-6 s
 * --------------------------------------------------------------------
 * -            | -                 | -                    | 342
 * +            | -                 | -                    | 348
 * +            | -                 | +                    | 366
 * +            | +                 | -                    | 373
 * +            | +                 | +                    | 382
 * --------------------------------------------------------------------
 * (a) - assuming sorted[i].unsorted == i, no random memory access for the "i"
 *     parameters and gradients; + the original code.
 * (b) - hard-coded orthogonal image routine; + generic image routine.
 * (c) - hard-coded decouple method; + generic vlambda method.
 */

namespace tinker {
#if 1
#   define GHAL    (real)0.12
#   define DHAL    (real)0.07
#   define SCEXP   5
#   define SCALPHA (real)0.7
#elif 0
#   define GHAL    ghal
#   define DHAL    dhal
#   define SCEXP   scexp
#   define SCALPHA scalpha
#endif
// ck.py Version 2.0.2
template <class Ver>
__global__
void ehal_cu1(int n, TINKER_IMAGE_PARAMS, CountBuffer restrict nev, EnergyBuffer restrict ev,
   VirialBuffer restrict vev, grad_prec* restrict gx, grad_prec* restrict gy,
   grad_prec* restrict gz, real cut, real off, const unsigned* restrict info, int nexclude,
   const int (*restrict exclude)[2], const real* restrict exclude_scale, const real* restrict x,
   const real* restrict y, const real* restrict z, const Spatial::SortedAtom* restrict sorted,
   int nakpl, const int* restrict iakpl, int niak, const int* restrict iak, const int* restrict lst,
   int njvdw, real vlam, Vdw vcouple, const real* restrict radmin, const real* restrict epsilon,
   const int* restrict jvdw, const int* restrict mut)
{
   constexpr bool do_e = Ver::e;
   constexpr bool do_a = Ver::a;
   constexpr bool do_g = Ver::g;
   constexpr bool do_v = Ver::v;
   const int ithread = threadIdx.x + blockIdx.x * blockDim.x;
   const int iwarp = ithread / WARP_SIZE;
   const int nwarp = blockDim.x * gridDim.x / WARP_SIZE;
   const int ilane = threadIdx.x & (WARP_SIZE - 1);

   int nevtl;
   if CONSTEXPR (do_a) {
      nevtl = 0;
   }
   using ebuf_prec = EnergyBufferTraits::type;
   ebuf_prec evtl;
   if CONSTEXPR (do_e) {
      evtl = 0;
   }
   using vbuf_prec = VirialBufferTraits::type;
   vbuf_prec vevtlxx, vevtlyx, vevtlzx, vevtlyy, vevtlzy, vevtlzz;
   if CONSTEXPR (do_v) {
      vevtlxx = 0;
      vevtlyx = 0;
      vevtlzx = 0;
      vevtlyy = 0;
      vevtlzy = 0;
      vevtlzz = 0;
   }
   real xi;
   real yi;
   real zi;
   real xk;
   real yk;
   real zk;
   real fix;
   real fiy;
   real fiz;
   real fkx;
   real fky;
   real fkz;
   int ijvdw;
   int imut;
   int kjvdw;
   int kmut;

   //* /
   for (int ii = ithread; ii < nexclude; ii += blockDim.x * gridDim.x) {
      if CONSTEXPR (do_g) {
         fix = 0;
         fiy = 0;
         fiz = 0;
         fkx = 0;
         fky = 0;
         fkz = 0;
      }

      int i = exclude[ii][0];
      int k = exclude[ii][1];
      real scalea = exclude_scale[ii];

      xi = x[i];
      yi = y[i];
      zi = z[i];
      xk = x[k];
      yk = y[k];
      zk = z[k];
      ijvdw = jvdw[i];
      imut = mut[i];
      kjvdw = jvdw[k];
      kmut = mut[k];

      constexpr bool incl = true;
      real xr = xi - xk;
      real yr = yi - yk;
      real zr = zi - zk;
      real r2 = image2(xr, yr, zr);
      if (r2 <= off * off and incl) {
         real r = REAL_SQRT(r2);
         real rv = radmin[ijvdw * njvdw + kjvdw];
         real eps = epsilon[ijvdw * njvdw + kjvdw];
         real vlambda = 1;
         if (vcouple == Vdw::DECOUPLE) {
            vlambda = (imut == kmut ? 1 : vlam);
         } else if (vcouple == Vdw::ANNIHILATE) {
            vlambda = (imut || kmut ? vlam : 1);
         }
         real e, de;
         pair_hal_v2<do_g, 0>(
            r, scalea, rv, eps, cut, off, vlambda, GHAL, DHAL, SCEXP, SCALPHA, e, de);
         if CONSTEXPR (do_e) {
            evtl += floatTo<ebuf_prec>(e);
            if CONSTEXPR (do_a) {
               if (scalea != 0 and e != 0)
                  nevtl += 1;
            }
         }
         if CONSTEXPR (do_g) {
            real dedx, dedy, dedz;
            de = de * REAL_RECIP(r);
            dedx = de * xr;
            dedy = de * yr;
            dedz = de * zr;
            fix += dedx;
            fiy += dedy;
            fiz += dedz;
            fkx -= dedx;
            fky -= dedy;
            fkz -= dedz;
            if CONSTEXPR (do_v) {
               vevtlxx += floatTo<vbuf_prec>(xr * dedx);
               vevtlyx += floatTo<vbuf_prec>(yr * dedx);
               vevtlzx += floatTo<vbuf_prec>(zr * dedx);
               vevtlyy += floatTo<vbuf_prec>(yr * dedy);
               vevtlzy += floatTo<vbuf_prec>(zr * dedy);
               vevtlzz += floatTo<vbuf_prec>(zr * dedz);
            }
         }
      }

      if CONSTEXPR (do_g) {
         atomic_add(fix, gx, i);
         atomic_add(fiy, gy, i);
         atomic_add(fiz, gz, i);
         atomic_add(fkx, gx, k);
         atomic_add(fky, gy, k);
         atomic_add(fkz, gz, k);
      }
   }
   // */

   for (int iw = iwarp; iw < nakpl; iw += nwarp) {
      if CONSTEXPR (do_g) {
         fix = 0;
         fiy = 0;
         fiz = 0;
         fkx = 0;
         fky = 0;
         fkz = 0;
      }

      int tri, tx, ty;
      tri = iakpl[iw];
      tri_to_xy(tri, tx, ty);

      int iid = ty * WARP_SIZE + ilane;
      int atomi = min(iid, n - 1);
      int i = sorted[atomi].unsorted;
      int kid = tx * WARP_SIZE + ilane;
      int atomk = min(kid, n - 1);
      int k = sorted[atomk].unsorted;
      xi = sorted[atomi].x;
      yi = sorted[atomi].y;
      zi = sorted[atomi].z;
      xk = sorted[atomk].x;
      yk = sorted[atomk].y;
      zk = sorted[atomk].z;

      ijvdw = jvdw[i];
      imut = mut[i];
      kjvdw = jvdw[k];
      kmut = mut[k];

      unsigned int info0 = info[iw * WARP_SIZE + ilane];
      for (int j = 0; j < WARP_SIZE; ++j) {
         int srclane = (ilane + j) & (WARP_SIZE - 1);
         bool incl = iid < kid and kid < n;
         int srcmask = 1 << srclane;
         incl = incl and (info0 & srcmask) == 0;
         real xr = xi - xk;
         real yr = yi - yk;
         real zr = zi - zk;
         real r2 = image2(xr, yr, zr);
         if (r2 <= off * off and incl) {
            real r = REAL_SQRT(r2);
            real rv = radmin[ijvdw * njvdw + kjvdw];
            real eps = epsilon[ijvdw * njvdw + kjvdw];
            real vlambda = 1;
            if (vcouple == Vdw::DECOUPLE) {
               vlambda = (imut == kmut ? 1 : vlam);
            } else if (vcouple == Vdw::ANNIHILATE) {
               vlambda = (imut || kmut ? vlam : 1);
            }
            real e, de;
            pair_hal_v2<do_g, 1>(
               r, 1, rv, eps, cut, off, vlambda, GHAL, DHAL, SCEXP, SCALPHA, e, de);
            if CONSTEXPR (do_e) {
               evtl += floatTo<ebuf_prec>(e);
               if CONSTEXPR (do_a) {
                  if (e != 0)
                     nevtl += 1;
               }
            }
            if CONSTEXPR (do_g) {
               real dedx, dedy, dedz;
               de = de * REAL_RECIP(r);
               dedx = de * xr;
               dedy = de * yr;
               dedz = de * zr;
               fix += dedx;
               fiy += dedy;
               fiz += dedz;
               fkx -= dedx;
               fky -= dedy;
               fkz -= dedz;
               if CONSTEXPR (do_v) {
                  vevtlxx += floatTo<vbuf_prec>(xr * dedx);
                  vevtlyx += floatTo<vbuf_prec>(yr * dedx);
                  vevtlzx += floatTo<vbuf_prec>(zr * dedx);
                  vevtlyy += floatTo<vbuf_prec>(yr * dedy);
                  vevtlzy += floatTo<vbuf_prec>(zr * dedy);
                  vevtlzz += floatTo<vbuf_prec>(zr * dedz);
               }
            }
         }

         iid = __shfl_sync(ALL_LANES, iid, ilane + 1);
         xi = __shfl_sync(ALL_LANES, xi, ilane + 1);
         yi = __shfl_sync(ALL_LANES, yi, ilane + 1);
         zi = __shfl_sync(ALL_LANES, zi, ilane + 1);
         ijvdw = __shfl_sync(ALL_LANES, ijvdw, ilane + 1);
         imut = __shfl_sync(ALL_LANES, imut, ilane + 1);
         if CONSTEXPR (do_g) {
            fix = __shfl_sync(ALL_LANES, fix, ilane + 1);
            fiy = __shfl_sync(ALL_LANES, fiy, ilane + 1);
            fiz = __shfl_sync(ALL_LANES, fiz, ilane + 1);
         }
      }

      if CONSTEXPR (do_g) {
         atomic_add(fix, gx, i);
         atomic_add(fiy, gy, i);
         atomic_add(fiz, gz, i);
         atomic_add(fkx, gx, k);
         atomic_add(fky, gy, k);
         atomic_add(fkz, gz, k);
      }
   }

   for (int iw = iwarp; iw < niak; iw += nwarp) {
      if CONSTEXPR (do_g) {
         fix = 0;
         fiy = 0;
         fiz = 0;
         fkx = 0;
         fky = 0;
         fkz = 0;
      }

      int ty = iak[iw];
      int atomi = ty * WARP_SIZE + ilane;
      int i = sorted[atomi].unsorted;
      int atomk = lst[iw * WARP_SIZE + ilane];
      int k = sorted[atomk].unsorted;
      xi = sorted[atomi].x;
      yi = sorted[atomi].y;
      zi = sorted[atomi].z;
      xk = sorted[atomk].x;
      yk = sorted[atomk].y;
      zk = sorted[atomk].z;

      ijvdw = jvdw[i];
      imut = mut[i];
      kjvdw = jvdw[k];
      kmut = mut[k];

      for (int j = 0; j < WARP_SIZE; ++j) {
         bool incl = atomk > 0;
         real xr = xi - xk;
         real yr = yi - yk;
         real zr = zi - zk;
         real r2 = image2(xr, yr, zr);
         if (r2 <= off * off and incl) {
            real r = REAL_SQRT(r2);
            real rv = radmin[ijvdw * njvdw + kjvdw];
            real eps = epsilon[ijvdw * njvdw + kjvdw];
            real vlambda = 1;
            if (vcouple == Vdw::DECOUPLE) {
               vlambda = (imut == kmut ? 1 : vlam);
            } else if (vcouple == Vdw::ANNIHILATE) {
               vlambda = (imut || kmut ? vlam : 1);
            }
            real e, de;
            pair_hal_v2<do_g, 1>(
               r, 1, rv, eps, cut, off, vlambda, GHAL, DHAL, SCEXP, SCALPHA, e, de);
            if CONSTEXPR (do_e) {
               evtl += floatTo<ebuf_prec>(e);
               if CONSTEXPR (do_a) {
                  if (e != 0)
                     nevtl += 1;
               }
            }
            if CONSTEXPR (do_g) {
               real dedx, dedy, dedz;
               de = de * REAL_RECIP(r);
               dedx = de * xr;
               dedy = de * yr;
               dedz = de * zr;
               fix += dedx;
               fiy += dedy;
               fiz += dedz;
               fkx -= dedx;
               fky -= dedy;
               fkz -= dedz;
               if CONSTEXPR (do_v) {
                  vevtlxx += floatTo<vbuf_prec>(xr * dedx);
                  vevtlyx += floatTo<vbuf_prec>(yr * dedx);
                  vevtlzx += floatTo<vbuf_prec>(zr * dedx);
                  vevtlyy += floatTo<vbuf_prec>(yr * dedy);
                  vevtlzy += floatTo<vbuf_prec>(zr * dedy);
                  vevtlzz += floatTo<vbuf_prec>(zr * dedz);
               }
            }
         }

         xi = __shfl_sync(ALL_LANES, xi, ilane + 1);
         yi = __shfl_sync(ALL_LANES, yi, ilane + 1);
         zi = __shfl_sync(ALL_LANES, zi, ilane + 1);
         ijvdw = __shfl_sync(ALL_LANES, ijvdw, ilane + 1);
         imut = __shfl_sync(ALL_LANES, imut, ilane + 1);
         if CONSTEXPR (do_g) {
            fix = __shfl_sync(ALL_LANES, fix, ilane + 1);
            fiy = __shfl_sync(ALL_LANES, fiy, ilane + 1);
            fiz = __shfl_sync(ALL_LANES, fiz, ilane + 1);
         }
      }

      if CONSTEXPR (do_g) {
         atomic_add(fix, gx, i);
         atomic_add(fiy, gy, i);
         atomic_add(fiz, gz, i);
         atomic_add(fkx, gx, k);
         atomic_add(fky, gy, k);
         atomic_add(fkz, gz, k);
      }
   }

   if CONSTEXPR (do_a) {
      atomic_add(nevtl, nev, ithread);
   }
   if CONSTEXPR (do_e) {
      atomic_add(evtl, ev, ithread);
   }
   if CONSTEXPR (do_v) {
      atomic_add(vevtlxx, vevtlyx, vevtlzx, vevtlyy, vevtlzy, vevtlzz, vev, ithread);
   }
}

template <class Ver>
static void ehal_cu3()
{
   constexpr bool do_g = Ver::g;

   const auto& st = *vspatial_v2_unit;
   const real cut = switchCut(Switch::VDW);
   const real off = switchOff(Switch::VDW);

   if CONSTEXPR (do_g)
      darray::zero(g::q0, n, gxred, gyred, gzred);

   int ngrid = gpuGridSize(BLOCK_DIM);
   auto ker1 = ehal_cu1<Ver>;
   ker1<<<ngrid, BLOCK_DIM, 0, g::s0>>>(st.n, TINKER_IMAGE_ARGS, nev, ev, vir_ev, gxred, gyred,
      gzred, cut, off, st.si1.bit0, nvexclude, vexclude, vexclude_scale, st.x, st.y, st.z,
      st.sorted, st.nakpl, st.iakpl, st.niak, st.iak, st.lst, njvdw, vlam, vcouple, radmin, epsilon,
      jvdw, mut);

   if CONSTEXPR (do_g) {
      ehalResolveGradient();
   }
}

void ehal_cu(int vers)
{
   if (vers == calc::v0)
      ehal_cu3<calc::V0>();
   else if (vers == calc::v1)
      ehal_cu3<calc::V1>();
   else if (vers == calc::v3)
      ehal_cu3<calc::V3>();
   else if (vers == calc::v4)
      ehal_cu3<calc::V4>();
   else if (vers == calc::v5)
      ehal_cu3<calc::V5>();
   else if (vers == calc::v6)
      ehal_cu3<calc::V6>();
}
}
