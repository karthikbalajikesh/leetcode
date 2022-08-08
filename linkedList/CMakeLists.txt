# cmake version to be used
cmake_minimum_required( VERSION 3.0 )
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_BUILD_TYPE DEBUG)
# project name
project(linkedlist)
include_directories(include)
file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
file(GLOB SRC_FILES src/*.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


# target
add_executable(linkedList main.cpp ${SRC_FILES})
