#ifndef _BOARD_H_
#define _BOARD_H_

#include <string>
#include <fstream>
#include "Cell.h"

// Default size of game board
#define ROW 10
#define COL 20

class Board {
public:
    explicit Board(int r = ROW, int c = COL);
    Board(const Board & src);
    ~Board();
    void reset();
    void nextGen();
    void autoNextGen();
    void setupBoard(); // prompts user to set up the game.
    void draw(); // saves board states
    void printBoard();
    bool loadBoard(std::string fileName);
    bool loadConfig(std::string fileName);
    bool saveBoard(std::string fileName);
    bool isZero();
    bool operator==(Cell **);

private:
    Cell ** board;
    int row, col;
    void printHorizontalLine() const;
    void setState(int row, int col, bool x);
    void printColNum() const;
    void updateNeighbors();
    Cell ** getNextGen();

};

#endif