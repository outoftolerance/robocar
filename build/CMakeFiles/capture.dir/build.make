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
include CMakeFiles/capture.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/capture.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/capture.dir/flags.make

CMakeFiles/capture.dir/include/capture/capture.cpp.o: CMakeFiles/capture.dir/flags.make
CMakeFiles/capture.dir/include/capture/capture.cpp.o: ../include/capture/capture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/james/Documents/robocar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/capture.dir/include/capture/capture.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/capture.dir/include/capture/capture.cpp.o -c /home/james/Documents/robocar/include/capture/capture.cpp

CMakeFiles/capture.dir/include/capture/capture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/capture.dir/include/capture/capture.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/Documents/robocar/include/capture/capture.cpp > CMakeFiles/capture.dir/include/capture/capture.cpp.i

CMakeFiles/capture.dir/include/capture/capture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/capture.dir/include/capture/capture.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/Documents/robocar/include/capture/capture.cpp -o CMakeFiles/capture.dir/include/capture/capture.cpp.s

CMakeFiles/capture.dir/include/capture/capture.cpp.o.requires:

.PHONY : CMakeFiles/capture.dir/include/capture/capture.cpp.o.requires

CMakeFiles/capture.dir/include/capture/capture.cpp.o.provides: CMakeFiles/capture.dir/include/capture/capture.cpp.o.requires
	$(MAKE) -f CMakeFiles/capture.dir/build.make CMakeFiles/capture.dir/include/capture/capture.cpp.o.provides.build
.PHONY : CMakeFiles/capture.dir/include/capture/capture.cpp.o.provides

CMakeFiles/capture.dir/include/capture/capture.cpp.o.provides.build: CMakeFiles/capture.dir/include/capture/capture.cpp.o


# Object files for target capture
capture_OBJECTS = \
"CMakeFiles/capture.dir/include/capture/capture.cpp.o"

# External object files for target capture
capture_EXTERNAL_OBJECTS =

libcapture.a: CMakeFiles/capture.dir/include/capture/capture.cpp.o
libcapture.a: CMakeFiles/capture.dir/build.make
libcapture.a: CMakeFiles/capture.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/james/Documents/robocar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcapture.a"
	$(CMAKE_COMMAND) -P CMakeFiles/capture.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/capture.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/capture.dir/build: libcapture.a

.PHONY : CMakeFiles/capture.dir/build

CMakeFiles/capture.dir/requires: CMakeFiles/capture.dir/include/capture/capture.cpp.o.requires

.PHONY : CMakeFiles/capture.dir/requires

CMakeFiles/capture.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/capture.dir/cmake_clean.cmake
.PHONY : CMakeFiles/capture.dir/clean

CMakeFiles/capture.dir/depend:
	cd /home/james/Documents/robocar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/james/Documents/robocar /home/james/Documents/robocar /home/james/Documents/robocar/build /home/james/Documents/robocar/build /home/james/Documents/robocar/build/CMakeFiles/capture.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/capture.dir/depend
