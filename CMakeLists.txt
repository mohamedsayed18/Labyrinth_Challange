cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++14")

project(labyrinth)

add_executable(
	labyrinth
	demo.cpp
)
