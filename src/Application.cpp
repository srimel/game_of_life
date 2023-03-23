#include "Application.h"
#include "Utility.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Application::runApplication()
{
    char resp;

    void (Application::*menuFunctions[])() = {
            &Application::exitApplication,
            &Application::drawBoard,
            &Application::loadBlinkerBoard,
            &Application::resetBoard,
            &Application::generateNextGen,
            &Application::autoNextGen
    };

    int totalMenuOptions = sizeof(menuFunctions) / sizeof(menuFunctions[0]);

    do {
        resp = getUserInput();
        int index = resp - '0'; // Convert char to integer index
        if (index >= 0 && index <= totalMenuOptions && menuFunctions[index]) {
            (this->*menuFunctions[index])();
        } else {
            cout << "Invalid menu option" << endl;
        }
    }while(resp != '0');
}

char Application::getUserInput() {
    char resp;
    bool check;
    Utility::clearScreen();
    do {
        resp = promptBoardMenu();
        if (resp < '0' || resp > '5')
            check = false;
        else
            check = true;
        Utility::clearScreen();
    } while (!check);
    return resp;
}

char Application::promptBoardMenu() {
    char resp;
    _board.printBoard();
    cout << "Menu Options:\n" << "[1] Draw [2] Load Blinker+ [3] Reset [4] Next [5] Auto-Run [0] Exit\n";
    cout << ">>> ";
    cin >> resp;
    cin.ignore(100, '\n');
    return resp;
}

void Application::drawBoard() {
    _board.draw();
}

void Application::loadBlinkerBoard() {
    if (_board.loadBoard("blinker_plus")) {
        _board.printBoard();
    } else {
        std::cerr << "Error: loading file failed for blinker_board.txt" << endl;
    }
}

void Application::resetBoard() {
    _board.reset();
}

void Application::generateNextGen() {
    _board.nextGen();
}

void Application::autoNextGen() {
    _board.autoNextGen(); // will run 30 times (hardcoded)
}

