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
CMAKE_SOURCE_DIR = /home/long/eclispseProject/10222506/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/long/eclispseProject/10222506/code/build

# Include any dependencies generated for this target.
include CMakeFiles/caches.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/caches.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/caches.dir/flags.make

CMakeFiles/caches.dir/src/main.cpp.o: CMakeFiles/caches.dir/flags.make
CMakeFiles/caches.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/long/eclispseProject/10222506/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/caches.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/caches.dir/src/main.cpp.o -c /home/long/eclispseProject/10222506/code/src/main.cpp

CMakeFiles/caches.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/caches.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/long/eclispseProject/10222506/code/src/main.cpp > CMakeFiles/caches.dir/src/main.cpp.i

CMakeFiles/caches.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/caches.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/long/eclispseProject/10222506/code/src/main.cpp -o CMakeFiles/caches.dir/src/main.cpp.s

CMakeFiles/caches.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/caches.dir/src/main.cpp.o.requires

CMakeFiles/caches.dir/src/main.cpp.o.provides: CMakeFiles/caches.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/caches.dir/build.make CMakeFiles/caches.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/caches.dir/src/main.cpp.o.provides

CMakeFiles/caches.dir/src/main.cpp.o.provides.build: CMakeFiles/caches.dir/src/main.cpp.o


# Object files for target caches
caches_OBJECTS = \
"CMakeFiles/caches.dir/src/main.cpp.o"

# External object files for target caches
caches_EXTERNAL_OBJECTS =

caches: CMakeFiles/caches.dir/src/main.cpp.o
caches: CMakeFiles/caches.dir/build.make
caches: CMakeFiles/caches.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/long/eclispseProject/10222506/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable caches"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/caches.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/caches.dir/build: caches

.PHONY : CMakeFiles/caches.dir/build

CMakeFiles/caches.dir/requires: CMakeFiles/caches.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/caches.dir/requires

CMakeFiles/caches.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/caches.dir/cmake_clean.cmake
.PHONY : CMakeFiles/caches.dir/clean

CMakeFiles/caches.dir/depend:
	cd /home/long/eclispseProject/10222506/code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/long/eclispseProject/10222506/code /home/long/eclispseProject/10222506/code /home/long/eclispseProject/10222506/code/build /home/long/eclispseProject/10222506/code/build /home/long/eclispseProject/10222506/code/build/CMakeFiles/caches.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/caches.dir/depend

