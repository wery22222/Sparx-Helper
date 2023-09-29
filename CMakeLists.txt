cmake_minimum_required(VERSION 3.26)
project(Sparx_Helper)
set(CMAKE_CXX_STANDARD 23)
add_executable(test Main.cpp fileIO.cpp fileIO.hpp mainConstructor.cpp output.cpp update.cpp input.cpp)
