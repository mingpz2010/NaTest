#ifndef _MY_PHYSICS_CONSTANTS_H_
#define _MY_PHYSICS_CONSTANTS_H_            1

#if defined(__cplusplus) && (__cplusplus >= 201103L)

const double GOLDEN_RATIO       = 1.618033988749895;
const double SPEED_OF_LIGHT     = 299792458.0;
const double PLANCK_CONSTANT    = 6.62607015E-34;
const double BOLTZMANN_CONSTANT = 1.380658E-23;
const double GRAVITY_CONSTANT   = 9.80665;
const double AVOGADRO_CONSTANT  = 6.02214076E+23;
const double ELECTRON_MASS      = 9.1093837015E-31;
const double PROTON_MASS        = 1.67262192369E-27;
const double NEUTRON_MASS       = 1.67492749804E-27;
const double ATOMIC_MASS        = 1.6605390666E-27;

#else

#define GOLDEN_RATIO                (1.618033988749895d)
#define SPEED_OF_LIGHT              (299792458.0d)
#define PLANCK_CONSTANT             ((6.62607015E-34)d)
#define BOLTZMANN_CONSTANT          ((1.380658E-23)d)
#define GRAVITY_CONSTANT            (9.80665d)
#define AVOGADRO_CONSTANT           ((6.02214076E+23)d)
#define ELECTRON_MASS               ((9.1093837015E-31)d)
#define PROTON_MASS                 ((1.67262192369E-27)d)
#define NEUTRON_MASS                ((1.67492749804E-27)d)
#define ATOMIC_MASS                 ((1.6605390666E-27)d)

#endif

#endif

