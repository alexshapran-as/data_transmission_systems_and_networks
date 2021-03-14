cmake_minimum_required(VERSION 3.17)
project(data_transmission_systems_and_networks)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_transmission_systems_and_networks main.cpp Queue.cpp Queue.h Package.cpp Package.h utils.cpp utils.h Byte.h)