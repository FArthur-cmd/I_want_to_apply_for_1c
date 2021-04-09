# cmake_minimum_required(VERSION <specify CMake version here>)
project(for_1c)

set(CMAKE_CXX_STANDARD 20)

add_executable(for_1c main.cpp Node.hpp Node.cpp Finder.cpp Finder.hpp)