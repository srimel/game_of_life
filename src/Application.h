#ifndef GAME_OF_LIFE_APPLICATION_H
#define GAME_OF_LIFE_APPLICATION_H
#include "Board.h"

class Application {
public:
    void runApplication();
    static void clearScreen();

private:
    Board _board;
};

#endif //GAME_OF_LIFE_APPLICATION_H