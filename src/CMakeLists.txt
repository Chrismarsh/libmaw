# Make sure the linker can find the Hello library once it is built.

find_package(Armadillo 3.0 REQUIRED)
#sym link /opt/matlab-7sp1 to the real matlab root will make this work properly
find_package(Matlab REQUIRED)



set( HEADER_FILES ${AMRADILLO_INCLUDE_DIR} ${MATLAB_INCLUDE_DIR})
set( LIB_FILES ${ARMADILLO_LIBRARIES} ${MATLAB_ENG_LIBRARY} )

include_directories(${HEADER_FILES})

add_library(maw STATIC matlab_engine.cpp graphics.cpp ${HEADER_FILES} )

target_link_libraries (maw ${LIB_FILES})