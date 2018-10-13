cmake_minimum_required(VERSION 3.8)

project(CUComputerGraphicsHackNight)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

include("cmake/compiler.cmake")
include("cmake/clang-tidy.cmake")
include("cmake/cppcheck.cmake")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME} "src/main.cpp")
add_executable(${PROJECT_NAME}Test "test/main.cpp")
