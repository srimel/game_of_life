cmake_minimum_required(VERSION 3.21)
project(game_of_life)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(game_of_life
        src/Board.cpp
        src/Board.h
        src/main.cpp src/Cell.cpp src/Cell.h src/Application.cpp src/Application.h src/Utility.cpp src/Utility.h)