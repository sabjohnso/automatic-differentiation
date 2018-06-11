//
// ... Standard header files
//
#include <cmath>

//
// ... AutoDiff header files
//
#include <autodiff/dual.hpp>


//
// ... Testing header files
//
#include <autodiff_testing/test_macros.hpp>


template< typename F, typename T >
class DerivativeTester
{
public:
  using function_type = F;
  using value_type = T;

  
  constexpr
  DerivativeTester(
    function_type  input_function,
    value_type lower_bound,
    value_type upper_bound,
    value_type difference_step,
    value_type tolerance,
    size_t sample_count )
    : fun( input_function )
    , a( lower_bound )
    , b( upper_bound )
    , h( difference_step )
    , tol( tolerance )
    , n( sample_count )
  {}

  void run( int& accum ) const {
    using namespace AutoDiff::Core;
    value_type dx = (b-a)/n;
    value_type scale = find_scale( dx );
    for( size_t i = 0; i < n; ++i ){
      value_type x = a+dx*i+dx/2;
      value_type xm = x-h/2;
      value_type xp = x+h/2;

      value_type yprime_fdiff = (fun( xp )-fun( xm ))/h;
      Dual<value_type,value_type> ydual = fun( dual( x, value_type( 1 )));

      AUTODIFF_TEST( accum, std::fabs( yprime_fdiff - du( ydual ))/scale < tol );
      
    }
  }

  void run_verbose( int& accum ) const {
    using namespace AutoDiff::Core;
    value_type dx = (b-a)/n;
    value_type scale = find_scale( dx );
    for( size_t i = 0; i < n; ++i ){
      value_type x = a+dx*i+dx/2;
      value_type xm = x-h/2;
      value_type xp = x+h/2;


      

      value_type yprime_fdiff = (fun( xp )-fun( xm ))/h;
      Dual<value_type,value_type> ydual = fun( dual( x, value_type( 1 )));

      std::cout << std::endl;
      std::cout << "x: " << x << std::endl;
      std::cout << "yprime (FD): " << yprime_fdiff << std::endl;
      std::cout << "yprime (AD): " << du( ydual ) << std::endl;
      std::cout << "yprime (AD): " << du( ydual ) << std::endl;
      std::cout << "error (rel): " 
		<< std::fabs( yprime_fdiff - du( ydual ))/scale
		<< std::endl;
      std::cout << "error (abs): "
		<< std::fabs( yprime_fdiff - du( ydual ))
		<< std::endl;
      std::cout << "tol: " << tol << std::endl;
      std::cout << std::endl;
      AUTODIFF_TEST( accum,  std::fabs((yprime_fdiff - du( ydual ))/scale) < tol );
      
    }
  }

  value_type
  find_scale( value_type dx ) const & {
    value_type result = 0;
    for( size_t i = 0; i < n; ++i ){
      value_type x = a+dx*(i+0.5);
      value_type y = std::fabs( fun( x ));
      if( y > result ){
	result = y;
      }
    }
    return result;
  }

private:
  function_type fun;
  value_type a;
  value_type b;
  value_type h;
  value_type tol;
  size_t n;
};


template< typename F, typename T >
constexpr auto
derivative_tester( F f, T a, T b, T h, T tol, size_t n ){
  return DerivativeTester<F,T>( f, a, b, h, tol, n );
} 




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

    derivative_tester( cosine, 0.0, 2.0*double( pi ), 1.0e-08, 1.0e-6, 100 ).run( accum );
    derivative_tester( sine, 0.0, 2.0*double( pi ), 1.0e-08, 1.0e-6, 100 ).run( accum );
    derivative_tester( tangent, 0.0, double( pi )/2.0, 1.0e-08, 1.0e-6, 100 ).run( accum );
    derivative_tester( sqr, 0.0, 1.0, 1.0e-08, 1.0e-6, 100 ).run( accum );
    derivative_tester( rcp, 0.1, 1.0, 1.0e-08, 1.0e-6, 100 ).run( accum );
    derivative_tester( arccosine, -1.0, 1.0, 1.0e-8, 1.0e-6, 100 ).run( accum );
    derivative_tester( arcsine, -1.0, 1.0, 1.0e-8, 1.0e-6, 100 ).run( accum );
    derivative_tester( arctangent, -100.0, 100.0, 1.0e-5, 1.0e-6, 100 ).run( accum );
    derivative_tester( hyperbolic_cosine, -1.0, 1.0, 1.0e-5, 1.0e-6, 100 ).run_verbose( accum );
    derivative_tester( hyperbolic_sine, -1.0, 1.0, 1.0e-5, 1.0e-6, 100 ).run( accum );
    derivative_tester( hyperbolic_tangent, -1.0, 1.0, 1.0e-5, 1.0e-6, 100 ).run( accum );
    derivative_tester( area_hyperbolic_cosine, 1.0, 2.0, 1.0e-5, 1.0e-6, 100 ).run( accum );
    derivative_tester( area_hyperbolic_sine, -1.0, 1.0, 1.0e-5, 1.0e-6, 100 ).run( accum );
    derivative_tester( area_hyperbolic_tangent, -0.5, 0.5, 1.0e-5, 1.0e-6, 100 ).run( accum );
    derivative_tester( square_root, 0.1, 1.0, 1.0e-5, 1.0e-6, 100 ).run( accum );
    derivative_tester( cube_root, 0.1, 1.0, 1.0e-5, 1.0e-6, 100 ).run( accum );

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
