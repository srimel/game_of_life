#include "Utility.h"
#include <iostream>


void Utility::clearScreen() {
    for(int i = 0; i < 50; ++i) {
        std::cout <<'\n';
    }
}
