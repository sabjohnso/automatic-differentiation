macro( autodiff_add_simple_test  name )
  add_executable( ${name}_test ${name}_test.cpp )
  add_test( ${name} ${name}_test ) 
endmacro( autodiff_add_simple_test  name )

autodiff_add_simple_test( dual )
autodiff_add_simple_test( irrational )


