//Board.h
#pragma once
#include "TextureManager.h"
#include "Tile.h"
#include "Random.h"
#include <vector>
using std::vector;

class Board
{
public:
	int _numRows;
	int _numCols;
	int _numMines;
	vector<vector<Tile>> board;
	vector<vector<int>> mines;
	int _flagCounter = 0;
	int _minesRemaining;
public:
	Board(int numRows, int numCols, int numMines, vector<vector<Tile>> boardInput);
};
