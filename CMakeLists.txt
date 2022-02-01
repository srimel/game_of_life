cmake_minimum_required(VERSION 3.20)
project(game_of_life)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")

include_directories(.)

add_executable(
        game_of_life
        gol.cpp
        gol.h
        main.cpp)

