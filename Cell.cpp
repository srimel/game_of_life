#include "Cell.h"

Cell::Cell() {
    neighbors = 0;
    state = false;
}

bool Cell::isAlive() const {
    if(state)
        return true;
    return false;
}
