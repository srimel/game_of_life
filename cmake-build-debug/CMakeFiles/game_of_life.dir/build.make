# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/stu/CLionProjects/game_of_life

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/stu/CLionProjects/game_of_life/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/game_of_life.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/game_of_life.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game_of_life.dir/flags.make

CMakeFiles/game_of_life.dir/gol.cpp.o: CMakeFiles/game_of_life.dir/flags.make
CMakeFiles/game_of_life.dir/gol.cpp.o: ../gol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stu/CLionProjects/game_of_life/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game_of_life.dir/gol.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game_of_life.dir/gol.cpp.o -c /Users/stu/CLionProjects/game_of_life/gol.cpp

CMakeFiles/game_of_life.dir/gol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game_of_life.dir/gol.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stu/CLionProjects/game_of_life/gol.cpp > CMakeFiles/game_of_life.dir/gol.cpp.i

CMakeFiles/game_of_life.dir/gol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game_of_life.dir/gol.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stu/CLionProjects/game_of_life/gol.cpp -o CMakeFiles/game_of_life.dir/gol.cpp.s

CMakeFiles/game_of_life.dir/main.cpp.o: CMakeFiles/game_of_life.dir/flags.make
CMakeFiles/game_of_life.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stu/CLionProjects/game_of_life/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game_of_life.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game_of_life.dir/main.cpp.o -c /Users/stu/CLionProjects/game_of_life/main.cpp

CMakeFiles/game_of_life.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game_of_life.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stu/CLionProjects/game_of_life/main.cpp > CMakeFiles/game_of_life.dir/main.cpp.i

CMakeFiles/game_of_life.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game_of_life.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stu/CLionProjects/game_of_life/main.cpp -o CMakeFiles/game_of_life.dir/main.cpp.s

# Object files for target game_of_life
game_of_life_OBJECTS = \
"CMakeFiles/game_of_life.dir/gol.cpp.o" \
"CMakeFiles/game_of_life.dir/main.cpp.o"

# External object files for target game_of_life
game_of_life_EXTERNAL_OBJECTS =

game_of_life: CMakeFiles/game_of_life.dir/gol.cpp.o
game_of_life: CMakeFiles/game_of_life.dir/main.cpp.o
game_of_life: CMakeFiles/game_of_life.dir/build.make
game_of_life: CMakeFiles/game_of_life.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/stu/CLionProjects/game_of_life/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable game_of_life"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game_of_life.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game_of_life.dir/build: game_of_life
.PHONY : CMakeFiles/game_of_life.dir/build

CMakeFiles/game_of_life.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game_of_life.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game_of_life.dir/clean

CMakeFiles/game_of_life.dir/depend:
	cd /Users/stu/CLionProjects/game_of_life/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/stu/CLionProjects/game_of_life /Users/stu/CLionProjects/game_of_life /Users/stu/CLionProjects/game_of_life/cmake-build-debug /Users/stu/CLionProjects/game_of_life/cmake-build-debug /Users/stu/CLionProjects/game_of_life/cmake-build-debug/CMakeFiles/game_of_life.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game_of_life.dir/depend
