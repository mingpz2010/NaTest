#ifndef _MY_UTILS_HPP_
#define _MY_UTILS_HPP_          1

#include <algorithm>

inline double my_max(double a, double b, double c)
{
    return std::max(std::max(a, b), c);
}

#endif
