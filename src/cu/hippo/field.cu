#include "ff/amoebamod.h"
#include "ff/hippomod.h"
#include "ff/image.h"
#include "ff/pme.h"
#include "ff/spatial.h"
#include "ff/switch.h"
#include "seq/launch.h"
#include "seq/pair_field_chgpen.h"
#include "seq/triangle.h"

namespace tinker {
// ck.py Version 2.0.3
template <class ETYP>
__global__
void dfieldChgpen_cu1(int n, TINKER_IMAGE_PARAMS, real off, const unsigned* restrict dinfo,
   int nexclude, const int (*restrict exclude)[2], const real (*restrict exclude_scale)[3],
   const real* restrict x, const real* restrict y, const real* restrict z,
   const Spatial::SortedAtom* restrict sorted, int nakpl, const int* restrict iakpl, int niak,
   const int* restrict iak, const int* restrict lst, real (*restrict field)[3],
   const real (*restrict rpole)[10], const real* restrict pcore, const real* restrict pval,
   const real* restrict palpha, real aewald)
{
   const int ithread = threadIdx.x + blockIdx.x * blockDim.x;
   const int iwarp = ithread / WARP_SIZE;
   const int nwarp = blockDim.x * gridDim.x / WARP_SIZE;
   const int ilane = threadIdx.x & (WARP_SIZE - 1);

   real xi;
   real yi;
   real zi;
   real xk;
   real yk;
   real zk;
   real fidx;
   real fidy;
   real fidz;
   real fkdx;
   real fkdy;
   real fkdz;
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
      fidx = 0;
      fidy = 0;
      fidz = 0;
      fkdx = 0;
      fkdy = 0;
      fkdz = 0;

      int i = exclude[ii][0];
      int k = exclude[ii][1];
      real scaleb = exclude_scale[ii][1];

      xi = x[i];
      yi = y[i];
      zi = z[i];
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
      real xr = xk - xi;
      real yr = yk - yi;
      real zr = zk - zi;
      real r2 = image2(xr, yr, zr);
      if (r2 <= off * off and incl) {
         pair_dfield_chgpen<ETYP>(r2, xr, yr, zr, scaleb, ci[klane], dix[klane], diy[klane],
            diz[klane], corei[klane], vali[klane], alphai[klane], qixx[klane], qixy[klane],
            qixz[klane], qiyy[klane], qiyz[klane], qizz[klane], ck, dkx, dky, dkz, corek, valk,
            alphak, qkxx, qkxy, qkxz, qkyy, qkyz, qkzz, aewald, fidx, fidy, fidz, fkdx, fkdy, fkdz);
      } // end if (include)

      atomic_add(fidx, &field[i][0]);
      atomic_add(fidy, &field[i][1]);
      atomic_add(fidz, &field[i][2]);
      atomic_add(fkdx, &field[k][0]);
      atomic_add(fkdy, &field[k][1]);
      atomic_add(fkdz, &field[k][2]);
   }
   // */

   for (int iw = iwarp; iw < nakpl; iw += nwarp) {
      fidx = 0;
      fidy = 0;
      fidz = 0;
      fkdx = 0;
      fkdy = 0;
      fkdz = 0;

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

      unsigned int dinfo0 = dinfo[iw * WARP_SIZE + ilane];
      for (int j = 0; j < WARP_SIZE; ++j) {
         int srclane = (ilane + j) & (WARP_SIZE - 1);
         int klane = srclane + threadIdx.x - ilane;
         bool incl = iid < kid and kid < n;
         int srcmask = 1 << srclane;
         incl = incl and (dinfo0 & srcmask) == 0;
         real scaleb = 1;
         real xr = xk - xi;
         real yr = yk - yi;
         real zr = zk - zi;
         real r2 = image2(xr, yr, zr);
         if (r2 <= off * off and incl) {
            pair_dfield_chgpen<ETYP>(r2, xr, yr, zr, scaleb, ci[klane], dix[klane], diy[klane],
               diz[klane], corei[klane], vali[klane], alphai[klane], qixx[klane], qixy[klane],
               qixz[klane], qiyy[klane], qiyz[klane], qizz[klane], ck, dkx, dky, dkz, corek, valk,
               alphak, qkxx, qkxy, qkxz, qkyy, qkyz, qkzz, aewald, fidx, fidy, fidz, fkdx, fkdy,
               fkdz);
         } // end if (include)

         iid = __shfl_sync(ALL_LANES, iid, ilane + 1);
         xi = __shfl_sync(ALL_LANES, xi, ilane + 1);
         yi = __shfl_sync(ALL_LANES, yi, ilane + 1);
         zi = __shfl_sync(ALL_LANES, zi, ilane + 1);
         fidx = __shfl_sync(ALL_LANES, fidx, ilane + 1);
         fidy = __shfl_sync(ALL_LANES, fidy, ilane + 1);
         fidz = __shfl_sync(ALL_LANES, fidz, ilane + 1);
      }

      atomic_add(fidx, &field[i][0]);
      atomic_add(fidy, &field[i][1]);
      atomic_add(fidz, &field[i][2]);
      atomic_add(fkdx, &field[k][0]);
      atomic_add(fkdy, &field[k][1]);
      atomic_add(fkdz, &field[k][2]);
   }

   for (int iw = iwarp; iw < niak; iw += nwarp) {
      fidx = 0;
      fidy = 0;
      fidz = 0;
      fkdx = 0;
      fkdy = 0;
      fkdz = 0;

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
         real scaleb = 1;
         real xr = xk - xi;
         real yr = yk - yi;
         real zr = zk - zi;
         real r2 = image2(xr, yr, zr);
         if (r2 <= off * off and incl) {
            pair_dfield_chgpen<ETYP>(r2, xr, yr, zr, scaleb, ci[klane], dix[klane], diy[klane],
               diz[klane], corei[klane], vali[klane], alphai[klane], qixx[klane], qixy[klane],
               qixz[klane], qiyy[klane], qiyz[klane], qizz[klane], ck, dkx, dky, dkz, corek, valk,
               alphak, qkxx, qkxy, qkxz, qkyy, qkyz, qkzz, aewald, fidx, fidy, fidz, fkdx, fkdy,
               fkdz);
         } // end if (include)

         xi = __shfl_sync(ALL_LANES, xi, ilane + 1);
         yi = __shfl_sync(ALL_LANES, yi, ilane + 1);
         zi = __shfl_sync(ALL_LANES, zi, ilane + 1);
         fidx = __shfl_sync(ALL_LANES, fidx, ilane + 1);
         fidy = __shfl_sync(ALL_LANES, fidy, ilane + 1);
         fidz = __shfl_sync(ALL_LANES, fidz, ilane + 1);
      }

      atomic_add(fidx, &field[i][0]);
      atomic_add(fidy, &field[i][1]);
      atomic_add(fidz, &field[i][2]);
      atomic_add(fkdx, &field[k][0]);
      atomic_add(fkdy, &field[k][1]);
      atomic_add(fkdz, &field[k][2]);
   }
}

template <class ETYP>
static void dfieldChgpen_cu(real (*field)[3])
{
   const auto& st = *mspatial_v2_unit;
   real off;

   if CONSTEXPR (eq<ETYP, EWALD>())
      off = switchOff(Switch::EWALD);
   else
      off = switchOff(Switch::MPOLE);

   real aewald = 0;
   if CONSTEXPR (eq<ETYP, EWALD>()) {
      PMEUnit pu = ppme_unit;
      aewald = pu->aewald;
   }

   int ngrid = gpuGridSize(BLOCK_DIM);
   dfieldChgpen_cu1<ETYP><<<ngrid, BLOCK_DIM, 0, g::s0>>>(st.n, TINKER_IMAGE_ARGS, off, st.si1.bit0,
      nmdwexclude, mdwexclude, mdwexclude_scale, st.x, st.y, st.z, st.sorted, st.nakpl, st.iakpl,
      st.niak, st.iak, st.lst, field, rpole, pcore, pval, palpha, aewald);
}

void dfieldChgpenEwaldReal_cu(real (*field)[3])
{
   dfieldChgpen_cu<EWALD>(field);
}
void dfieldChgpenNonEwald_cu(real (*field)[3])
{
   darray::zero(g::q0, n, field);

   dfieldChgpen_cu<NON_EWALD>(field);
}

// ck.py Version 2.0.3
template <class ETYP>
__global__
void ufieldChgpen_cu1(int n, TINKER_IMAGE_PARAMS, real off, const unsigned* restrict winfo,
   int nexclude, const int (*restrict exclude)[2], const real (*restrict exclude_scale)[3],
   const real* restrict x, const real* restrict y, const real* restrict z,
   const Spatial::SortedAtom* restrict sorted, int nakpl, const int* restrict iakpl, int niak,
   const int* restrict iak, const int* restrict lst, const real (*restrict uind)[3],
   real (*restrict field)[3], const real* restrict pcore, const real* restrict pval,
   const real* restrict palpha, real aewald)
{
   const int ithread = threadIdx.x + blockIdx.x * blockDim.x;
   const int iwarp = ithread / WARP_SIZE;
   const int nwarp = blockDim.x * gridDim.x / WARP_SIZE;
   const int ilane = threadIdx.x & (WARP_SIZE - 1);

   real xi;
   real yi;
   real zi;
   real xk;
   real yk;
   real zk;
   real fidx;
   real fidy;
   real fidz;
   real fkdx;
   real fkdy;
   real fkdz;
   __shared__ real uidx[BLOCK_DIM];
   __shared__ real uidy[BLOCK_DIM];
   __shared__ real uidz[BLOCK_DIM];
   __shared__ real corei[BLOCK_DIM];
   __shared__ real alphai[BLOCK_DIM];
   __shared__ real vali[BLOCK_DIM];
   real ukdx;
   real ukdy;
   real ukdz;
   real corek;
   real alphak;
   real valk;

   //* /
   for (int ii = ithread; ii < nexclude; ii += blockDim.x * gridDim.x) {
      const int klane = threadIdx.x;
      fidx = 0;
      fidy = 0;
      fidz = 0;
      fkdx = 0;
      fkdy = 0;
      fkdz = 0;

      int i = exclude[ii][0];
      int k = exclude[ii][1];
      real scalec = exclude_scale[ii][2];

      xi = x[i];
      yi = y[i];
      zi = z[i];
      xk = x[k];
      yk = y[k];
      zk = z[k];
      uidx[klane] = uind[i][0];
      uidy[klane] = uind[i][1];
      uidz[klane] = uind[i][2];
      corei[klane] = pcore[i];
      alphai[klane] = palpha[i];
      vali[klane] = pval[i];
      ukdx = uind[k][0];
      ukdy = uind[k][1];
      ukdz = uind[k][2];
      corek = pcore[k];
      alphak = palpha[k];
      valk = pval[k];

      constexpr bool incl = true;
      real xr = xk - xi;
      real yr = yk - yi;
      real zr = zk - zi;
      real r2 = image2(xr, yr, zr);
      if (r2 <= off * off and incl) {
         pair_ufield_chgpen<ETYP>(r2, xr, yr, zr, scalec, uidx[klane], uidy[klane], uidz[klane],
            corei[klane], vali[klane], alphai[klane], ukdx, ukdy, ukdz, corek, valk, alphak, aewald,
            fidx, fidy, fidz, fkdx, fkdy, fkdz);
      } // end if (include)

      atomic_add(fidx, &field[i][0]);
      atomic_add(fidy, &field[i][1]);
      atomic_add(fidz, &field[i][2]);
      atomic_add(fkdx, &field[k][0]);
      atomic_add(fkdy, &field[k][1]);
      atomic_add(fkdz, &field[k][2]);
   }
   // */

   for (int iw = iwarp; iw < nakpl; iw += nwarp) {
      fidx = 0;
      fidy = 0;
      fidz = 0;
      fkdx = 0;
      fkdy = 0;
      fkdz = 0;

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

      uidx[threadIdx.x] = uind[i][0];
      uidy[threadIdx.x] = uind[i][1];
      uidz[threadIdx.x] = uind[i][2];
      corei[threadIdx.x] = pcore[i];
      alphai[threadIdx.x] = palpha[i];
      vali[threadIdx.x] = pval[i];
      ukdx = uind[k][0];
      ukdy = uind[k][1];
      ukdz = uind[k][2];
      corek = pcore[k];
      alphak = palpha[k];
      valk = pval[k];

      unsigned int winfo0 = winfo[iw * WARP_SIZE + ilane];
      for (int j = 0; j < WARP_SIZE; ++j) {
         int srclane = (ilane + j) & (WARP_SIZE - 1);
         int klane = srclane + threadIdx.x - ilane;
         bool incl = iid < kid and kid < n;
         int srcmask = 1 << srclane;
         incl = incl and (winfo0 & srcmask) == 0;
         real scalec = 1;
         real xr = xk - xi;
         real yr = yk - yi;
         real zr = zk - zi;
         real r2 = image2(xr, yr, zr);
         if (r2 <= off * off and incl) {
            pair_ufield_chgpen<ETYP>(r2, xr, yr, zr, scalec, uidx[klane], uidy[klane], uidz[klane],
               corei[klane], vali[klane], alphai[klane], ukdx, ukdy, ukdz, corek, valk, alphak,
               aewald, fidx, fidy, fidz, fkdx, fkdy, fkdz);
         } // end if (include)

         iid = __shfl_sync(ALL_LANES, iid, ilane + 1);
         xi = __shfl_sync(ALL_LANES, xi, ilane + 1);
         yi = __shfl_sync(ALL_LANES, yi, ilane + 1);
         zi = __shfl_sync(ALL_LANES, zi, ilane + 1);
         fidx = __shfl_sync(ALL_LANES, fidx, ilane + 1);
         fidy = __shfl_sync(ALL_LANES, fidy, ilane + 1);
         fidz = __shfl_sync(ALL_LANES, fidz, ilane + 1);
      }

      atomic_add(fidx, &field[i][0]);
      atomic_add(fidy, &field[i][1]);
      atomic_add(fidz, &field[i][2]);
      atomic_add(fkdx, &field[k][0]);
      atomic_add(fkdy, &field[k][1]);
      atomic_add(fkdz, &field[k][2]);
   }

   for (int iw = iwarp; iw < niak; iw += nwarp) {
      fidx = 0;
      fidy = 0;
      fidz = 0;
      fkdx = 0;
      fkdy = 0;
      fkdz = 0;

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

      uidx[threadIdx.x] = uind[i][0];
      uidy[threadIdx.x] = uind[i][1];
      uidz[threadIdx.x] = uind[i][2];
      corei[threadIdx.x] = pcore[i];
      alphai[threadIdx.x] = palpha[i];
      vali[threadIdx.x] = pval[i];
      ukdx = uind[k][0];
      ukdy = uind[k][1];
      ukdz = uind[k][2];
      corek = pcore[k];
      alphak = palpha[k];
      valk = pval[k];

      for (int j = 0; j < WARP_SIZE; ++j) {
         int srclane = (ilane + j) & (WARP_SIZE - 1);
         int klane = srclane + threadIdx.x - ilane;
         bool incl = atomk > 0;
         real scalec = 1;
         real xr = xk - xi;
         real yr = yk - yi;
         real zr = zk - zi;
         real r2 = image2(xr, yr, zr);
         if (r2 <= off * off and incl) {
            pair_ufield_chgpen<ETYP>(r2, xr, yr, zr, scalec, uidx[klane], uidy[klane], uidz[klane],
               corei[klane], vali[klane], alphai[klane], ukdx, ukdy, ukdz, corek, valk, alphak,
               aewald, fidx, fidy, fidz, fkdx, fkdy, fkdz);
         } // end if (include)

         xi = __shfl_sync(ALL_LANES, xi, ilane + 1);
         yi = __shfl_sync(ALL_LANES, yi, ilane + 1);
         zi = __shfl_sync(ALL_LANES, zi, ilane + 1);
         fidx = __shfl_sync(ALL_LANES, fidx, ilane + 1);
         fidy = __shfl_sync(ALL_LANES, fidy, ilane + 1);
         fidz = __shfl_sync(ALL_LANES, fidz, ilane + 1);
      }

      atomic_add(fidx, &field[i][0]);
      atomic_add(fidy, &field[i][1]);
      atomic_add(fidz, &field[i][2]);
      atomic_add(fkdx, &field[k][0]);
      atomic_add(fkdy, &field[k][1]);
      atomic_add(fkdz, &field[k][2]);
   }
}

template <class ETYP>
static void ufieldChgpen_cu(const real (*uind)[3], real (*field)[3])
{

   const auto& st = *mspatial_v2_unit;
   real off;

   if CONSTEXPR (eq<ETYP, EWALD>())
      off = switchOff(Switch::EWALD);
   else
      off = switchOff(Switch::MPOLE);

   real aewald = 0;
   if CONSTEXPR (eq<ETYP, EWALD>()) {
      PMEUnit pu = ppme_unit;
      aewald = pu->aewald;
   }

   int ngrid = gpuGridSize(BLOCK_DIM);
   ufieldChgpen_cu1<ETYP><<<ngrid, BLOCK_DIM, 0, g::s0>>>(st.n, TINKER_IMAGE_ARGS, off, st.si1.bit0,
      nmdwexclude, mdwexclude, mdwexclude_scale, st.x, st.y, st.z, st.sorted, st.nakpl, st.iakpl,
      st.niak, st.iak, st.lst, uind, field, pcore, pval, palpha, aewald);
}

void ufieldChgpenEwaldReal_cu(const real (*uind)[3], real (*field)[3])
{
   ufieldChgpen_cu<EWALD>(uind, field);
}

void ufieldChgpenNonEwald_cu(const real (*uind)[3], real (*field)[3])
{
   darray::zero(g::q0, n, field);
   ufieldChgpen_cu<NON_EWALD>(uind, field);
}
}
