#ifndef DUAL_HPP_INCLUDED_282683657645228829
#define DUAL_HPP_INCLUDED_282683657645228829 1

//
// ... AutoDiff header files
//
#include <autodiff/derivatives.hpp>


namespace AutoDiff
{
  namespace Core
  {

    /** 
     * @brief Dual arithmetic
     */
    template< typename R, typename D >
    class Dual
      : public Arithmetic<Dual<R,D>>
      , public Comparable<Dual<R,D>>
      , public Specfunable<Dual<R,D>>
      , public Compound_assignable<Dual<R,D>>
    {
    public:
      
      using real_type = R;
      using dual_type = D;

      template< typename T, typename U >
      constexpr
      Dual( T&& real_input, U&& dual_input )
	: re( forward<T>( real_input ))
	, du( forward<U>( dual_input ))
      {}

      constexpr
      Dual( const real_type& real_input )
	: re( real_input )
	, du( 0 )
      {}

      constexpr
      Dual( const Dual& input )
	: re( input.re )
	, du( input.du )
      {}
      
      constexpr
      Dual( Dual&& input )
	: re( move( input.re ))
	, du( move( input.du ))
      {}

      Dual&
      operator =( const Dual& x ){
	re = x.re;
	du = x.du;
	return *this;
      }

      template< typename F >
      friend constexpr auto
      apply_unary( F&& f, const Dual& x ){
	return Dual(
	  f( x.re ),
	  x.du * diff( f, integer<size_t,0> )( x.re ));
      } // end of function apply_unary


      template< typename F >
      friend constexpr auto
      apply_binary( F&& f, const Dual& x, const Dual& y ){
	return Dual(
	  f( x.re, y.re ),
	  x.du*diff( f, integer<size_t,0> )( x.re, y.re ) +
	  y.du*diff( f, integer<size_t,1> )( x.re, y.re ));
      }

      friend constexpr bool
      operator <( const Dual& x, const Dual& y ){
	return x.re < y.re;
      }


      friend constexpr auto
      re( const Dual& x ){ return x.re; }

      friend constexpr auto
      du( const Dual& x ){ return x.du; }

    private:
      
      real_type re;
      dual_type du;

      template< typename Stream >
      friend Stream&
      operator <<( Stream& os, const Dual& x ){
	os << type<Dual> << '(' << x.re << ',' << x.du << ')';
	return os;
      }

      
      
    }; // end of class Dual

    
    
    template< typename Stream >
    Stream&
    operator <<( Stream& os, Type<Type1<Dual>>  ){
      os << "AutoDiff::Core::Dual";
      return os;
    }
    
    template< typename Stream >
    Stream&
    operator <<( Stream& os, Type1<Dual>  ){
      os << "AutoDiff::Core::Dual";
      return os;
    }




      
    template< typename R, typename D >
    constexpr auto
    dual( R&& re, D&& du ){
      return Dual<decay_t<R>,decay_t<D>>(
	forward<R>( re ),
	forward<D>( du ));
    }


    template< typename R >
    constexpr auto
    dual( R&& re ){
      return Dual<decay_t<R>,decay_t<R>>( forward<R>( re ), 0 );
    }
    

    
    
    
  } // end of namespace Core
} // end of namespace AutoDiff

#endif // !defined DUAL_HPP_INCLUDED_282683657645228829
