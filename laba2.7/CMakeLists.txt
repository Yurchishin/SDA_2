cmake_minimum_required(VERSION 3.10)

project(BSTree)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES "src/*.cpp")

file(GLOB INCLUDE "include/*.h")

add_executable(${PROJECT_NAME} main.cpp ${INCLUDE} ${SOURCES})