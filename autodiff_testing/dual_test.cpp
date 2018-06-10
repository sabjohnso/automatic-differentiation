//
// ... AutoDiff header files
//
#include <autodiff/dual.hpp>


//
// ... Testing header files
//
#include <autodiff_testing/test_macros.hpp>



/** UNDOCUMENTED TEST */
struct Dual_test
{
  Dual_test() : accum( 0 ) {
    construction_test();
    arithmetic_test();
    specfun_test();
    comparison_test();
  }

  
  void
  construction_test(){
    using namespace AutoDiff::Core;
    AUTODIFF_STATIC_TEST( type<decltype( dual( 1.0, 2.0 ))> == type<Dual<double,double>>);
    AUTODIFF_STATIC_TEST( re( dual( 1.0, 2.0 )) == 1.0 );
    AUTODIFF_STATIC_TEST( du( dual( 1.0, 2.0 )) == 2.0 );
    AUTODIFF_STATIC_TEST( type<decltype(dual( 1.0 ))> == type<Dual<double,double>> );
    AUTODIFF_STATIC_TEST( re( dual( 1.0 )) == 1.0 );
    AUTODIFF_STATIC_TEST( du( dual( 1.0 )) == 0.0 );

    AUTODIFF_TEST( accum, type<decltype( dual( 1.0, 2.0 ))> == type<Dual<double,double>>);
    AUTODIFF_TEST( accum, re( dual( 1.0, 2.0 )) == 1.0 );
    AUTODIFF_TEST( accum, du( dual( 1.0, 2.0 )) == 2.0 );
    AUTODIFF_TEST( accum, type<decltype(dual( 1.0 ))> == type<Dual<double,double>> );
    AUTODIFF_TEST( accum, re( dual( 1.0 )) == 1.0 );
    AUTODIFF_TEST( accum, du( dual( 1.0 )) == 0.0 );
    
  }


  void
  arithmetic_test(){
    using namespace AutoDiff::Core;

    AUTODIFF_STATIC_TEST( 
      type<decltype( dual( 1.0,2.0 ) + dual( 3.0, 4.0 ))> ==
      type<Dual<double,double>> );
    
    AUTODIFF_STATIC_TEST(
      re( dual( 1.0, 2.0 ) + dual( 3.0, 4.0 )) ==
      4.0 );
    
    AUTODIFF_STATIC_TEST(
      du( dual( 1.0, 2.0 ) + dual( 3.0, 4.0 )) ==
      6.0 );


    

    AUTODIFF_STATIC_TEST(
      type<decltype(dual(1.0,2.0) - dual(3.0,4.0))> ==
      type<Dual<double,double>> );
    
    AUTODIFF_STATIC_TEST(
      re( dual( 1.0, 2.0 ) - dual( 3.0, 4.0 )) ==
      -2.0 );
    
    AUTODIFF_STATIC_TEST(
      du( dual( 1.0, 2.0 ) - dual( 3.0, 4.0 )) ==
      -2.0 );




    AUTODIFF_STATIC_TEST( 
      type<decltype( dual( 1.0,2.0 ) * dual( 3.0, 4.0 ))> ==
      type<Dual<double,double>> );
    
    AUTODIFF_STATIC_TEST(
      re( dual( 1.0, 2.0 ) * dual( 3.0, 4.0 )) ==
      3.0 );
    
    AUTODIFF_STATIC_TEST(
      du( dual( 1.0, 2.0 ) * dual( 3.0, 4.0 )) ==
      10.0 );

    AUTODIFF_STATIC_TEST( 
      type<decltype( dual( 1.0,2.0 ) / dual( 3.0, 4.0 ))> ==
      type<Dual<double,double>> );
    
    AUTODIFF_STATIC_TEST(
      re( dual( 1.0, 2.0 ) / dual( 3.0, 4.0 )) ==
      1.0/3.0 );
    
    AUTODIFF_STATIC_TEST(
      du( dual( 1.0, 2.0 ) / dual( 3.0, 4.0 )) ==
      2.0/3.0 - 4.0/(9.0));

    

  }

  void
  specfun_test(){
    using namespace AutoDiff::Core;
  }

  
  void
  comparison_test(){
    using namespace AutoDiff::Core;
    AUTODIFF_STATIC_TEST( dual( 1.0, 2.0 ) == dual( 1.0, 2.0 ));
    AUTODIFF_STATIC_TEST( !( dual( 3.0, 4.0 ) == dual( 1.0, 2.0 )));
    AUTODIFF_STATIC_TEST( !( dual( 1.0, 2.0 ) != dual( 1.0, 2.0 )));
    AUTODIFF_STATIC_TEST( dual( 3.0, 4.0 ) != dual( 1.0, 2.0 ));    
  }
  operator int() const { return accum; }
private:
  int accum;
}; // end of struct Dual_test


int
main( int, char** )
{
  int accum = 0;
  accum += Dual_test();
  return accum;
}
