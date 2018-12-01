cmake_minimum_required(VERSION 2.8.9)

project(caches)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o2 -std=c++0x" )

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(caches ${SOURCES})


