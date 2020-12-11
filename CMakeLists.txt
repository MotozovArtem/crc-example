cmake_minimum_required(VERSION 3.9)
project(crc_example)

set(CMAKE_CXX_STANDARD 11)
set(HEADER "include/Array.h")
set(SOURCE "src/main.cpp" "src/Array.cpp")

add_executable(crc_example ${SOURCE} ${HEADER})