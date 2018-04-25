cmake_minimum_required( VERSION 2.8 )
project( salt_noise )

set( CMAKE_CXX_FLAGS "-std=c++11" )
set( CMAKE_BUILD_TYPE "Release" )
set(OpenCV_DIR "/usr/local/share/OpenCV")

find_package( OpenCV 3.1 REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( salt_noise salt_noise.cpp )
target_link_libraries( salt_noise ${OpenCV_LIBS} )
