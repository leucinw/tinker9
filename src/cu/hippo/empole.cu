#include "ff/amoebamod.h"
#include "ff/hippomod.h"
#include "ff/image.h"
#include "ff/pme.h"
#include "ff/spatial.h"
#include "ff/switch.h"
#include "seq/emselfhippo.h"
#include "seq/launch.h"
#include "seq/pair_mpole_chgpen.h"
#include "seq/triangle.h"
#include <cassert>

namespace tinker {
// ck.py Version 2.0.3
template <class Ver, class ETYP, bool CFLX>
__global__
void empoleChgpen_cu1(int n, TINKER_IMAGE_PARAMS, CountBuffer restrict nem,
   EnergyBuffer restrict em, VirialBuffer restrict vem, grad_prec* restrict gx,
   grad_prec* restrict gy, grad_prec* restrict gz, real off, const unsigned* restrict minfo,
   int nexclude, const int (*restrict exclude)[2], const real (*restrict exclude_scale)[3],
   const real* restrict x, const real* restrict y, const real* restrict z,
   const Spatial::SortedAtom* restrict sorted, int nakpl, const int* restrict iakpl, int niak,
   const int* restrict iak, const int* restrict lst, real* restrict trqx, real* restrict trqy,
   real* restrict trqz, real* restrict pot, const real (*restrict rpole)[10], real* restrict pcore,
   real* restrict pval, const real* restrict palpha, real aewald, real f)
{
   constexpr bool do_a = Ver::a;
   constexpr bool do_e = Ver::e;
   constexpr bool do_v = Ver::v;
   constexpr bool do_g = Ver::g;
   const int ithread = threadIdx.x + blockIdx.x * blockDim.x;
   const int iwarp = ithread / WARP_SIZE;
   const int nwarp = blockDim.x * gridDim.x / WARP_SIZE;
   const int ilane = threadIdx.x & (WARP_SIZE - 1);

   int nemtl;
   if CONSTEXPR (do_a) {
      nemtl = 0;
   }
   using ebuf_prec = EnergyBufferTraits::type;
   ebuf_prec emtl;
   if CONSTEXPR (do_e) {
      emtl = 0;
   }
   using vbuf_prec = VirialBufferTraits::type;
   vbuf_prec vemtlxx, vemtlyx, vemtlzx, vemtlyy, vemtlzy, vemtlzz;
   if CONSTEXPR (do_v) {
      vemtlxx = 0;
      vemtlyx = 0;
      vemtlzx = 0;
      vemtlyy = 0;
      vemtlzy = 0;
      vemtlzz = 0;
   }
   __shared__ real xi[BLOCK_DIM];
   __shared__ real yi[BLOCK_DIM];
   __shared__ real zi[BLOCK_DIM];
   real xk;
   real yk;
   real zk;
   __shared__ real gxi[BLOCK_DIM];
   __shared__ real gyi[BLOCK_DIM];
   __shared__ real gzi[BLOCK_DIM];
   __shared__ real txi[BLOCK_DIM];
   __shared__ real tyi[BLOCK_DIM];
   __shared__ real tzi[BLOCK_DIM];
   __shared__ real poti[BLOCK_DIM];
   real gxk;
   real gyk;
   real gzk;
   real txk;
   real tyk;
   real tzk;
   real potk;
   __shared__ real ci[BLOCK_DIM];
   __shared__ real dix[BLOCK_DIM];
   __shared__ real diy[BLOCK_DIM];
   __shared__ real diz[BLOCK_DIM];
   __shared__ real qixx[BLOCK_DIM];
   __shared__ real qixy[BLOCK_DIM];
   __shared__ real qixz[BLOCK_DIM];
   __shared__ real qiyy[BLOCK_DIM];
   __shared__ real qiyz[BLOCK_DIM];
   __shared__ real qizz[BLOCK_DIM];
   __shared__ real corei[BLOCK_DIM];
   __shared__ real alphai[BLOCK_DIM];
   __shared__ real vali[BLOCK_DIM];
   real ck;
   real dkx;
   real dky;
   real dkz;
   real qkxx;
   real qkxy;
   real qkxz;
   real qkyy;
   real qkyz;
   real qkzz;
   real corek;
   real alphak;
   real valk;

   //* /
   for (int ii = ithread; ii < nexclude; ii += blockDim.x * gridDim.x) {
      const int klane = threadIdx.x;
      if CONSTEXPR (do_g) {
         gxi[threadIdx.x] = 0;
         gyi[threadIdx.x] = 0;
         gzi[threadIdx.x] = 0;
         txi[threadIdx.x] = 0;
         tyi[threadIdx.x] = 0;
         tzi[threadIdx.x] = 0;
         if CONSTEXPR (CFLX)
            poti[threadIdx.x] = 0;
         gxk = 0;
         gyk = 0;
         gzk = 0;
         txk = 0;
         tyk = 0;
         tzk = 0;
         if CONSTEXPR (CFLX)
            potk = 0;
      }

      int i = exclude[ii][0];
      int k = exclude[ii][1];
      real scalea = exclude_scale[ii][0];

      xi[klane] = x[i];
      yi[klane] = y[i];
      zi[klane] = z[i];
      xk = x[k];
      yk = y[k];
      zk = z[k];
      ci[klane] = rpole[i][MPL_PME_0];
      dix[klane] = rpole[i][MPL_PME_X];
      diy[klane] = rpole[i][MPL_PME_Y];
      diz[klane] = rpole[i][MPL_PME_Z];
      qixx[klane] = rpole[i][MPL_PME_XX];
      qixy[klane] = rpole[i][MPL_PME_XY];
      qixz[klane] = rpole[i][MPL_PME_XZ];
      qiyy[klane] = rpole[i][MPL_PME_YY];
      qiyz[klane] = rpole[i][MPL_PME_YZ];
      qizz[klane] = rpole[i][MPL_PME_ZZ];
      corei[klane] = pcore[i];
      alphai[klane] = palpha[i];
      vali[klane] = pval[i];
      ck = rpole[k][MPL_PME_0];
      dkx = rpole[k][MPL_PME_X];
      dky = rpole[k][MPL_PME_Y];
      dkz = rpole[k][MPL_PME_Z];
      qkxx = rpole[k][MPL_PME_XX];
      qkxy = rpole[k][MPL_PME_XY];
      qkxz = rpole[k][MPL_PME_XZ];
      qkyy = rpole[k][MPL_PME_YY];
      qkyz = rpole[k][MPL_PME_YZ];
      qkzz = rpole[k][MPL_PME_ZZ];
      corek = pcore[k];
      alphak = palpha[k];
      valk = pval[k];

      constexpr bool incl = true;
      real xr = xk - xi[klane];
      real yr = yk - yi[klane];
      real zr = zk - zi[klane];

      real e;
      real pota, potb;
      PairMPoleGrad pgrad;
      zero(pgrad);

      real r2 = image2(xr, yr, zr);
      if (r2 <= off * off and incl) {
         pair_mpole_chgpen<do_e, do_g, ETYP, CFLX>(r2, xr, yr, zr, scalea, //
            ci[klane], dix[klane], diy[klane], diz[klane], corei[klane], vali[klane],
            alphai[klane], //
            qixx[klane], qixy[klane], qixz[klane], qiyy[klane], qiyz[klane],
            qizz[klane],                            //
            ck, dkx, dky, dkz, corek, valk, alphak, //
            qkxx, qkxy, qkxz, qkyy, qkyz, qkzz,     //
            f, aewald, e, pota, potb, pgrad);

         if CONSTEXPR (do_a)
            if (e != 0 and scalea != 0)
               nemtl += 1;
         if CONSTEXPR (do_e)
            emtl += floatTo<ebuf_prec>(e);
         if CONSTEXPR (do_g) {
            gxi[klane] += pgrad.frcx;
            gyi[klane] += pgrad.frcy;
            gzi[klane] += pgrad.frcz;
            gxk -= pgrad.frcx;
            gyk -= pgrad.frcy;
            gzk -= pgrad.frcz;

            txi[klane] += pgrad.ttmi[0];
            tyi[klane] += pgrad.ttmi[1];
            tzi[klane] += pgrad.ttmi[2];
            txk += pgrad.ttmk[0];
            tyk += pgrad.ttmk[1];
            tzk += pgrad.ttmk[2];
         }
         if CONSTEXPR (do_v) {
            vemtlxx += floatTo<vbuf_prec>(-xr * pgrad.frcx);
            vemtlyx += floatTo<vbuf_prec>(-0.5f * (yr * pgrad.frcx + xr * pgrad.frcy));
            vemtlzx += floatTo<vbuf_prec>(-0.5f * (zr * pgrad.frcx + xr * pgrad.frcz));
            vemtlyy += floatTo<vbuf_prec>(-yr * pgrad.frcy);
            vemtlzy += floatTo<vbuf_prec>(-0.5f * (zr * pgrad.frcy + yr * pgrad.frcz));
            vemtlzz += floatTo<vbuf_prec>(-zr * pgrad.frcz);
         }
         if CONSTEXPR (CFLX) {
            poti[klane] += pota;
            potk += potb;
         }
      } // end if (include)

      if CONSTEXPR (do_g) {
         atomic_add(gxi[threadIdx.x], gx, i);
         atomic_add(gyi[threadIdx.x], gy, i);
         atomic_add(gzi[threadIdx.x], gz, i);
         atomic_add(txi[threadIdx.x], trqx, i);
         atomic_add(tyi[threadIdx.x], trqy, i);
         atomic_add(tzi[threadIdx.x], trqz, i);
         if CONSTEXPR (CFLX)
            atomic_add(poti[threadIdx.x], pot, i);
         atomic_add(gxk, gx, k);
         atomic_add(gyk, gy, k);
         atomic_add(gzk, gz, k);
         atomic_add(txk, trqx, k);
         atomic_add(tyk, trqy, k);
         atomic_add(tzk, trqz, k);
         if CONSTEXPR (CFLX)
            atomic_add(potk, pot, k);
      }
   }
   // */

   for (int iw = iwarp; iw < nakpl; iw += nwarp) {
      if CONSTEXPR (do_g) {
         gxi[threadIdx.x] = 0;
         gyi[threadIdx.x] = 0;
         gzi[threadIdx.x] = 0;
         txi[threadIdx.x] = 0;
         tyi[threadIdx.x] = 0;
         tzi[threadIdx.x] = 0;
         if CONSTEXPR (CFLX)
            poti[threadIdx.x] = 0;
         gxk = 0;
         gyk = 0;
         gzk = 0;
         txk = 0;
         tyk = 0;
         tzk = 0;
         if CONSTEXPR (CFLX)
            potk = 0;
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
      xi[threadIdx.x] = sorted[atomi].x;
      yi[threadIdx.x] = sorted[atomi].y;
      zi[threadIdx.x] = sorted[atomi].z;
      xk = sorted[atomk].x;
      yk = sorted[atomk].y;
      zk = sorted[atomk].z;

      ci[threadIdx.x] = rpole[i][MPL_PME_0];
      dix[threadIdx.x] = rpole[i][MPL_PME_X];
      diy[threadIdx.x] = rpole[i][MPL_PME_Y];
      diz[threadIdx.x] = rpole[i][MPL_PME_Z];
      qixx[threadIdx.x] = rpole[i][MPL_PME_XX];
      qixy[threadIdx.x] = rpole[i][MPL_PME_XY];
      qixz[threadIdx.x] = rpole[i][MPL_PME_XZ];
      qiyy[threadIdx.x] = rpole[i][MPL_PME_YY];
      qiyz[threadIdx.x] = rpole[i][MPL_PME_YZ];
      qizz[threadIdx.x] = rpole[i][MPL_PME_ZZ];
      corei[threadIdx.x] = pcore[i];
      alphai[threadIdx.x] = palpha[i];
      vali[threadIdx.x] = pval[i];
      ck = rpole[k][MPL_PME_0];
      dkx = rpole[k][MPL_PME_X];
      dky = rpole[k][MPL_PME_Y];
      dkz = rpole[k][MPL_PME_Z];
      qkxx = rpole[k][MPL_PME_XX];
      qkxy = rpole[k][MPL_PME_XY];
      qkxz = rpole[k][MPL_PME_XZ];
      qkyy = rpole[k][MPL_PME_YY];
      qkyz = rpole[k][MPL_PME_YZ];
      qkzz = rpole[k][MPL_PME_ZZ];
      corek = pcore[k];
      alphak = palpha[k];
      valk = pval[k];

      unsigned int minfo0 = minfo[iw * WARP_SIZE + ilane];
      for (int j = 0; j < WARP_SIZE; ++j) {
         int srclane = (ilane + j) & (WARP_SIZE - 1);
         int klane = srclane + threadIdx.x - ilane;
         bool incl = iid < kid and kid < n;
         int srcmask = 1 << srclane;
         incl = incl and (minfo0 & srcmask) == 0;
         real xr = xk - xi[klane];
         real yr = yk - yi[klane];
         real zr = zk - zi[klane];

         real e;
         real pota, potb;
         PairMPoleGrad pgrad;
         zero(pgrad);

         real r2 = image2(xr, yr, zr);
         if (r2 <= off * off and incl) {
            pair_mpole_chgpen<do_e, do_g, ETYP, CFLX>(r2, xr, yr, zr, 1, //
               ci[klane], dix[klane], diy[klane], diz[klane], corei[klane], vali[klane],
               alphai[klane], //
               qixx[klane], qixy[klane], qixz[klane], qiyy[klane], qiyz[klane],
               qizz[klane],                            //
               ck, dkx, dky, dkz, corek, valk, alphak, //
               qkxx, qkxy, qkxz, qkyy, qkyz, qkzz,     //
               f, aewald, e, pota, potb, pgrad);

            if CONSTEXPR (do_a)
               if (e != 0)
                  nemtl += 1;
            if CONSTEXPR (do_e)
               emtl += floatTo<ebuf_prec>(e);
            if CONSTEXPR (do_g) {
               gxi[klane] += pgrad.frcx;
               gyi[klane] += pgrad.frcy;
               gzi[klane] += pgrad.frcz;
               gxk -= pgrad.frcx;
               gyk -= pgrad.frcy;
               gzk -= pgrad.frcz;

               txi[klane] += pgrad.ttmi[0];
               tyi[klane] += pgrad.ttmi[1];
               tzi[klane] += pgrad.ttmi[2];
               txk += pgrad.ttmk[0];
               tyk += pgrad.ttmk[1];
               tzk += pgrad.ttmk[2];
            }
            if CONSTEXPR (do_v) {
               vemtlxx += floatTo<vbuf_prec>(-xr * pgrad.frcx);
               vemtlyx += floatTo<vbuf_prec>(-0.5f * (yr * pgrad.frcx + xr * pgrad.frcy));
               vemtlzx += floatTo<vbuf_prec>(-0.5f * (zr * pgrad.frcx + xr * pgrad.frcz));
               vemtlyy += floatTo<vbuf_prec>(-yr * pgrad.frcy);
               vemtlzy += floatTo<vbuf_prec>(-0.5f * (zr * pgrad.frcy + yr * pgrad.frcz));
               vemtlzz += floatTo<vbuf_prec>(-zr * pgrad.frcz);
            }
            if CONSTEXPR (CFLX) {
               poti[klane] += pota;
               potk += potb;
            }
         } // end if (include)

         iid = __shfl_sync(ALL_LANES, iid, ilane + 1);
      }

      if CONSTEXPR (do_g) {
         atomic_add(gxi[threadIdx.x], gx, i);
         atomic_add(gyi[threadIdx.x], gy, i);
         atomic_add(gzi[threadIdx.x], gz, i);
         atomic_add(txi[threadIdx.x], trqx, i);
         atomic_add(tyi[threadIdx.x], trqy, i);
         atomic_add(tzi[threadIdx.x], trqz, i);
         if CONSTEXPR (CFLX)
            atomic_add(poti[threadIdx.x], pot, i);
         atomic_add(gxk, gx, k);
         atomic_add(gyk, gy, k);
         atomic_add(gzk, gz, k);
         atomic_add(txk, trqx, k);
         atomic_add(tyk, trqy, k);
         atomic_add(tzk, trqz, k);
         if CONSTEXPR (CFLX)
            atomic_add(potk, pot, k);
      }
   }

   for (int iw = iwarp; iw < niak; iw += nwarp) {
      if CONSTEXPR (do_g) {
         gxi[threadIdx.x] = 0;
         gyi[threadIdx.x] = 0;
         gzi[threadIdx.x] = 0;
         txi[threadIdx.x] = 0;
         tyi[threadIdx.x] = 0;
         tzi[threadIdx.x] = 0;
         if CONSTEXPR (CFLX)
            poti[threadIdx.x] = 0;
         gxk = 0;
         gyk = 0;
         gzk = 0;
         txk = 0;
         tyk = 0;
         tzk = 0;
         if CONSTEXPR (CFLX)
            potk = 0;
      }

      int ty = iak[iw];
      int atomi = ty * WARP_SIZE + ilane;
      int i = sorted[atomi].unsorted;
      int atomk = lst[iw * WARP_SIZE + ilane];
      int k = sorted[atomk].unsorted;
      xi[threadIdx.x] = sorted[atomi].x;
      yi[threadIdx.x] = sorted[atomi].y;
      zi[threadIdx.x] = sorted[atomi].z;
      xk = sorted[atomk].x;
      yk = sorted[atomk].y;
      zk = sorted[atomk].z;

      ci[threadIdx.x] = rpole[i][MPL_PME_0];
      dix[threadIdx.x] = rpole[i][MPL_PME_X];
      diy[threadIdx.x] = rpole[i][MPL_PME_Y];
      diz[threadIdx.x] = rpole[i][MPL_PME_Z];
      qixx[threadIdx.x] = rpole[i][MPL_PME_XX];
      qixy[threadIdx.x] = rpole[i][MPL_PME_XY];
      qixz[threadIdx.x] = rpole[i][MPL_PME_XZ];
      qiyy[threadIdx.x] = rpole[i][MPL_PME_YY];
      qiyz[threadIdx.x] = rpole[i][MPL_PME_YZ];
      qizz[threadIdx.x] = rpole[i][MPL_PME_ZZ];
      corei[threadIdx.x] = pcore[i];
      alphai[threadIdx.x] = palpha[i];
      vali[threadIdx.x] = pval[i];
      ck = rpole[k][MPL_PME_0];
      dkx = rpole[k][MPL_PME_X];
      dky = rpole[k][MPL_PME_Y];
      dkz = rpole[k][MPL_PME_Z];
      qkxx = rpole[k][MPL_PME_XX];
      qkxy = rpole[k][MPL_PME_XY];
      qkxz = rpole[k][MPL_PME_XZ];
      qkyy = rpole[k][MPL_PME_YY];
      qkyz = rpole[k][MPL_PME_YZ];
      qkzz = rpole[k][MPL_PME_ZZ];
      corek = pcore[k];
      alphak = palpha[k];
      valk = pval[k];

      for (int j = 0; j < WARP_SIZE; ++j) {
         int srclane = (ilane + j) & (WARP_SIZE - 1);
         int klane = srclane + threadIdx.x - ilane;
         bool incl = atomk > 0;
         real xr = xk - xi[klane];
         real yr = yk - yi[klane];
         real zr = zk - zi[klane];

         real e;
         real pota, potb;
         PairMPoleGrad pgrad;
         zero(pgrad);

         real r2 = image2(xr, yr, zr);
         if (r2 <= off * off and incl) {
            pair_mpole_chgpen<do_e, do_g, ETYP, CFLX>(r2, xr, yr, zr, 1, //
               ci[klane], dix[klane], diy[klane], diz[klane], corei[klane], vali[klane],
               alphai[klane], //
               qixx[klane], qixy[klane], qixz[klane], qiyy[klane], qiyz[klane],
               qizz[klane],                            //
               ck, dkx, dky, dkz, corek, valk, alphak, //
               qkxx, qkxy, qkxz, qkyy, qkyz, qkzz,     //
               f, aewald, e, pota, potb, pgrad);

            if CONSTEXPR (do_a)
               if (e != 0)
                  nemtl += 1;
            if CONSTEXPR (do_e)
               emtl += floatTo<ebuf_prec>(e);
            if CONSTEXPR (do_g) {
               gxi[klane] += pgrad.frcx;
               gyi[klane] += pgrad.frcy;
               gzi[klane] += pgrad.frcz;
               gxk -= pgrad.frcx;
               gyk -= pgrad.frcy;
               gzk -= pgrad.frcz;

               txi[klane] += pgrad.ttmi[0];
               tyi[klane] += pgrad.ttmi[1];
               tzi[klane] += pgrad.ttmi[2];
               txk += pgrad.ttmk[0];
               tyk += pgrad.ttmk[1];
               tzk += pgrad.ttmk[2];
            }
            if CONSTEXPR (do_v) {
               vemtlxx += floatTo<vbuf_prec>(-xr * pgrad.frcx);
               vemtlyx += floatTo<vbuf_prec>(-0.5f * (yr * pgrad.frcx + xr * pgrad.frcy));
               vemtlzx += floatTo<vbuf_prec>(-0.5f * (zr * pgrad.frcx + xr * pgrad.frcz));
               vemtlyy += floatTo<vbuf_prec>(-yr * pgrad.frcy);
               vemtlzy += floatTo<vbuf_prec>(-0.5f * (zr * pgrad.frcy + yr * pgrad.frcz));
               vemtlzz += floatTo<vbuf_prec>(-zr * pgrad.frcz);
            }
            if CONSTEXPR (CFLX) {
               poti[klane] += pota;
               potk += potb;
            }
         } // end if (include)
      }

      if CONSTEXPR (do_g) {
         atomic_add(gxi[threadIdx.x], gx, i);
         atomic_add(gyi[threadIdx.x], gy, i);
         atomic_add(gzi[threadIdx.x], gz, i);
         atomic_add(txi[threadIdx.x], trqx, i);
         atomic_add(tyi[threadIdx.x], trqy, i);
         atomic_add(tzi[threadIdx.x], trqz, i);
         if CONSTEXPR (CFLX)
            atomic_add(poti[threadIdx.x], pot, i);
         atomic_add(gxk, gx, k);
         atomic_add(gyk, gy, k);
         atomic_add(gzk, gz, k);
         atomic_add(txk, trqx, k);
         atomic_add(tyk, trqy, k);
         atomic_add(tzk, trqz, k);
         if CONSTEXPR (CFLX)
            atomic_add(potk, pot, k);
      }
   }

   if CONSTEXPR (do_a) {
      atomic_add(nemtl, nem, ithread);
   }
   if CONSTEXPR (do_e) {
      atomic_add(emtl, em, ithread);
   }
   if CONSTEXPR (do_v) {
      atomic_add(vemtlxx, vemtlyx, vemtlzx, vemtlyy, vemtlzy, vemtlzz, vem, ithread);
   }
}

template <class Ver, class ETYP, int CFLX>
static void empoleChgpen_cu()
{
   constexpr bool do_e = Ver::e;
   constexpr bool do_a = Ver::a;

   const auto& st = *mspatial_v2_unit;
   real off;
   if CONSTEXPR (eq<ETYP, EWALD>())
      off = switchOff(Switch::EWALD);
   else
      off = switchOff(Switch::MPOLE);

   const real f = electric / dielec;
   real aewald = 0;
   if CONSTEXPR (eq<ETYP, EWALD>()) {
      PMEUnit pu = epme_unit;
      aewald = pu->aewald;
      launch_k1b(g::s0, n, empoleChgpenSelf_cu<do_a, do_e, CFLX>, //
         nem, em, rpole, pot, n, f, aewald);
   }

   int ngrid = gpuGridSize(BLOCK_DIM);
   empoleChgpen_cu1<Ver, ETYP, CFLX><<<ngrid, BLOCK_DIM, 0, g::s0>>>(st.n, TINKER_IMAGE_ARGS, nem,
      em, vir_em, demx, demy, demz, off, st.si1.bit0, nmdwexclude, mdwexclude, mdwexclude_scale,
      st.x, st.y, st.z, st.sorted, st.nakpl, st.iakpl, st.niak, st.iak, st.lst, trqx, trqy, trqz,
      pot, rpole, pcore, pval, palpha, aewald, f);
}

void empoleChgpenNonEwald_cu(int vers, int use_cf)
{
   if (use_cf) {
      if (vers == calc::v0) {
         // empoleChgpen_cu<calc::V0, NON_EWALD, 1>();
         assert(false && "CFLX must compute gradient.");
      } else if (vers == calc::v1) {
         empoleChgpen_cu<calc::V1, NON_EWALD, 1>();
      } else if (vers == calc::v3) {
         // empoleChgpen_cu<calc::V3, NON_EWALD, 1>();
         assert(false && "CFLX must compute gradient.");
      } else if (vers == calc::v4) {
         empoleChgpen_cu<calc::V4, NON_EWALD, 1>();
      } else if (vers == calc::v5) {
         empoleChgpen_cu<calc::V5, NON_EWALD, 1>();
      } else if (vers == calc::v6) {
         empoleChgpen_cu<calc::V6, NON_EWALD, 1>();
      }
   } else {
      if (vers == calc::v0) {
         empoleChgpen_cu<calc::V0, NON_EWALD, 0>();
      } else if (vers == calc::v1) {
         empoleChgpen_cu<calc::V1, NON_EWALD, 0>();
      } else if (vers == calc::v3) {
         empoleChgpen_cu<calc::V3, NON_EWALD, 0>();
      } else if (vers == calc::v4) {
         empoleChgpen_cu<calc::V4, NON_EWALD, 0>();
      } else if (vers == calc::v5) {
         empoleChgpen_cu<calc::V5, NON_EWALD, 0>();
      } else if (vers == calc::v6) {
         empoleChgpen_cu<calc::V6, NON_EWALD, 0>();
      }
   }
}

void empoleChgpenEwaldRealSelf_cu(int vers, int use_cf)
{
   if (use_cf) {
      if (vers == calc::v0) {
         // empoleChgpen_cu<calc::V0, EWALD, 1>();
         assert(false && "CFLX must compute gradient.");
      } else if (vers == calc::v1) {
         empoleChgpen_cu<calc::V1, EWALD, 1>();
      } else if (vers == calc::v3) {
         // empoleChgpen_cu<calc::V3, EWALD, 1>();
         assert(false && "CFLX must compute gradient.");
      } else if (vers == calc::v4) {
         empoleChgpen_cu<calc::V4, EWALD, 1>();
      } else if (vers == calc::v5) {
         empoleChgpen_cu<calc::V5, EWALD, 1>();
      } else if (vers == calc::v6) {
         empoleChgpen_cu<calc::V6, EWALD, 1>();
      }
   } else {
      if (vers == calc::v0) {
         empoleChgpen_cu<calc::V0, EWALD, 0>();
      } else if (vers == calc::v1) {
         empoleChgpen_cu<calc::V1, EWALD, 0>();
      } else if (vers == calc::v3) {
         empoleChgpen_cu<calc::V3, EWALD, 0>();
      } else if (vers == calc::v4) {
         empoleChgpen_cu<calc::V4, EWALD, 0>();
      } else if (vers == calc::v5) {
         empoleChgpen_cu<calc::V5, EWALD, 0>();
      } else if (vers == calc::v6) {
         empoleChgpen_cu<calc::V6, EWALD, 0>();
      }
   }
}
}

namespace tinker {
__global__
void empoleEwaldRecipGenericAddVirM_cu(
   size_t size, VirialBuffer restrict vir_em, const VirialBuffer restrict vir_m)
{
   for (size_t i = ITHREAD; i < size; i += STRIDE)
      vir_em[0][i] += vir_m[0][i];
}

template <bool do_e, bool do_g, bool do_v, int CFLX>
__global__
void empoleEwaldRecipGeneric_cu1(int n, real f,                                  //
   EnergyBuffer restrict em, VirialBuffer restrict vir_em,                       //
   grad_prec* restrict demx, grad_prec* restrict demy, grad_prec* restrict demz, //
   real* restrict trqx, real* restrict trqy, real* restrict trqz,                //
   real* restrict pot,                                                           //
   const real (*restrict cmp)[10], const real (*restrict fmp)[10],               //
   const real (*restrict cphi)[10], const real (*restrict fphi)[20],             //
   int nfft1, int nfft2, int nfft3, TINKER_IMAGE_PARAMS)
{
   int ithread = ITHREAD;
   for (int i = ithread; i < n; i += STRIDE) {
      constexpr int deriv1[] = {2, 5, 8, 9, 11, 16, 18, 14, 15, 20};
      constexpr int deriv2[] = {3, 8, 6, 10, 14, 12, 19, 16, 20, 17};
      constexpr int deriv3[] = {4, 9, 10, 7, 15, 17, 13, 20, 18, 19};

      real e = 0;
      real f1 = 0;
      real f2 = 0;
      real f3 = 0;

      for (int k = 0; k < 10; ++k) {
         if CONSTEXPR (do_e)
            e += fmp[i][k] * fphi[i][k];
         if CONSTEXPR (do_g) {
            f1 += fmp[i][k] * fphi[i][deriv1[k] - 1];
            f2 += fmp[i][k] * fphi[i][deriv2[k] - 1];
            f3 += fmp[i][k] * fphi[i][deriv3[k] - 1];
         }
      } // end for (int k)

      // increment the permanent multipole energy and gradient

      if CONSTEXPR (do_e)
         atomic_add(0.5f * e * f, em, ithread);

      if CONSTEXPR (do_g) {
         f1 *= nfft1;
         f2 *= nfft2;
         f3 *= nfft3;

         real h1 = recipa.x * f1 + recipb.x * f2 + recipc.x * f3;
         real h2 = recipa.y * f1 + recipb.y * f2 + recipc.y * f3;
         real h3 = recipa.z * f1 + recipb.z * f2 + recipc.z * f3;

         atomic_add(h1 * f, demx, i);
         atomic_add(h2 * f, demy, i);
         atomic_add(h3 * f, demz, i);

         // resolve site torques then increment forces and virial

         real tem1 = cmp[i][3] * cphi[i][2] - cmp[i][2] * cphi[i][3] +
            2 * (cmp[i][6] - cmp[i][5]) * cphi[i][9] + cmp[i][8] * cphi[i][7] +
            cmp[i][9] * cphi[i][5] - cmp[i][7] * cphi[i][8] - cmp[i][9] * cphi[i][6];
         real tem2 = cmp[i][1] * cphi[i][3] - cmp[i][3] * cphi[i][1] +
            2 * (cmp[i][4] - cmp[i][6]) * cphi[i][8] + cmp[i][7] * cphi[i][9] +
            cmp[i][8] * cphi[i][6] - cmp[i][8] * cphi[i][4] - cmp[i][9] * cphi[i][7];
         real tem3 = cmp[i][2] * cphi[i][1] - cmp[i][1] * cphi[i][2] +
            2 * (cmp[i][5] - cmp[i][4]) * cphi[i][7] + cmp[i][7] * cphi[i][4] +
            cmp[i][9] * cphi[i][8] - cmp[i][7] * cphi[i][5] - cmp[i][8] * cphi[i][9];
         tem1 *= f;
         tem2 *= f;
         tem3 *= f;

         atomic_add(tem1, trqx, i);
         atomic_add(tem2, trqy, i);
         atomic_add(tem3, trqz, i);

         if CONSTEXPR (do_v) {
            real vxx = -cmp[i][1] * cphi[i][1] - 2 * cmp[i][4] * cphi[i][4] -
               cmp[i][7] * cphi[i][7] - cmp[i][8] * cphi[i][8];
            real vxy = -0.5f * (cmp[i][2] * cphi[i][1] + cmp[i][1] * cphi[i][2]) -
               (cmp[i][4] + cmp[i][5]) * cphi[i][7] - 0.5f * cmp[i][7] * (cphi[i][4] + cphi[i][5]) -
               0.5f * (cmp[i][8] * cphi[i][9] + cmp[i][9] * cphi[i][8]);
            real vxz = -0.5f * (cmp[i][3] * cphi[i][1] + cmp[i][1] * cphi[i][3]) -
               (cmp[i][4] + cmp[i][6]) * cphi[i][8] - 0.5f * cmp[i][8] * (cphi[i][4] + cphi[i][6]) -
               0.5f * (cmp[i][7] * cphi[i][9] + cmp[i][9] * cphi[i][7]);
            real vyy = -cmp[i][2] * cphi[i][2] - 2 * cmp[i][5] * cphi[i][5] -
               cmp[i][7] * cphi[i][7] - cmp[i][9] * cphi[i][9];
            real vyz = -0.5f * (cmp[i][3] * cphi[i][2] + cmp[i][2] * cphi[i][3]) -
               (cmp[i][5] + cmp[i][6]) * cphi[i][9] - 0.5f * cmp[i][9] * (cphi[i][5] + cphi[i][6]) -
               0.5f * (cmp[i][7] * cphi[i][8] + cmp[i][8] * cphi[i][7]);
            real vzz = -cmp[i][3] * cphi[i][3] - 2 * cmp[i][6] * cphi[i][6] -
               cmp[i][8] * cphi[i][8] - cmp[i][9] * cphi[i][9];
            vxx *= f;
            vxy *= f;
            vxz *= f;
            vyy *= f;
            vyz *= f;
            vzz *= f;

            atomic_add(vxx, vxy, vxz, vyy, vyz, vzz, vir_em, ithread);
         } // end if (do_v)
         if CONSTEXPR (CFLX) {
            atomic_add(f * cphi[i][0], pot, i);
         }
      } // end if (do_g)
   }
}

template <class Ver, int CFLX>
static void empoleEwaldRecipGeneric_cu()
{
   constexpr bool do_e = Ver::e;
   constexpr bool do_g = Ver::g;
   constexpr bool do_v = Ver::v;

   const PMEUnit pu = epme_unit;
   cmpToFmp(pu, cmp, fmp);
   gridMpole(pu, fmp);
   fftfront(pu);
   if CONSTEXPR (do_v) {
      if (vir_m) {
         pmeConv(pu, vir_m);
         auto size = bufferSize() * VirialBufferTraits::value;
         launch_k1s(g::s0, size, empoleEwaldRecipGenericAddVirM_cu, size, vir_em, vir_m);
      } else {
         pmeConv(pu, vir_em);
      }
   } else {
      pmeConv(pu);
   }
   fftback(pu);
   fphiMpole(pu);
   fphiToCphi(pu, fphi, cphi);

   auto& st = *pu;
   const int nfft1 = st.nfft1;
   const int nfft2 = st.nfft2;
   const int nfft3 = st.nfft3;
   const real f = electric / dielec;

   launch_k1b(g::s0, n, empoleEwaldRecipGeneric_cu1<do_e, do_g, do_v, CFLX>, //
      n, f, em, vir_em, demx, demy, demz, trqx, trqy, trqz, pot,             //
      cmp, fmp, cphi, fphi,                                                  //
      nfft1, nfft2, nfft3, TINKER_IMAGE_ARGS);
}

void empoleChgpenEwaldRecip_cu(int vers, int use_cf)
{
   if (use_cf) {
      if (vers == calc::v0)
         // empoleEwaldRecipGeneric_cu<calc::V0, 1>();
         assert(false && "CFLX must compute gradient.");
      else if (vers == calc::v1)
         empoleEwaldRecipGeneric_cu<calc::V1, 1>();
      else if (vers == calc::v3)
         // empoleEwaldRecipGeneric_cu<calc::V3, 1>();
         assert(false && "CFLX must compute gradient.");
      else if (vers == calc::v4)
         empoleEwaldRecipGeneric_cu<calc::V4, 1>();
      else if (vers == calc::v5)
         empoleEwaldRecipGeneric_cu<calc::V5, 1>();
      else if (vers == calc::v6)
         empoleEwaldRecipGeneric_cu<calc::V6, 1>();
   } else {
      if (vers == calc::v0)
         empoleEwaldRecipGeneric_cu<calc::V0, 0>();
      else if (vers == calc::v1)
         empoleEwaldRecipGeneric_cu<calc::V1, 0>();
      else if (vers == calc::v3)
         empoleEwaldRecipGeneric_cu<calc::V3, 0>();
      else if (vers == calc::v4)
         empoleEwaldRecipGeneric_cu<calc::V4, 0>();
      else if (vers == calc::v5)
         empoleEwaldRecipGeneric_cu<calc::V5, 0>();
      else if (vers == calc::v6)
         empoleEwaldRecipGeneric_cu<calc::V6, 0>();
   }
}
}
