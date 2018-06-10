configure_file( config.hpp.in config.h )

install( FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  autodiff.hpp
  DESTINATION ${AUTODIFF_INSTALL_INCLUDE_DIR})
