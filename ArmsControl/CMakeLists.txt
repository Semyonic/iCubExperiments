CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
SET(PROJECTNAME armsControlTest)
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0") # debug, no optimisation
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage") # enabling coverage
PROJECT(${PROJECTNAME})

FIND_PACKAGE(YARP)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${YARP_MODULE_PATH})

include_directories(${YARP_INCLUDE_DIRS})
add_executable(armsControl armsControl.cpp)
target_link_libraries(armsControl ${YARP_LIBRARIES})
