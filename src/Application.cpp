#include "Application.h"
#include "Utility.h"
#include <dirent.h>
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
            &Application::loadBoard,
            &Application::saveBoard,
            &Application::resetBoard,
            &Application::generateNextGen,
            &Application::autoNextGen
    };

    int totalMenuOptions = sizeof(menuFunctions) / sizeof(menuFunctions[0]);

    do {
        resp = getUserInput(totalMenuOptions);
        int index = resp - '0'; // Convert char to integer index
        if (index >= 0 && index <= totalMenuOptions && menuFunctions[index]) {
            (this->*menuFunctions[index])();
        } else {
            cout << "Invalid menu option" << endl;
        }
    }while(resp != '0');
}

char Application::getUserInput(int totalOptions) {
    char resp;
    char optionLimit = '0' + (totalOptions - 1);
    bool check;
    Utility::clearScreen();
    do {
        resp = promptBoardMenu();
        if (resp < '0' || resp > optionLimit)
            check = false;
        else
            check = true;
        Utility::clearScreen();
    } while (!check);
    return resp;
}

char Application::promptBoardMenu() {
    char resp;
    std::string options[] {
        "Exit",
        "Draw",
        "Load Blinker+",
        "Load Board",
        "Save Board",
        "Reset",
        "Next",
        "Auto-Run"
    };
    int optionsCount = sizeof(options) / sizeof(options[0]);
    _board.printBoard();
    cout << "Menu Options:\n";
    for (int i = 1; i < optionsCount; i++) {
        cout << "[" << i << "] " << options[i] << " ";
    }
    cout << "[0] " << options[0] <<endl;
    cout << ">>> ";
    cin >> resp;
    cin.ignore(100, '\n');
    return resp;
}

void Application::drawBoard() {
    _board.draw();
}

void Application::loadBlinkerBoard() {
    if (_board.loadBoard("../boards/blinker_plus")) {
        _board.printBoard();
    } else {
        std::cerr << "Error: loading file failed for blinker_board.txt" << endl;
    }
}

void Application::loadBoard() {
    DIR* dir;
    struct dirent* ent;
    std::string fileName;
    std::string directory = "../boards";
    dir = opendir(directory.c_str());
    if(dir != nullptr) {
        cout << "Saved Boards: \n" << endl;
        while((ent = readdir(dir)) != nullptr) {
            if(ent->d_name[0] != '.') {
                cout << ent->d_name <<endl;
            }
        }
        closedir(dir);
        cout << "\n\nEnter a board to load: ";
        getline(cin, fileName);
        if (!_board.loadBoard(fileName)) {
            std::cerr << fileName << " not loaded" << endl;
        }
    } else {
        std::cerr << "Could not open directory: " << directory << endl;
    }
}

void Application::resetBoard() {
    _board.reset();
}

void Application::generateNextGen() {
    _board.nextGen();
}

void Application::autoNextGen() {
    _board.autoNextGen();
}

void Application::exitApplication() {
    cout << "Goodbye!" << endl;
}

void Application::saveBoard() {
    std::string response;
    cout << "Enter a file name for this board: ";
    getline(cin, response);
    if (!_board.saveBoard(response)) {
        std::cerr << response << " not saved" << endl;
    }
}

