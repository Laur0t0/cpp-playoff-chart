#ifndef DOCTEST_INCLUDED
#define DOCTEST_INCLUDED

#include <sstream>
#include <vector>
#include <iterator>

#include "doctest.h"
namespace doctest {

template <typename T>
struct StringMaker<std::vector<T>> {
  static String convert(const std::vector<T>& vec) {
    std::ostringstream oss;
    oss << "[ ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(oss, " "));
    oss << "]";
    return oss.str().c_str();
  }
};

}  // namespace doctest

#endif
