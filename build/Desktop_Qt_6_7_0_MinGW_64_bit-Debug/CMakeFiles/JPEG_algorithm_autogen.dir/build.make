# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\adria\Desktop\Adrian\projects\Qt\JPEG_algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\adria\Desktop\Adrian\projects\Qt\JPEG_algorithm\build\Desktop_Qt_6_7_0_MinGW_64_bit-Debug

# Utility rule file for JPEG_algorithm_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/JPEG_algorithm_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/JPEG_algorithm_autogen.dir/progress.make

CMakeFiles/JPEG_algorithm_autogen: JPEG_algorithm_autogen/timestamp

JPEG_algorithm_autogen/timestamp: C:/Qt/6.7.0/mingw_64/./bin/moc.exe
JPEG_algorithm_autogen/timestamp: C:/Qt/6.7.0/mingw_64/./bin/uic.exe
JPEG_algorithm_autogen/timestamp: CMakeFiles/JPEG_algorithm_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\adria\Desktop\Adrian\projects\Qt\JPEG_algorithm\build\Desktop_Qt_6_7_0_MinGW_64_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target JPEG_algorithm"
	"C:\Program Files\CMake\bin\cmake.exe" -E cmake_autogen C:/Users/adria/Desktop/Adrian/projects/Qt/JPEG_algorithm/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/CMakeFiles/JPEG_algorithm_autogen.dir/AutogenInfo.json Debug
	"C:\Program Files\CMake\bin\cmake.exe" -E touch C:/Users/adria/Desktop/Adrian/projects/Qt/JPEG_algorithm/build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/JPEG_algorithm_autogen/timestamp

JPEG_algorithm_autogen: CMakeFiles/JPEG_algorithm_autogen
JPEG_algorithm_autogen: JPEG_algorithm_autogen/timestamp
JPEG_algorithm_autogen: CMakeFiles/JPEG_algorithm_autogen.dir/build.make
.PHONY : JPEG_algorithm_autogen

# Rule to build all files generated by this target.
CMakeFiles/JPEG_algorithm_autogen.dir/build: JPEG_algorithm_autogen
.PHONY : CMakeFiles/JPEG_algorithm_autogen.dir/build

CMakeFiles/JPEG_algorithm_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\JPEG_algorithm_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/JPEG_algorithm_autogen.dir/clean

CMakeFiles/JPEG_algorithm_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\adria\Desktop\Adrian\projects\Qt\JPEG_algorithm C:\Users\adria\Desktop\Adrian\projects\Qt\JPEG_algorithm C:\Users\adria\Desktop\Adrian\projects\Qt\JPEG_algorithm\build\Desktop_Qt_6_7_0_MinGW_64_bit-Debug C:\Users\adria\Desktop\Adrian\projects\Qt\JPEG_algorithm\build\Desktop_Qt_6_7_0_MinGW_64_bit-Debug C:\Users\adria\Desktop\Adrian\projects\Qt\JPEG_algorithm\build\Desktop_Qt_6_7_0_MinGW_64_bit-Debug\CMakeFiles\JPEG_algorithm_autogen.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/JPEG_algorithm_autogen.dir/depend
