#ifndef _BOARD_H_
#define _BOARD_H_

#include <string>
#include <fstream>
#include "Cell.h"

#define ROW 10
#define COL 20

class Board {
public:
    explicit Board(int r = ROW, int c = COL);
    Board(const Board & src);
    ~Board();
    void reset();
    bool nextGen();
    void autoNextGen();
    void setupBoard();
    void draw();
    void printBoard();
    bool loadBoard(const std::string& fileName);
    bool loadConfig(const std::string& fileName);
    bool saveBoard(const std::string& fileName);
    bool isZero();
    bool operator==(Cell **) const;

private:
    Cell ** board;
    int row, col;
    void printHorizontalLine() const;
    void setState(int row, int col);
    void printColNum() const;
    void updateNeighbors();
    Cell ** getNextGen();

};

#endif