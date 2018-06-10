#
# ... Build script for autodiff
#

cmake_minimum_required( VERSION 3.7 )

project( AUTODIFF )
set( AUTODIFF_MAJOR 0)
set( AUTODIFF_MINOR 1)
set( AUTODIFF_UPDATE 0)
set( AUTODIFF_VERSION autodiff-${AUTODIFF_MAJOR}.${AUTODIFF_MINOR} )
set( AUTODIFF_VERSION_UPDATE ${AUTODIFF_VERSION}.${AUTODIFF_UPDATE} )

option( BUILD_AUTODIFF_TESTING  "Build the autodiff  tests" ON )
option( BUILD_AUTODIFF_DOCUMENTATION "Build the autodiff documentation" ON )

include_directories( 
  ${AUTODIFF_SOURCE_DIR}
  ${AUTODIFF_BINARY_DIR} )

if( NOT AUTODIFF_INSTALL_INCLUDE_DIR)
  set( AUTODIFF_INSTALL_INCLUDE_DIR include/autodiff
    CACHE PATH "Path for installation of header files" )
endif( NOT AUTODIFF_INSTALL_INCLUDE_DIR)

add_subdirectory( autodiff )



#
# ... Testing #
if( BUILD_AUTODIFF_TESTING )
  enable_testing()
  add_subdirectory( autodiff_testing )
endif( BUILD_AUTODIFF_TESTING )



#
# ... Documentation
#
if( BUILD_AUTODIFF_DOCUMENTATION )

  configure_file( Doxyfile.in Doxyfile )

  if( NOT AUTODIFF_INSTALL_DOC_DIR)
    set( AUTODIFF_INSTALL_DOC_DIR share/doc/${AUTODIFF_VERSION}
      CACHE PATH "Path for installation of documentation files" )
  endif( NOT AUTODIFF_INSTALL_DOC_DIR)

  if( NOT AUTODIFF_INTALL_MAN_DIR)
    set( AUTODIFF_INTALL_MAN_DIR include/autodiff
      CACHE PATH "Path for installation of man files" )
  endif( NOT AUTODIFF_INTALL_MAN_DIR)

  find_package( Doxygen REQUIRED )

  add_custom_command(
    OUTPUT ${AUTODIFF_BINARY_DIR}/doxygen.log
    COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile > doxygen.log
    MAIN_DEPENDENCY Doxyfile
    DEPENDS ${AUTODIFF_SOURCE_DIR}/autodiff
    WORKING_DIRECTORY ${${AUTODIFF_BINARY_DIR}} )

  add_custom_target(
    autodiff_documentation ALL
    DEPENDS ${AUTODIFF_BINARY_DIR}/doxygen.log )

  install( DIRECTORY ${AUTODIFF_BINARY_DIR}/doc/html DESTINATION ${AUTODIFF_INSTALL_DOC_DIR} )
  install( DIRECTORY ${AUTODIFF_BINARY_DIR}/doc/man DESTINATION ${AUTODIFF_INTALL_MAN_DIR} )
endif( BUILD_AUTODIFF_DOCUMENTATION )



# end of build definition for autodiff
