cmake_minimum_required(VERSION 2.8)
PROJECT(imagePickUp)
FIND_PACKAGE(YARP)
FIND_PACKAGE(ICUB)
# add include directories
INCLUDE_DIRECTORIES(${YARP_INCLUDE_DIRS} ${ICUB_INCLUDE_DIRS})
# add required linker flags
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${ICUB_LINK_FLAGS}")      
ADD_EXECUTABLE(imagePickUp main.cpp)
# we now add the YARP and iCub libraries to our project.
TARGET_LINK_LIBRARIES(imagePickUp ${YARP_LIBRARIES} ${ICUB_LIBRARIES})
