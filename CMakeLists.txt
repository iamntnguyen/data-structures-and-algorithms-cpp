cmake_minimum_required(VERSION 3.20)
project(demo LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(my_app src/main.cpp)
set_target_properties(my_app PROPERTIES WIN32_EXECUTABLE FALSE)
