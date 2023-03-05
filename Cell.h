#ifndef GAME_OF_LIFE_CELL_H
#define GAME_OF_LIFE_CELL_H

class Cell {
public:
    Cell();
    void setNeighbors(int x) {neighbors = x;}
    int getNeighbors() const {return neighbors;}
    void setLife(bool x) {state = x;}
    bool isAlive() const;
private:
    int neighbors; // represents cells adjacent to this one that are alive.
    bool state;
};

#endif //GAME_OF_LIFE_CELL_H
