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
    cout << "new board created" << endl;
}

vector<Tile*> Board::getNeighbors(Tile& tile) {

    vector<Tile* > neighbors;
    //    cout << tile._row << endl;
        // has top neighbors
    if (tile._row > 0) {

        // has top left
        if (tile._column > 0) {
            neighbors.push_back(&board[tile._row - 1][tile._column - 1]);
        }

        // top neighbor
        neighbors.push_back(&board[tile._row - 1][tile._column]);

        // top right neighbor
        if (tile._column < _numCols - 1) {
            neighbors.push_back(&board[tile._row - 1][tile._column + 1]);
        }

    }

    // left neighbor
    if (tile._column > 0) {
        neighbors.push_back(&board[tile._row][tile._column - 1]);
    }

    // right neighbor
    if (tile._column < _numCols - 1) {
        neighbors.push_back(&board[tile._row][tile._column + 1]);
    }

    // has bottom neighbors
    if (tile._row < _numRows - 1) {

        // has bottom left
        if (tile._column > 0) {
            neighbors.push_back(&board[tile._row + 1][tile._column - 1]);
        }

        // bottom neighbor
        neighbors.push_back(&board[tile._row + 1][tile._column]);

        // bottom right neighbor
        if (tile._column < _numCols - 1) {
            neighbors.push_back(&board[tile._row + 1][tile._column + 1]);
        }

    }


    return neighbors;

}

void Board::recursiveCheckNeighbors(Tile& tile) {
    auto neighbors = getNeighbors(tile);

    int count = 0;
    for (auto& neighbor : neighbors)
    {
        if (neighbor->_isMine) {
            count++;
        }
    }

    // update tile with number of mines touching it
    tile._neighbors = count;


    if (count == 0) {
        for (auto& neighbor : neighbors) {
            if (!neighbor->_isRevealed && !neighbor->_isMine && !neighbor->_isFlag && !tile._isMine) {
                neighbor->LeftClick();
                recursiveCheckNeighbors(*neighbor);
            }
        }
    }


    /* else if (count == 1) {
         tile._tileSpriteRevealed = tile._tileSprite1;
     }
     else if (count == 2)
         tile._tileSpriteRevealed = tile._tileSprite2;
     else if (count == 3)
         tile._tileSpriteRevealed = tile._tileSprite3;
     else if (count == 4)
         tile._tileSpriteRevealed = tile._tileSprite4;
     else if (count == 5)
         tile._tileSpriteRevealed = tile._tileSprite5;
     else if (count == 6)
         tile._tileSpriteRevealed = tile._tileSprite6;
     else if (count == 7)
         tile._tileSpriteRevealed = tile._tileSprite7;
     else if (count == 8)
         tile._tileSpriteRevealed = tile._tileSprite8;*/
}
