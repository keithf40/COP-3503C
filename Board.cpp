//Board.cpp
#include "Board.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

Board::Board(int numRows, int numCols, int numMines, vector<vector<Tile>> boardInput)
{
    _numRows = numRows;
    _numCols = numCols;
    _numMines = numMines;
    board = boardInput;
    _minesRemaining = numMines - _flagCounter;
    //mines = minesInput;
}
