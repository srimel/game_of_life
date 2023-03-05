#include "Board.h"
#include <iostream>

// This program is a simulation of Conway's game of life.
// TODO: Need to figure out a way to stop the auto generation when the board fails to change state after x generations
// Will try to finish before spring term

using std::cout;
using std::endl;
using std::cin;

int main() {
    Board b;
    char resp;
    do {
        bool check;
        clearScreen();
        do {
            b.printBoard();
            cout << "Testing Board Setup for Conway's Game of Life" << endl;
            cout << "Menu Options:\n" << "[1] Draw [2] Load Blinker+ [3] Reset [4] Next [5] Auto-Run [0] Exit\n";
            cout << ">>> ";
            cin >> resp;
            cin.ignore(100, '\n');
            if (resp < '0' || resp > '5')
                check = false;
            else
                check = true;
            clearScreen();
        } while (!check);

        switch (resp) {
            case '0':
                cout << "\n\nGoodbye!\n" << endl;
                break;

            case '1':
                b.draw();
                break;

            case '2': {
                if (b.loadBoard("blinker_plus")) {
                    b.printBoard();
                } else {
                    std::cerr << "Error: loading file failed for blinker_board.txt" << endl;
                }
                break;
            }
            case '3':
                b.reset();
                break;
            case '4':
                b.nextGen();
                break;
            case '5':
                b.autoNextGen(); // will run 30 times (hardcoded)
                break;
            default:
                cout << "Shouldn't be hitting the default menu case..." << endl;
                break;
        }
    }while(resp != '0');

	return 0;
}

void clearScreen() {
	for(int i = 0; i < 50; ++i) {
		cout <<'\n';
	}
}