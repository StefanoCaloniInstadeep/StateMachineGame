cmake_minimum_required(VERSION 3.20)
project(StateExample)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)




add_executable(StateExample 
  main.cpp 
  Physics.cpp
  Player.cpp
  World.cpp
  Rendering.cpp)

find_package(raylib REQUIRED)
target_link_libraries(StateExample
  PUBLIC
  raylib
  )

set_property(TARGET StateExample PROPERTY CXX_STANDARD 23)

target_compile_options(StateExample PRIVATE -pedantic -Wall -Wextra -Wshadow -Wconversion -Werror -Wfatal-errors -Wno-extra-semi -g)
target_link_libraries(StateExample PUBLIC)
