#ifndef FUNCTIONS_HPP_INCLUDED_1694386481213822286
#define FUNCTIONS_HPP_INCLUDED_1694386481213822286 1

//
// ... AutoDiff header files
//
#include <autodiff/import.hpp>
#include <autodiff/value.hpp>


namespace AutoDiff
{
  namespace Core
  {

    

    template< typename T >
    class Constant : Value<T> {
    public:
      
      using value_type = T;
      using base = Value<value_type>;

      using base::base;

      template< typename ... Ts >
      constexpr const value_type &
      operator ()( Ts ... ) const& { return base::value; }

      template< typename ... Ts >
      constexpr value_type &&
      operator ()( Ts ... ) && { return move( base::value ); }

      

    }; //end of class constant


    
    


    template< typename T >
    constexpr auto
    constant( T&& x ){
      return Constant<decay_t<T>>( x );
    }






    constexpr
    class Left {
    public:
      template< typename T, typename U >
      constexpr auto
      operator ()( T&& x, U&&  ) const & { return forward<T>( x );  }
    } left{};
    

    constexpr
    class Right {
    public:
      template< typename T, typename U >
      constexpr auto
      operator ()( T&&, U&& y ) const & { return forward<U>( y ); }
    } right{};



    constexpr auto sqr = compose( multiply, dup );
    constexpr auto twc = compose( add, dup );
    constexpr auto rcp = compose( divide, 
				  pcompose( constant( 1 ),
					    identity),
				  dup );


    
    
  } // end of namespace Core
} // end of namespace AutoDiff

#endif // !defined FUNCTIONS_HPP_INCLUDED_1694386481213822286
