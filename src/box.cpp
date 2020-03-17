#include "box.h"
#include "darray.h"
#include "mathfunc.h"
#include "md.h"
#include "tinker_rt.h"
#include <tinker/detail/bound.hh>
#include <tinker/detail/boxes.hh>


TINKER_NAMESPACE_BEGIN
void set_default_box(const Box& p)
{
   box_shape = p.box_shape;
   lvec1 = p.lvec1;
   lvec2 = p.lvec2;
   lvec3 = p.lvec3;
   recipa = p.recipa;
   recipb = p.recipb;
   recipc = p.recipc;
}


void get_default_box(Box& p)
{
   p.box_shape = box_shape;
   p.lvec1 = lvec1;
   p.lvec2 = lvec2;
   p.lvec3 = lvec3;
   p.recipa = recipa;
   p.recipb = recipb;
   p.recipc = recipc;
}


void set_default_recip_box()
{
   if (box_shape == ORTHO_BOX) {
      recipc.x = 0;
      recipc.y = 0;
      recipc.z = 1.0 / lvec3.z;

      recipb.x = 0;
      recipb.y = 1.0 / lvec2.y;
      recipb.z = 0;

      recipa.x = 1.0 / lvec1.x;
      recipa.y = 0;
      recipa.z = 0;
   } else if (box_shape == MONO_BOX) {
      recipc.x = 0;
      recipc.y = 0;
      recipc.z = 1.0 / lvec3.z;

      recipb.x = 0;
      recipb.y = 1.0 / lvec2.y;
      recipb.z = 0;

      recipa.x = 1.0 / lvec1.x;
      recipa.y = 0;
      recipa.z = -lvec1.z / (lvec1.x * lvec3.z);
   } else if (box_shape == TRI_BOX) {
      recipc.x = 0;
      recipc.y = 0;
      recipc.z = 1.0 / lvec3.z;

      recipb.x = 0;
      recipb.y = 1.0 / lvec2.y;
      recipb.z = -lvec2.z / (lvec2.y * lvec3.z);

      recipa.x = 1.0 / lvec1.x;
      recipa.y = -lvec1.y / (lvec1.x * lvec2.y);
      recipa.z = lvec1.y * lvec2.z - lvec1.z * lvec2.y;
      recipa.z /= (lvec1.x * lvec2.y * lvec3.z);
   } else if (box_shape == OCT_BOX) {
      recipc.x = 0;
      recipc.y = 0;
      recipc.z = 1.0 / lvec1.x;

      recipb.x = 0;
      recipb.y = 1.0 / lvec1.x;
      recipb.z = 0;

      recipa.x = 1.0 / lvec1.x;
      recipa.y = 0;
      recipa.z = 0;
   }
}


void get_box_axes_angles(const Box& p, double& a, double& b, double& c,
                         double& alpha, double& beta, double& gamma)
{
   auto DOT3 = [](const double* a, const double* b) -> double {
      return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
   };


   double ax[3] = {p.lvec1.x, p.lvec2.x, p.lvec3.x};
   double bx[3] = {p.lvec1.y, p.lvec2.y, p.lvec3.y};
   double cx[3] = {p.lvec1.z, p.lvec2.z, p.lvec3.z};


   double xbox = std::sqrt(DOT3(ax, ax));
   double ybox = std::sqrt(DOT3(bx, bx));
   double zbox = std::sqrt(DOT3(cx, cx));
   double cos_a = DOT3(bx, cx) / (ybox * zbox);
   double cos_b = DOT3(cx, ax) / (zbox * xbox);
   double cos_c = DOT3(ax, bx) / (xbox * ybox);
   double a_deg = radian_dp * std::acos(cos_a);
   double b_deg = radian_dp * std::acos(cos_b);
   double c_deg = radian_dp * std::acos(cos_c);


   a = xbox;
   b = ybox;
   c = zbox;
   alpha = a_deg;
   beta = b_deg;
   gamma = c_deg;
}


void set_tinker_box_module(const Box& p)
{
   if (p.box_shape == UNBOUND_BOX)
      return;


   boxes::orthogonal = 0;
   boxes::monoclinic = 0;
   boxes::triclinic = 0;
   boxes::octahedron = 0;
   if (box_shape == ORTHO_BOX)
      boxes::orthogonal = 1;
   else if (box_shape == MONO_BOX)
      boxes::monoclinic = 1;
   else if (box_shape == TRI_BOX)
      boxes::triclinic = 1;
   else if (box_shape == OCT_BOX)
      boxes::octahedron = 1;


   double xbox, ybox, zbox, a_deg, b_deg, c_deg;
   get_box_axes_angles(p, xbox, ybox, zbox, a_deg, b_deg, c_deg);


   boxes::xbox = xbox;
   boxes::ybox = ybox;
   boxes::zbox = zbox;
   boxes::alpha = a_deg;
   boxes::beta = b_deg;
   boxes::gamma = c_deg;
   TINKER_RT(lattice)();
}


void get_tinker_box_module(Box& p)
{
   if (!bound::use_bounds) {
      p.box_shape = UNBOUND_BOX;
      p.lvec1 = make_real3(0, 0, 0);
      p.lvec2 = make_real3(0, 0, 0);
      p.lvec3 = make_real3(0, 0, 0);
      p.recipa = make_real3(0, 0, 0);
      p.recipb = make_real3(0, 0, 0);
      p.recipc = make_real3(0, 0, 0);
      return;
   }


   if (boxes::orthogonal)
      p.box_shape = ORTHO_BOX;
   else if (boxes::monoclinic)
      p.box_shape = MONO_BOX;
   else if (boxes::triclinic)
      p.box_shape = TRI_BOX;
   else if (boxes::octahedron)
      p.box_shape = OCT_BOX;


   const auto& r = boxes::recip;
   const auto& l = boxes::lvec;
   p.recipa.x = r[0][0];
   p.recipa.y = r[0][1];
   p.recipa.z = r[0][2];
   p.recipb.x = 0; // r[1][0];
   p.recipb.y = r[1][1];
   p.recipb.z = r[1][2];
   p.recipc.x = 0; // r[2][0];
   p.recipc.y = 0; // r[2][1];
   p.recipc.z = r[2][2];
   p.lvec1.x = l[0][0];
   p.lvec1.y = l[0][1];
   p.lvec1.z = l[0][2];
   p.lvec2.x = 0; // l[1][0];
   p.lvec2.y = l[1][1];
   p.lvec2.z = l[1][2];
   p.lvec3.x = 0; // l[1][1];
   p.lvec3.y = 0; // l[1][2];
   p.lvec3.z = l[2][2];
}


void box_data(rc_op op)
{
   if (op & rc_dealloc) {
      if (calc::traj & rc_flag) {
         std::free(trajbox);
      } else {
         trajbox = nullptr;
      }
      box_shape = UNBOUND_BOX;
   }


   if (op & rc_alloc) {
      if (calc::traj & rc_flag) {
         trajbox = (Box*)std::malloc(sizeof(Box) * trajn);
      }
   }


   if (op & rc_init) {
      Box p;
      get_tinker_box_module(p);
      set_default_box(p);
   }
}


real volbox()
{
   real ans = lvec1.x * lvec2.y * lvec3.z;
   if (box_shape == OCT_BOX)
      ans *= 0.5f;
   return ans;
}
TINKER_NAMESPACE_END
