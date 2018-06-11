#ifndef IRRATIONAL_HPP_INCLUDED_1894734551719302319
#define IRRATIONAL_HPP_INCLUDED_1894734551719302319 1

//
// ... AutoDiff header files
//
#include <autodiff/import.hpp>

namespace AutoDiff
{
  namespace Core
  {

    constexpr 
    struct Pi{
      template< typename T >
      constexpr
      operator T() const & { return acos( T( -1 )); }
    } pi{};


    constexpr
    struct E{
      template< typename T >
      constexpr
      operator T() const & { return exp( T( 1 )); }    
    } e{};
    
    
  } // end of namespace Core
} // end of namespace AutoDiff
#endif // !defined IRRATIONAL_HPP_INCLUDED_1894734551719302319
