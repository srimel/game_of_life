#include <unistd.h>
#include <iostream>
#include "Board.h"
#include "Cell.h"
#include "Application.h"

using std::cout;
using std::endl;
using std::cin;

Board::Board(int r, int c): row(r), col(c) {
	board = new Cell * [row];
	for(int i = 0; i < row; i++) {
		board[i] = new Cell[col];
    }
}

Board::Board(const Board & src) {
    row = src.row;
    col = src.col;
    board = new Cell * [row];
    for(int i = 0; i < row; i++) {
        board[i] = new Cell[col];
        for(int j = 0; j < col; ++j) {
            board[i][j].setLife(src.board[i][j].isAlive());
        }
    }
}

Board::~Board() {
	for(int i = 0; i < row; i++) {
		delete [] board[i];
	}
	delete [] board;
}

void Board::setState(int r, int c, bool x) {
    if(r >= row || c >= col) {
        cout <<"Error: Out of array bounds\n";
        return;
    }
	board[r][c].setLife(x);
}

void Board::printColNum() const {
    cout <<"   |";
    for(int j {0}; j < col; ++j) {
        if(j < 10)
            cout <<" " << j <<" |";
        else
            cout <<" " << j <<"|";
    }
    cout <<'\n';
}

void Board::printBoard() {
    printColNum();
	printHorizontalLine();
	for(int i {0}; i < row; ++i) {
        cout <<i <<": ";
		for(int j {0}; j < col; ++j) {
			if(j == 0) cout <<'|';
			if(board[i][j].isAlive())
				cout <<" ■ ";
			else
				cout <<"   ";
            cout <<'|';
        }
        cout <<'\n';
        printHorizontalLine();
    }
}

void Board::printHorizontalLine() const {
    cout  <<"   "; // offest space accounts for numbering of each row.
	for(int q {0}; q < ((col * 4) + 1); q++) {
		cout <<'-';
	}
	cout <<'\n';
}

void Board::setupBoard() {
    char response = 'n';
    int x = 0, y = 0;
    Application::clearScreen();
    do {
        cout <<"Let's set up the board for Conway's Game of Life!\n" <<endl;
        printBoard();
        cout <<"Enter coordinates of a cell you want to birth (e.g. row <space> column <enter>) " <<endl;
        cout <<">>> ";
        cin >> x;
        cin >> y;
        setState(x,y,true);
        cin.ignore(100, '\n');
        Application::clearScreen();
        cout <<"Let's set up the board for Conway's Game of Life!\n" <<endl;
        printBoard();
        cout <<"Would you like to enter another cell? (y/n): ";
        cin >> response;
        Application::clearScreen();
    }while( tolower(response) != 'n');
    cout <<"Initial State of Board:\n" <<endl;
    printBoard();
    updateNeighbors();
}

// Able to load special configuration files where each line in external file is a 2-pair tuple
// indicating row and column position separated by a comma and each tuple sepated by a newline.
bool Board::loadConfig(std::string fileName) {
    std::ifstream fin;
    fin.open(fileName);
    if(!fin) {
        std::cerr <<"File could not be opened" <<endl;
        return false;
    }
    else {
        reset();
        while(!fin.eof()) {
            int x, y;
            fin >> x;
            fin.ignore(100,',');
            fin >> y;
            fin.ignore(100,'\n');
            cout <<"X: " <<x <<" Y: " <<y <<endl;
            setState(x, y, true);
        }
        fin.close();
        updateNeighbors();
        return true;
    }
}

bool Board::saveBoard(std::string fileName) {
    std::ofstream fout;
    fout.open(fileName);
    if(!fout) {
        std::cerr <<"Error opening save file:" << fileName <<endl;
        return false;
    }
    else {
        for (int i{0}; i < row; ++i) {
            for (int j{0}; j < col; ++j) {
                fout << board[i][j].isAlive() << ',';
            }
            fout << '\n';
        }
        fout.close();
        return true;
    }
}

bool Board::loadBoard(std::string fileName) {
    std::ifstream fin;
    fin.open(fileName);
    if(!fin) {
        std::cerr <<"Error opening file!\n";
        return false;
    }
    else {
        for(int i {0}; i < row && !fin.eof(); ++i) {
            bool life {false};
            for(int j {0}; j < col && !fin.eof(); ++j) {
                fin >> life;
                fin.ignore(100,',');
                board[i][j].setLife(life);
            }
            fin.ignore(100,'\n');
        }
        fin.close();
        updateNeighbors();
        return true;
    }
}

void Board::draw() {
    char response;
    do {
        std::string fn;
        setupBoard();
        cout << "Would you like to save this board? [y/n]: ";
        cin >> response;
        cin.ignore(100, '\n');
        if (tolower(response) == 'y') {
            cout << "Enter filename to save as: ";
            cin >> fn;
            cin.ignore(100,'\n');
            if(saveBoard(fn))
                cout <<fn <<" was successfully saved!" <<endl;
            else
                cout <<"Error: not saved" <<endl;
            response = 'n';
        }
    }while(tolower(response) != 'n');
}

void Board::reset() {
    for(int i {0}; i < row; ++i) {
       for(int j {0}; j < col; ++j) {
           board[i][j].setLife(false);
       }
    }
}

void Board::nextGen() {
    // board containing next generation
    Cell ** hold = getNextGen();
    // delete current board
    for(int i {0}; i < row; ++i) {
        delete [] board[i];
    }
    delete [] board;

    // update this board
    this->board = hold;
    updateNeighbors();
}

Cell ** Board::getNextGen() {
    // Make a new board to update with changes (allocates memory)
    Cell ** temp = new Cell *[row];
    for(int i {0}; i < row; ++i) {
        temp[i] = new Cell[col];
    }
    for(int i {0}; i < row; ++i) {
        for(int j {0}; j < col; ++j) {
            int n = board[i][j].getNeighbors();
            if(board[i][j].isAlive() ) {                // survival rules
                if((n > 1) && (n < 4))
                    temp[i][j].setLife(true);
            } else {
                if(n == 3) {                            // birth rule
                    temp[i][j].setLife(true);
                } else {                                // current cell is dead and remains so.
                    temp[i][j].setLife(false);
                }
            }
        }
    }
    return temp;
}

void Board::updateNeighbors() {
    for(int i {0}; i < row; ++i) {
        for(int j {0}; j < col; ++j) {
            int n{0}, w{0}, e{0}, s{0}, nw{0}, ne{0}, sw{0}, se{0}, sum{0};
            // check north, northwest, northeast
            if(i != 0) {
                n = board[i-1][j].isAlive();
                if(j != 0) {
                    nw = board[i-1][j-1].isAlive();
                }
                if(j != (col-1)) {
                    ne = board[i-1][j+1].isAlive();
                }
            }
            // check west
            if(j != 0) {
                w = board[i][j-1].isAlive();
            }
            // check east
            if(j != (col-1)) {
                e = board[i][j+1].isAlive();
            }
            // check south, southwest, southeast
            if(i != (row-1)) {
                s = board[i+1][j].isAlive();
                if(j != 0) {
                    sw = board[i+1][j-1].isAlive();
                }
                if( j != (col-1)) {
                    se = board[i+1][j+1].isAlive();
                }
            }
            sum = n + w + e + s + nw + ne + sw + se;
            board[i][j].setNeighbors(sum);
        }
    }
}

void Board::autoNextGen() {
    for(int i {0}; !isZero(); i++) {
        cout << "Generation: " << i+1 << endl;
        nextGen();
        printBoard();
        usleep(500000); // need micro-sec?
        Application::clearScreen();
    }
}

bool Board::isZero() {
    int result = 0;
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
           if(board[i][j].isAlive())
               return false;
        }
    }
    return true;
}

// TODO: use this for stopping auto generate when board doesn't change on update
bool Board::operator==(Cell ** other_board) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // TODO: overload != operator for Cell class
            //if (board[i][j] != other_board[i][j]) { return false; }
        };
    }
    return false;
}