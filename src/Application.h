#ifndef GAME_OF_LIFE_APPLICATION_H
#define GAME_OF_LIFE_APPLICATION_H
#include "Board.h"

class Application {
public:
    void runApplication();

private:
    Board _board;

    char getUserInput();

    char promptBoardMenu();
};

#endif //GAME_OF_LIFE_APPLICATION_H
