cmake_minimum_required(VERSION 2.8)

project( robocar )

find_package( OpenCV REQUIRED )

include_directories(
	${PROJECT_SOURCE_DIR}/include
)


set(CAPTURE_HEADER_FILES	include/capture/capture.hpp)
set(CAPTURE_SOURCE_FILES	include/capture/capture.cpp)
add_library(capture ${CAPTURE_SOURCE_FILES} ${CAPTURE_HEADER_FILES})

add_executable( robocar robocar.cpp )
target_link_libraries(
	robocar
	capture
)

target_link_libraries( robocar ${OpenCV_LIBS} )