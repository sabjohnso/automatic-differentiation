configure_file( config.hpp.in config.hpp )

install( FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  autodiff.hpp
  derivatives.hpp
  dual.hpp
  functions.hpp
  import.hpp
  irrational.hpp
  value.hpp
  DESTINATION ${AUTODIFF_INSTALL_INCLUDE_DIR})




