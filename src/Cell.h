#ifndef GAME_OF_LIFE_CELL_H
#define GAME_OF_LIFE_CELL_H

class Cell {
public:
    Cell();
    void setNeighbors(int x);
    int getNeighbors() const;
    void setLife(bool x);
    bool isAlive() const;
private:
    int neighbors; // represents cells adjacent to this one that are alive.
    bool state;
};

#endif //GAME_OF_LIFE_CELL_H
