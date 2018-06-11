
#ifndef DERIVATIVES_HPP_INCLUDED_1336452949977298507
#define DERIVATIVES_HPP_INCLUDED_1336452949977298507 1

//
// ... AutoDiff header files
//
#include <autodiff/import.hpp>
#include <autodiff/functions.hpp>
#include <autodiff/irrational.hpp>


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
      return compose( divide, pcompose( minus, sqr ));
    }


    constexpr auto
    diff( Cosine, integral_constant<size_t, 0> ){ return compose( minus, sine ); }

    constexpr auto
    diff( Sine, integral_constant<size_t, 0> ){ return cosine; }

    constexpr auto
    diff( Tangent, integral_constant<size_t, 0> ){
      return compose( add, pcompose( compose( sqr, tangent ),
				     constant( 1 )),
		      dup);
    }

    constexpr auto
    diff( ArcCosine, integral_constant<size_t,0> ){
      return []( auto&& x ){ return -rcp( sqrt( 1 - sqr( x ))); };
    }

    constexpr auto
    diff( ArcSine, integral_constant<size_t,0> ){
      return []( auto&& x ){ return rcp( sqrt( 1.0-sqr( x ))); };
    }

    constexpr auto
    diff( ArcTangent, integral_constant<size_t,0> ){
      return []( auto&& x ){ return rcp( sqr(x ) + 1 ); };
    }


    constexpr auto
    diff( HyperbolicCosine, integral_constant<size_t,0> ){
      return hyperbolic_sine;
    }

    constexpr auto
    diff( HyperbolicSine, integral_constant<size_t,0> ){
      return hyperbolic_cosine;
    }

    constexpr auto
    diff( HyperbolicTangent, integral_constant<size_t,0> ){
      return []( auto&& x ){ return 1-sqr(tanh( x )); };
    }

    constexpr auto
    diff( AreaHyperbolicCosine, integral_constant<size_t,0> ){
      return []( auto&& x ){ return rcp( sqrt( sqr( x ) - 1 )); };
    }

    constexpr auto
    diff( AreaHyperbolicSine, integral_constant<size_t,0> ){
      return []( auto&& x ){ return rcp( sqrt( sqr( x ) + 1 )); };
    }

    constexpr auto
    diff( AreaHyperbolicTangent, integral_constant<size_t,0> ){
      return []( auto&& x ){ return rcp( 1 - sqr( x )); };
    }


    constexpr auto
    diff( SquareRoot, integral_constant<size_t,0> ){
      return []( auto&& x ){ return rcp( 2*sqrt( x )); };
    }

    constexpr auto
    diff( CubeRoot, integral_constant<size_t,0> ){
      return []( auto&& x ){ return rcp( 3*sqr( cbrt( x ))); };
    }

    constexpr auto
    diff( Logarithm, integral_constant<size_t,0> ){
      return rcp;
    }

    constexpr auto
    diff( Logarithm10, integral_constant<size_t,0> ){
      return []( auto&& x ){ return diff( logarithm, integer<size_t,0>)( x )/log(10); };
    }

    constexpr auto
    diff( ErrorFunction, integral_constant<size_t,0> ){
      return []( auto&& x ){ return 2*exp( - sqr( x ))/sqrt( pi ); };
    }

    constexpr auto
    diff( ComplementaryErrorFunction, integral_constant<size_t,0> ){
      return []( auto&& x ){ return -2*exp( - sqr( x ))/sqrt( pi ); };
    }



    constexpr auto
    diff( Floor, integral_constant<size_t,0> ){
      return constant( 1 );
    }

    constexpr auto
    diff( Ceil, integral_constant<size_t, 0> ){
      return constant( 1 );
    }
    

    constexpr auto
    diff( Power, integral_constant<size_t,0> ){
      return []( auto&& x, auto&& y ){ return y*power( x, y-1 ); };
    }

    constexpr auto
    diff( Power, integral_constant<size_t,1> ){
      return []( auto&& x, auto&& y ){ return logarithm( x )*power( x, y ); };
    }

    constexpr auto
    diff( Hypotenuse, integral_constant<size_t,0> ){
      return []( auto&& x, auto&& y ){ return 2*x; };
    }

    constexpr auto
    diff( Hypotenuse, integral_constant<size_t,1> ){
      return []( auto&& x, auto&& y ){ return 2*y ; };
    }

    constexpr auto
    diff( PositiveDifference, integral_constant<size_t,0> ){
      return []( auto&& x, auto&& y ){ return x > y ? 1 : 0; };
    }

    constexpr auto
    diff( PositiveDifference, integral_constant<size_t,1> ){
      return []( auto&& x, auto&& y ){ return x > y ? -1 : 0; };
    }


    constexpr auto
    diff( Maximum, integral_constant<size_t,0> ){
      return []( auto&& x, auto&& y ){ return x >= y ? 1 : 0; };
    }

    constexpr auto
    diff( Maximum, integral_constant<size_t,1> ){
      return []( auto&& x, auto&& y ){ return x < y ? 1 : 0; };
    }

    constexpr auto
    diff( Minimum, integral_constant<size_t,0> ){
      return []( auto&& x, auto&& y ){ return x < y ? 1 : 0; };
    }

    constexpr auto
    diff( Minimum, integral_constant<size_t,1> ){
      return []( auto&& x, auto&& y ){ return x > y ? 1 : 0; };
    }

    

    
  } // end of namespace Core
} // end of namespace AutoDiff

#endif // !defined DERIVATIVES_HPP_INCLUDED_1336452949977298507
