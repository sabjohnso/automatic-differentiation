#ifndef DERIVATIVES_HPP_INCLUDED_1336452949977298507
#define DERIVATIVES_HPP_INCLUDED_1336452949977298507 1

//
// ... AutoDiff header files
//
#include <autodiff/import.hpp>
#include <autodiff/functions.hpp>


namespace AutoDiff
{
  namespace Core
  {

    template< typename T, size_t index >
    constexpr auto
    diff( Constant<T>, integral_constant<size_t,index> ){
      return constant( 0 );
    }
    

    constexpr auto
    diff( Plus, integral_constant<size_t,0> ){
      return constant( 1 );
    }

    constexpr auto
    diff( Minus, integral_constant<size_t,0> ){
      return constant( -1 );
    }

    
    constexpr auto
    diff( Addition, integral_constant<size_t, 0> ){
      return constant( 1 );
    }

    constexpr auto
    diff( Addition, integral_constant<size_t, 1> ){
      return constant( 1 );
    }

    constexpr auto
    diff( Subtraction, integral_constant<size_t,0> ){
      return constant( 1 );
    }

    constexpr auto
    diff( Subtraction, integral_constant<size_t,1> ){
      return constant( -1 );
    }

    constexpr auto
    diff( Multiplication, integral_constant< size_t,0> ){
      return right;
    }

    constexpr auto
    diff( Multiplication, integral_constant<size_t,1> ){
      return left;
    }

    constexpr auto
    diff( Division, integral_constant<size_t,0> ){
      return []( auto, auto y ){ return 1/y; };
    }

    constexpr auto
    diff( Division, integral_constant<size_t,1> ){
      return []( auto& x, auto& y ){ return -x/(y*y); };
    }


    constexpr auto
    diff( Cosine, integral_constant<size_t, 0 > ){ return compose( minus, sine ); }

    constexpr auto
    diff( Sine, integral_constant<size_t, 0> ){ return cosine; }
    



    
    
    
  } // end of namespace Core
} // end of namespace AutoDiff

#endif // !defined DERIVATIVES_HPP_INCLUDED_1336452949977298507
