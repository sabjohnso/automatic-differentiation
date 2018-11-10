#ifndef IMPORT_HPP_INCLUDED_275860519703107586
#define IMPORT_HPP_INCLUDED_275860519703107586 1

//
// ... Standard header files
//
#include <cstddef>
#include <cmath>
#include <utility>
#include <type_traits>



//
// ... Other libraries
//
#include <type_utility/type_utility.hpp>
#include <operators/operators.hpp>
#include <function_utility/function_utility.hpp>




namespace AutoDiff
{
  namespace Core
  {

    using std::size_t;
    using std::integral_constant;
    using std::decay_t;
    
    using std::forward;
    using std::move;

    using TypeUtility::type;
    using TypeUtility::type_pure;
    using TypeUtility::Type;
    using TypeUtility::Type1;
    using TypeUtility::integer;

    using FunctionUtility::pcompose;
    using FunctionUtility::compose;
    using FunctionUtility::dup;
    using FunctionUtility::identity;


    using Operators::Arithmetic;
    using Operators::Specfunable;
    using Operators::Compound_assignable;
    using Operators::Comparable;

    using Operators::minus;
    using Operators::add;
    using Operators::multiply;
    using Operators::divide;
    using Operators::cosine;
    using Operators::sine;
    using Operators::tangent;
    using Operators::arccosine;
    using Operators::arcsine;
    using Operators::arctangent; 
    using Operators::hyperbolic_cosine;
    using Operators::hyperbolic_sine;
    using Operators::hyperbolic_tangent;
    using Operators::area_hyperbolic_cosine;
    using Operators::area_hyperbolic_sine;
    using Operators::area_hyperbolic_tangent;
    using Operators::logarithm;
    using Operators::logarithm10;
    using Operators::exponent;
    using Operators::square_root;
    using Operators::cube_root;
    using Operators::floor_function;
    using Operators::ceil_function;
    using Operators::power;

    using Operators::Plus;
    using Operators::Minus;
    using Operators::Addition;
    using Operators::Subtraction;
    using Operators::Multiplication;
    using Operators::Division;
    
    using Operators::Cosine;
    using Operators::Sine;
    using Operators::Tangent;
    using Operators::ArcCosine;
    using Operators::ArcSine;
    using Operators::ArcTangent;
    using Operators::HyperbolicCosine;
    using Operators::HyperbolicSine;
    using Operators::HyperbolicTangent;
    using Operators::AreaHyperbolicCosine;
    using Operators::AreaHyperbolicSine;
    using Operators::AreaHyperbolicTangent;
    using Operators::ErrorFunction;
    using Operators::ComplementaryErrorFunction;
    using Operators::GammaFunction;
    using Operators::LogGamma;
    using Operators::Exponent;
    using Operators::Logarithm;
    using Operators::Logarithm10;
    using Operators::SquareRoot;
    using Operators::CubeRoot;
    using Operators::Floor;
    using Operators::Ceil;

    using Operators::Power;
    using Operators::ArcTangent2;
    using Operators::Hypotenuse;
    using Operators::PositiveDifference;
    using Operators::Minimum;
    using Operators::Maximum;

    using Operators::FusedMultiplyAdd;


    

  } // end of namespace Core
} // end of namespace AutoDiff

#endif // !defined IMPORT_HPP_INCLUDED_275860519703107586
