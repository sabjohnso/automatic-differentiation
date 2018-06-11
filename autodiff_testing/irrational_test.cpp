//
// ... AutoDiff header files
//
#include <autodiff/irrational.hpp>


//
// ... Testing header files
//
#include <autodiff_testing/test_macros.hpp>


/** Test the irrational numbers */
struct Irrational_test
{
  Irrational_test() : accum( 0 ) {
    e_test();
    pi_test();

    }
  
  operator int() const { return accum; }
private:
  
  void
  e_test() const &{
    using namespace AutoDiff::Core;
    AUTODIFF_STATIC_TEST( double( e ) == std::exp( 1.0 ));
    AUTODIFF_STATIC_TEST( float( e ) == std::exp( 1.0f ));
  }

  void
  pi_test() const & {
    using namespace AutoDiff::Core;
    AUTODIFF_STATIC_TEST( double( pi ) == std::acos( -1.0 ));
    AUTODIFF_STATIC_TEST( float( pi ) == std::acos( -1.0f ));
  }
  
  int accum;
  
}; // end of struct Irrational_test


int
main( int, char** )
{
  int accum = 0;
  accum += Irrational_test();
  return accum;
}
