cmake_minimum_required(VERSION 2.8)

project( robocar )

find_package( OpenCV REQUIRED )

include_directories(
	${PROJECT_SOURCE_DIR}/include
)


set(CAMERA_HEADER_FILES	include/camera.hpp)
set(CAMERA_SOURCE_FILES	include/camera.cpp)
add_library(camera ${CAMERA_SOURCE_FILES} ${CAMERA_HEADER_FILES})

add_executable( robocar robocar.cpp )
target_link_libraries(
	robocar
	camera
)

target_link_libraries( robocar ${OpenCV_LIBS} )