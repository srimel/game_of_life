#include "Application.h"
#include "Utility.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Application::runApplication()
{
    char resp;
    do {
        bool check;
        Utility::clearScreen();
        do {
            _board.printBoard();
            cout << "Testing Board Setup for Conway's Game of Life" << endl;
            cout << "Menu Options:\n" << "[1] Draw [2] Load Blinker+ [3] Reset [4] Next [5] Auto-Run [0] Exit\n";
            cout << ">>> ";
            cin >> resp;
            cin.ignore(100, '\n');
            if (resp < '0' || resp > '5')
                check = false;
            else
                check = true;
            Utility::clearScreen();
        } while (!check);

        switch (resp) {
            case '0':
                cout << "\n\nGoodbye!\n" << endl;
                break;

            case '1':
               _board.draw();
                break;

            case '2': {
                if (_board.loadBoard("blinker_plus")) {
                    _board.printBoard();
                } else {
                    std::cerr << "Error: loading file failed for blinker_board.txt" << endl;
                }
                break;
            }
            case '3':
                _board.reset();
                break;
            case '4':
                _board.nextGen();
                break;
            case '5':
                _board.autoNextGen(); // will run 30 times (hardcoded)
                break;
            default:
                cout << "Shouldn't be hitting the default menu case..." << endl;
                break;
        }
    }while(resp != '0');
}


