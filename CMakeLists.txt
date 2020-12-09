cmake_minimum_required(VERSION 3.9)
project(crc_example)

set(CMAKE_CXX_STANDARD 11)
set(HEADER_FILES "include/Array.h")

include_directories("include")

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable(crc_example "src/main.cpp" "src/Array.cpp" "include/Array.h")