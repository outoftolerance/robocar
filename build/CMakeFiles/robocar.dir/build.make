# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/james/Documents/robocar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/james/Documents/robocar/build

# Include any dependencies generated for this target.
include CMakeFiles/robocar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/robocar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/robocar.dir/flags.make

CMakeFiles/robocar.dir/robocar.cpp.o: CMakeFiles/robocar.dir/flags.make
CMakeFiles/robocar.dir/robocar.cpp.o: ../robocar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/james/Documents/robocar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/robocar.dir/robocar.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/robocar.dir/robocar.cpp.o -c /home/james/Documents/robocar/robocar.cpp

CMakeFiles/robocar.dir/robocar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/robocar.dir/robocar.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/Documents/robocar/robocar.cpp > CMakeFiles/robocar.dir/robocar.cpp.i

CMakeFiles/robocar.dir/robocar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/robocar.dir/robocar.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/Documents/robocar/robocar.cpp -o CMakeFiles/robocar.dir/robocar.cpp.s

CMakeFiles/robocar.dir/robocar.cpp.o.requires:

.PHONY : CMakeFiles/robocar.dir/robocar.cpp.o.requires

CMakeFiles/robocar.dir/robocar.cpp.o.provides: CMakeFiles/robocar.dir/robocar.cpp.o.requires
	$(MAKE) -f CMakeFiles/robocar.dir/build.make CMakeFiles/robocar.dir/robocar.cpp.o.provides.build
.PHONY : CMakeFiles/robocar.dir/robocar.cpp.o.provides

CMakeFiles/robocar.dir/robocar.cpp.o.provides.build: CMakeFiles/robocar.dir/robocar.cpp.o


# Object files for target robocar
robocar_OBJECTS = \
"CMakeFiles/robocar.dir/robocar.cpp.o"

# External object files for target robocar
robocar_EXTERNAL_OBJECTS =

robocar: CMakeFiles/robocar.dir/robocar.cpp.o
robocar: CMakeFiles/robocar.dir/build.make
robocar: libcapture.a
robocar: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.9
robocar: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.9
robocar: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.9
robocar: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.9
robocar: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.9
robocar: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.9
robocar: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.9
robocar: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.9
robocar: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.9
robocar: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.9
robocar: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.9
robocar: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.9
robocar: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.9
robocar: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.9
robocar: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.9
robocar: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.9
robocar: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.9
robocar: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.9
robocar: CMakeFiles/robocar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/james/Documents/robocar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable robocar"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/robocar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/robocar.dir/build: robocar

.PHONY : CMakeFiles/robocar.dir/build

CMakeFiles/robocar.dir/requires: CMakeFiles/robocar.dir/robocar.cpp.o.requires

.PHONY : CMakeFiles/robocar.dir/requires

CMakeFiles/robocar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/robocar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/robocar.dir/clean

CMakeFiles/robocar.dir/depend:
	cd /home/james/Documents/robocar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/james/Documents/robocar /home/james/Documents/robocar /home/james/Documents/robocar/build /home/james/Documents/robocar/build /home/james/Documents/robocar/build/CMakeFiles/robocar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/robocar.dir/depend

