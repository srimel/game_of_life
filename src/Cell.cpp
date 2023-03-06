#include "Cell.h"

Cell::Cell() {
    neighbors = 0;
    state = false;
}

void Cell::setNeighbors(int x) {
    neighbors = x;
}

int Cell::getNeighbors() const {
    return neighbors;
}

void Cell::setLife(bool x) {
    state = x;
}

bool Cell::isAlive() const {
    if(state)
        return true;
    return false;
}
