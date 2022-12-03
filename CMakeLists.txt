cmake_minimum_required(VERSION 2.8.3)
project(demo)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g -pthread")


add_executable(demo demo2.cpp )
target_link_libraries(demo pthread)
