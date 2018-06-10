#ifndef VALUE_HPP_INCLUDED_1195738031764322135
#define VALUE_HPP_INCLUDED_1195738031764322135 1

//
// ... AutoDiff header files
//
#include <autodiff/import.hpp>


namespace AutoDiff
{
  namespace Core
  {


    /** 
     * @brief A structure holding a single value
     *
     */
    template< typename T >
    struct Value{
      using value_type = T;
      value_type value;

      template< typename U >
      constexpr
      Value( U&& input ) :
	value( forward<U>( input ))
      {}


    private:

      constexpr
      operator value_type && () && { return move( value ); }

      constexpr
      operator const value_type& () const & { return value; }
      
    }; // end of struct Value
    
  } // end of namespace Core
} // end of namespace Autodiff

#endif // !defined VALUE_HPP_INCLUDED_1195738031764322135
