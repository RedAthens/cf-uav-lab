# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/uav/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uav/catkin_ws/build

# Include any dependencies generated for this target.
include mocap_optitrack/src/CMakeFiles/get_vel_node.dir/depend.make

# Include the progress variables for this target.
include mocap_optitrack/src/CMakeFiles/get_vel_node.dir/progress.make

# Include the compile flags for this target's objects.
include mocap_optitrack/src/CMakeFiles/get_vel_node.dir/flags.make

mocap_optitrack/src/CMakeFiles/get_vel_node.dir/get_velocity.cpp.o: mocap_optitrack/src/CMakeFiles/get_vel_node.dir/flags.make
mocap_optitrack/src/CMakeFiles/get_vel_node.dir/get_velocity.cpp.o: /home/uav/catkin_ws/src/mocap_optitrack/src/get_velocity.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/uav/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object mocap_optitrack/src/CMakeFiles/get_vel_node.dir/get_velocity.cpp.o"
	cd /home/uav/catkin_ws/build/mocap_optitrack/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/get_vel_node.dir/get_velocity.cpp.o -c /home/uav/catkin_ws/src/mocap_optitrack/src/get_velocity.cpp

mocap_optitrack/src/CMakeFiles/get_vel_node.dir/get_velocity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/get_vel_node.dir/get_velocity.cpp.i"
	cd /home/uav/catkin_ws/build/mocap_optitrack/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/uav/catkin_ws/src/mocap_optitrack/src/get_velocity.cpp > CMakeFiles/get_vel_node.dir/get_velocity.cpp.i

mocap_optitrack/src/CMakeFiles/get_vel_node.dir/get_velocity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/get_vel_node.dir/get_velocity.cpp.s"
	cd /home/uav/catkin_ws/build/mocap_optitrack/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/uav/catkin_ws/src/mocap_optitrack/src/get_velocity.cpp -o CMakeFiles/get_vel_node.dir/get_velocity.cpp.s

mocap_optitrack/src/CMakeFiles/get_vel_node.dir/get_velocity.cpp.o.requires:
.PHONY : mocap_optitrack/src/CMakeFiles/get_vel_node.dir/get_velocity.cpp.o.requires

mocap_optitrack/src/CMakeFiles/get_vel_node.dir/get_velocity.cpp.o.provides: mocap_optitrack/src/CMakeFiles/get_vel_node.dir/get_velocity.cpp.o.requires
	$(MAKE) -f mocap_optitrack/src/CMakeFiles/get_vel_node.dir/build.make mocap_optitrack/src/CMakeFiles/get_vel_node.dir/get_velocity.cpp.o.provides.build
.PHONY : mocap_optitrack/src/CMakeFiles/get_vel_node.dir/get_velocity.cpp.o.provides

mocap_optitrack/src/CMakeFiles/get_vel_node.dir/get_velocity.cpp.o.provides.build: mocap_optitrack/src/CMakeFiles/get_vel_node.dir/get_velocity.cpp.o

# Object files for target get_vel_node
get_vel_node_OBJECTS = \
"CMakeFiles/get_vel_node.dir/get_velocity.cpp.o"

# External object files for target get_vel_node
get_vel_node_EXTERNAL_OBJECTS =

/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: mocap_optitrack/src/CMakeFiles/get_vel_node.dir/get_velocity.cpp.o
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: mocap_optitrack/src/CMakeFiles/get_vel_node.dir/build.make
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /opt/ros/indigo/lib/libtf.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /opt/ros/indigo/lib/libtf2_ros.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /opt/ros/indigo/lib/libactionlib.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /opt/ros/indigo/lib/libmessage_filters.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /opt/ros/indigo/lib/libroscpp.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /opt/ros/indigo/lib/libtf2.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /opt/ros/indigo/lib/librosconsole.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /usr/lib/liblog4cxx.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /opt/ros/indigo/lib/librostime.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /opt/ros/indigo/lib/libcpp_common.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node: mocap_optitrack/src/CMakeFiles/get_vel_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node"
	cd /home/uav/catkin_ws/build/mocap_optitrack/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/get_vel_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
mocap_optitrack/src/CMakeFiles/get_vel_node.dir/build: /home/uav/catkin_ws/devel/lib/mocap_optitrack/get_vel_node
.PHONY : mocap_optitrack/src/CMakeFiles/get_vel_node.dir/build

mocap_optitrack/src/CMakeFiles/get_vel_node.dir/requires: mocap_optitrack/src/CMakeFiles/get_vel_node.dir/get_velocity.cpp.o.requires
.PHONY : mocap_optitrack/src/CMakeFiles/get_vel_node.dir/requires

mocap_optitrack/src/CMakeFiles/get_vel_node.dir/clean:
	cd /home/uav/catkin_ws/build/mocap_optitrack/src && $(CMAKE_COMMAND) -P CMakeFiles/get_vel_node.dir/cmake_clean.cmake
.PHONY : mocap_optitrack/src/CMakeFiles/get_vel_node.dir/clean

mocap_optitrack/src/CMakeFiles/get_vel_node.dir/depend:
	cd /home/uav/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uav/catkin_ws/src /home/uav/catkin_ws/src/mocap_optitrack/src /home/uav/catkin_ws/build /home/uav/catkin_ws/build/mocap_optitrack/src /home/uav/catkin_ws/build/mocap_optitrack/src/CMakeFiles/get_vel_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : mocap_optitrack/src/CMakeFiles/get_vel_node.dir/depend

