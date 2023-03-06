# Conway's Game of Life

### Overview

Console implementation of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) created using C++.

### Build and Run Instructions (Unix/Linux)
1. Verify that [cmake](https://cmake.org/) is installed. (Needs to be at least version 3.21)
2. Create a build directory within project directory
3. From build directory run: `cmake path/to/project/directory`
4. To build project run: `make` from the build directory
5. To start the program run: `./game_of_life` from the build directory

### Rule Set
- Births: Each dead cell adjacent to exactly three live neighbors will become
   live in the next generation.
- Death by isolation: Each live cell with one or fewer live neighbors will die
   in the next generation.
- Death by overcrowding: Each live cell with four or more live neighbors will
   die in the next generation.
- Survival: Each live cell with either two or three live neighbors will remain
   alive for the next generation.
- Apply rules to all cells at the same time.

### Starting Screen
```
   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15| 16| 17| 18| 19|
   ---------------------------------------------------------------------------------
0: |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   ---------------------------------------------------------------------------------
1: |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   ---------------------------------------------------------------------------------
2: |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   ---------------------------------------------------------------------------------
3: |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   ---------------------------------------------------------------------------------
4: |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   ---------------------------------------------------------------------------------
5: |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   ---------------------------------------------------------------------------------
6: |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   ---------------------------------------------------------------------------------
7: |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   ---------------------------------------------------------------------------------
8: |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   ---------------------------------------------------------------------------------
9: |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   ---------------------------------------------------------------------------------
Testing Board Setup for Conway's Game of Life
Menu Options:
[1] Draw [2] Load Blinker+ [3] Reset [4] Next [5] Auto-Run [0] Exit
```
