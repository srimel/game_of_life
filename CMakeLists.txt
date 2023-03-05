cmake_minimum_required(VERSION 3.21)
project(game_of_life)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(game_of_life
        Board.cpp
        Board.h
        main.cpp Cell.cpp Cell.h Application.cpp Application.h)