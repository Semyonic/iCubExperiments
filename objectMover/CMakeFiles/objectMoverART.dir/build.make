# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_COMMAND = /usr/local/Cellar/cmake30/3.0.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake30/3.0.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Semih/Documents/GitHub/iCub-ExampleCodes/objectMover

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Semih/Documents/GitHub/iCub-ExampleCodes/objectMover

# Include any dependencies generated for this target.
include CMakeFiles/objectMoverART.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/objectMoverART.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/objectMoverART.dir/flags.make

CMakeFiles/objectMoverART.dir/objectMoverART.o: CMakeFiles/objectMoverART.dir/flags.make
CMakeFiles/objectMoverART.dir/objectMoverART.o: objectMoverART.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Semih/Documents/GitHub/iCub-ExampleCodes/objectMover/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/objectMoverART.dir/objectMoverART.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/objectMoverART.dir/objectMoverART.o -c /Users/Semih/Documents/GitHub/iCub-ExampleCodes/objectMover/objectMoverART.cpp

CMakeFiles/objectMoverART.dir/objectMoverART.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/objectMoverART.dir/objectMoverART.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Semih/Documents/GitHub/iCub-ExampleCodes/objectMover/objectMoverART.cpp > CMakeFiles/objectMoverART.dir/objectMoverART.i

CMakeFiles/objectMoverART.dir/objectMoverART.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/objectMoverART.dir/objectMoverART.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Semih/Documents/GitHub/iCub-ExampleCodes/objectMover/objectMoverART.cpp -o CMakeFiles/objectMoverART.dir/objectMoverART.s

CMakeFiles/objectMoverART.dir/objectMoverART.o.requires:
.PHONY : CMakeFiles/objectMoverART.dir/objectMoverART.o.requires

CMakeFiles/objectMoverART.dir/objectMoverART.o.provides: CMakeFiles/objectMoverART.dir/objectMoverART.o.requires
	$(MAKE) -f CMakeFiles/objectMoverART.dir/build.make CMakeFiles/objectMoverART.dir/objectMoverART.o.provides.build
.PHONY : CMakeFiles/objectMoverART.dir/objectMoverART.o.provides

CMakeFiles/objectMoverART.dir/objectMoverART.o.provides.build: CMakeFiles/objectMoverART.dir/objectMoverART.o

# Object files for target objectMoverART
objectMoverART_OBJECTS = \
"CMakeFiles/objectMoverART.dir/objectMoverART.o"

# External object files for target objectMoverART
objectMoverART_EXTERNAL_OBJECTS =

objectMoverART: CMakeFiles/objectMoverART.dir/objectMoverART.o
objectMoverART: CMakeFiles/objectMoverART.dir/build.make
objectMoverART: /usr/local/lib/libopencv_videostab.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_video.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_ts.a
objectMoverART: /usr/local/lib/libopencv_superres.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_stitching.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_photo.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_ocl.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_objdetect.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_nonfree.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_ml.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_legacy.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_imgproc.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_highgui.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_gpu.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_flann.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_features2d.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_core.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_contrib.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_calib3d.2.4.10.dylib
objectMoverART: /usr/local/lib/libYARP_OS.2.3.63.6.dylib
objectMoverART: /usr/local/lib/libYARP_sig.2.3.63.6.dylib
objectMoverART: /usr/local/lib/libYARP_math.2.3.63.6.dylib
objectMoverART: /usr/local/lib/libYARP_dev.2.3.63.6.dylib
objectMoverART: /usr/local/lib/libYARP_name.2.3.63.6.dylib
objectMoverART: /usr/local/lib/libYARP_init.2.3.63.6.dylib
objectMoverART: /usr/local/lib/libiCubIDLClients.a
objectMoverART: /usr/local/lib/libiCubDev.a
objectMoverART: /usr/local/lib/libiCubVis.a
objectMoverART: /usr/local/lib/liblogpolar.a
objectMoverART: /usr/local/lib/libboostMIL.a
objectMoverART: /usr/local/lib/libctrlLib.a
objectMoverART: /usr/local/lib/libskinDynLib.a
objectMoverART: /usr/local/lib/libiKin.a
objectMoverART: /usr/local/lib/libiDyn.a
objectMoverART: /usr/local/lib/liblearningMachine.a
objectMoverART: /usr/local/lib/libperceptiveModels.a
objectMoverART: /usr/local/lib/libactionPrimitives.a
objectMoverART: /usr/local/lib/libarmcalibrator.a
objectMoverART: /usr/local/lib/libarmcalibratorj8.a
objectMoverART: /usr/local/lib/libcartesiancontrollerserver.a
objectMoverART: /usr/local/lib/libcartesiancontrollerclient.a
objectMoverART: /usr/local/lib/libgazecontrollerclient.a
objectMoverART: /usr/local/lib/libhandcalibrator.a
objectMoverART: /usr/local/lib/liblegscalibrator.a
objectMoverART: /usr/local/lib/liblogpolarclient.a
objectMoverART: /usr/local/lib/liblogpolargrabber.a
objectMoverART: /usr/local/lib/libdebugInterfaceClient.a
objectMoverART: /usr/local/lib/libdebugInterfaceWrapper.a
objectMoverART: /usr/local/lib/libembObjMotionControl.a
objectMoverART: /usr/local/lib/libethResources.a
objectMoverART: /usr/local/lib/libicubmod.a
objectMoverART: /usr/local/lib/libd4c.a
objectMoverART: /usr/local/lib/liboptimization.a
objectMoverART: /usr/local/lib/liblib0.a
objectMoverART: /usr/local/lib/liblib1.a
objectMoverART: /usr/local/lib/libsharksWithLasers.a
objectMoverART: /usr/local/lib/libcanLoaderLib.a
objectMoverART: /usr/local/lib/libicubmod.a
objectMoverART: /usr/local/lib/libopencv_videostab.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_ts.a
objectMoverART: /usr/local/lib/libopencv_superres.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_stitching.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_contrib.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_nonfree.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_ocl.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_gpu.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_photo.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_objdetect.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_legacy.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_video.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_ml.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_calib3d.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_features2d.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_highgui.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_imgproc.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_flann.2.4.10.dylib
objectMoverART: /usr/local/lib/libopencv_core.2.4.10.dylib
objectMoverART: /usr/local/lib/libskinDynLib.a
objectMoverART: /usr/local/lib/libperceptiveModels.a
objectMoverART: /usr/local/lib/liblearningMachine.a
objectMoverART: /usr/local/lib/libarmcalibrator.a
objectMoverART: /usr/local/lib/libarmcalibratorj8.a
objectMoverART: /usr/local/lib/libcartesiancontrollerserver.a
objectMoverART: /usr/local/lib/libcartesiancontrollerclient.a
objectMoverART: /usr/local/lib/libiKin.a
objectMoverART: /usr/local/lib/libgazecontrollerclient.a
objectMoverART: /usr/local/lib/libhandcalibrator.a
objectMoverART: /usr/local/lib/liblegscalibrator.a
objectMoverART: /usr/local/lib/liblogpolarclient.a
objectMoverART: /usr/local/lib/liblogpolargrabber.a
objectMoverART: /usr/local/lib/liblogpolar.a
objectMoverART: /usr/local/lib/libdebugInterfaceClient.a
objectMoverART: /usr/local/lib/libdebugInterfaceWrapper.a
objectMoverART: /usr/local/lib/libembObjMotionControl.a
objectMoverART: /usr/local/lib/libiCubDev.a
objectMoverART: /usr/local/lib/libethResources.a
objectMoverART: /usr/local/lib/libctrlLib.a
objectMoverART: /usr/local/lib/libgsl.dylib
objectMoverART: /usr/local/lib/libgslcblas.dylib
objectMoverART: /usr/local/lib/libipopt.dylib
objectMoverART: /usr/lib/liblapack.dylib
objectMoverART: /usr/lib/libblas.dylib
objectMoverART: /usr/lib/libm.dylib
objectMoverART: /usr/lib/libdl.dylib
objectMoverART: /usr/local/lib/libcoinmumps.dylib
objectMoverART: /usr/local/Cellar/gcc/4.9.2_1/lib/gcc/4.9/libgfortran.dylib
objectMoverART: /usr/local/Cellar/gcc/4.9.2_1/lib/gcc/4.9/libquadmath.dylib
objectMoverART: /usr/lib/libblas.dylib
objectMoverART: /usr/lib/libm.dylib
objectMoverART: /usr/lib/libdl.dylib
objectMoverART: /usr/local/lib/libcoinmumps.dylib
objectMoverART: /usr/local/Cellar/gcc/4.9.2_1/lib/gcc/4.9/libgfortran.dylib
objectMoverART: /usr/local/Cellar/gcc/4.9.2_1/lib/gcc/4.9/libquadmath.dylib
objectMoverART: /usr/local/lib/libcoinmetis.dylib
objectMoverART: /usr/local/lib/liblib0.a
objectMoverART: /usr/local/lib/libYARP_math.2.3.63.6.dylib
objectMoverART: /usr/local/lib/libYARP_dev.2.3.63.6.dylib
objectMoverART: /usr/local/lib/libYARP_sig.2.3.63.6.dylib
objectMoverART: /usr/local/lib/libYARP_name.2.3.63.6.dylib
objectMoverART: /usr/local/lib/libYARP_init.2.3.63.6.dylib
objectMoverART: /usr/local/lib/libYARP_OS.2.3.63.6.dylib
objectMoverART: /usr/local/lib/libACE.dylib
objectMoverART: CMakeFiles/objectMoverART.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable objectMoverART"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/objectMoverART.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/objectMoverART.dir/build: objectMoverART
.PHONY : CMakeFiles/objectMoverART.dir/build

CMakeFiles/objectMoverART.dir/requires: CMakeFiles/objectMoverART.dir/objectMoverART.o.requires
.PHONY : CMakeFiles/objectMoverART.dir/requires

CMakeFiles/objectMoverART.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/objectMoverART.dir/cmake_clean.cmake
.PHONY : CMakeFiles/objectMoverART.dir/clean

CMakeFiles/objectMoverART.dir/depend:
	cd /Users/Semih/Documents/GitHub/iCub-ExampleCodes/objectMover && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Semih/Documents/GitHub/iCub-ExampleCodes/objectMover /Users/Semih/Documents/GitHub/iCub-ExampleCodes/objectMover /Users/Semih/Documents/GitHub/iCub-ExampleCodes/objectMover /Users/Semih/Documents/GitHub/iCub-ExampleCodes/objectMover /Users/Semih/Documents/GitHub/iCub-ExampleCodes/objectMover/CMakeFiles/objectMoverART.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/objectMoverART.dir/depend

