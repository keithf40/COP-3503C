//main.cpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include "TextureManager.h"
#include "Board.h"
#include "Tile.h"
#include <set>
using namespace std;

int main()
{
    //Create window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper");
    
    //Read config file
    int numCols = 0;
    int numRows = 0;
    int numMines = 0;
    ifstream inFile("boards/config.cfg");
    if (inFile.is_open())
    {
        string data;

        getline(inFile, data);
        numCols = stoi(data);
        cout << "Number of columns: " << numCols << endl;

        getline(inFile, data);
        numRows = stoi(data);
        cout << "Number of rows: " << numRows << endl;

        getline(inFile, data);
        numMines = stoi(data);
        cout << "Number of mines: " << numMines << endl;
    }
    
    //Create vector for board with all hidden tiles
    vector<vector<Tile>> board;
    for (int i = 0; i < numRows; i++)
    {
        // new row
        vector<Tile> row;
        for (int j = 0; j < numCols; j++) {
            // new tile for each col
            row.push_back(Tile(i, j));
        }
        board.push_back(row);
    }

    //Create board
    Board realBoard = Board(numRows, numCols, numMines, board);
    
    //Create Random numbers
    const int lowerBound = 0;
    const int upperBound = numRows * numCols - 1;
    const int numberOfRandomIntegers = numMines;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(lowerBound, upperBound);
    std:vector<int> uniqueRandomNumbers;
    while (uniqueRandomNumbers.size() < numberOfRandomIntegers)
    {
        int randomNumber = distribution(generator);
        uniqueRandomNumbers.push_back(randomNumber);
    }

    // Print the generated unique random integers
    std::cout << "Generated unique random integers:" << std::endl;
    for (int number : uniqueRandomNumbers)
        std::cout << number << " ";
    std::cout << std::endl;
    
    
    
    
    
    
    //Set board to random numbers
    int counter = 0;
    int howManyTimes = 0;
    for (int i = 0; i < numRows; i++)
    {
        // new row
        //vector<Tile> row;
        for (int j = 0; j < numCols; j++) {
            // new tile for each col
            for (int k = 0; k < uniqueRandomNumbers.size(); k++) 
                if (uniqueRandomNumbers[k] == counter)
                {
                    realBoard.board[i][j]._isMine = true;
                    howManyTimes++;
                }
                    
                counter++;            
        }
    }

    cout << "Counter: " << counter << endl;
    cout << "Many: " << howManyTimes << endl;

    
    
    
    
    
    
    
    
    
    /*
    //Read in testboard1
    vector<vector<int>> mines;
    mines.resize(numRows, std::vector<int>(numCols));
    ifstream inFile1("boards/testboard1.brd");
    if (inFile1.is_open())
    {
        //int mine = dataChar;
        char dataChar;
        for (int i = 0; i < numRows; i++)
        {         
            // new row
            vector<int> row;
            for (int j = 0; j < numCols; j++) {
                // new tile for each col
                                
                inFile1.get(dataChar);
                //cout << dataChar;
              
                int dataInt = static_cast<int>(dataChar);
                dataInt = dataInt - 48;

                mines[i][j] = dataInt;
                //cout << mines[i][j];
            }
            inFile1.get(dataChar);
            //mines.push_back(row);
        }

        //Print testboard1
        for (size_t i = 0; i < mines.size(); ++i) {
            for (size_t j = 0; j < mines[i].size(); ++j) {
                std::cout << mines[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    //Copy testboard1 into the empty board
    for (int i = 0; i < numRows; i++)
    {
        // new row
        //vector<Tile> row;
        for (int j = 0; j < numCols; j++) {
            // new tile for each col
            if (mines[i][j] == 1)
                realBoard.board[i][j]._isMine = true;
        }
        //board.push_back(row);
    }
    
    */


    //Create spirtes for buttons
    sf::Sprite debug(TextureManager::GetTexture("debug"));
    debug.setPosition(500, 512);
    sf::Sprite test_1(TextureManager::GetTexture("test_1"));
    test_1.setPosition(564, 512);
    sf::Sprite test_2(TextureManager::GetTexture("test_2"));
    test_2.setPosition(628, 512);
    sf::Sprite test_3(TextureManager::GetTexture("test_3"));
    test_3.setPosition(692, 512);
    sf::Sprite face_happy(TextureManager::GetTexture("face_happy"));
    face_happy.setPosition(350, 512);
          
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                auto mousePosition = sf::Mouse::getPosition(window);

                //IF CLICKED TESTBOARD 1 BUTTON
                if ((mousePosition.x > 563 && mousePosition.x < 628)
                    && (mousePosition.y > 512 && mousePosition.y < 576))
                {
                
                    //Read in testboard1
                    vector<vector<int>> mines;
                    mines.resize(numRows, std::vector<int>(numCols));
                    ifstream inFile1("boards/testboard1.brd");
                    if (inFile1.is_open())
                    {
                        //int mine = dataChar;
                        char dataChar;
                        for (int i = 0; i < numRows; i++)
                        {
                            // new row
                            vector<int> row;
                            for (int j = 0; j < numCols; j++)
                            {
                                // new tile for each col

                                inFile1.get(dataChar);
                                //cout << dataChar;

                                int dataInt = static_cast<int>(dataChar);
                                dataInt = dataInt - 48;

                                mines[i][j] = dataInt;
                                //cout << mines[i][j];
                            }
                            inFile1.get(dataChar);
                            //mines.push_back(row);
                        }

                        //Print testboard1
                        for (size_t i = 0; i < mines.size(); ++i)
                        {
                            for (size_t j = 0; j < mines[i].size(); ++j)
                                std::cout << mines[i][j] << " ";
                            std::cout << std::endl;
                        }
                        cout << endl;
                    }

                    //Copy testboard1 into the empty board
                    Board realBoard = Board(numRows, numCols, numMines, board);
                    for (int i = 0; i < numRows; i++)
                    {
                        // new row
                        //vector<Tile> row;
                        for (int j = 0; j < numCols; j++)
                        {
                            // new tile for each col
                            if (mines[i][j] == 1)
                            {
                                realBoard.board[i][j]._isMine = true;
                                realBoard._numMines++;
                            }

                            else
                                realBoard.board[i][j]._isMine = false;

                            realBoard.board[i][j]._isFlag = false;
                            realBoard.board[i][j]._isRevealed = false;
                        }
                    }

                    cout << "Number of mines: " << numMines;
                }




                //IF CLICKED TESTBOARD 2 BUTTON
                if ((mousePosition.x > 627 && mousePosition.x < 692)
                    && (mousePosition.y > 512 && mousePosition.y < 576))
                {

                    //Read in testboard2
                    vector<vector<int>> mines;
                    mines.resize(numRows, std::vector<int>(numCols));
                    ifstream inFile2("boards/testboard2.brd");
                    if (inFile2.is_open())
                    {
                        //int mine = dataChar;
                        char dataChar;
                        for (int i = 0; i < numRows; i++)
                        {
                            // new row
                            vector<int> row;
                            for (int j = 0; j < numCols; j++)
                            {
                                // new tile for each col

                                inFile2.get(dataChar);
                                //cout << dataChar;

                                int dataInt = static_cast<int>(dataChar);
                                dataInt = dataInt - 48;

                                mines[i][j] = dataInt;
                                //cout << mines[i][j];
                            }
                            inFile2.get(dataChar);
                            //mines.push_back(row);
                        }

                        //Print testboard2
                        for (size_t i = 0; i < mines.size(); ++i)
                        {
                            for (size_t j = 0; j < mines[i].size(); ++j)
                                std::cout << mines[i][j] << " ";
                            std::cout << std::endl;
                        }
                        cout << endl;
                    }

                    //Copy testboard2 into the empty board
                    Board realBoard = Board(numRows, numCols, numMines, board);
                    for (int i = 0; i < numRows; i++)
                    {
                        // new row
                        //vector<Tile> row;
                        for (int j = 0; j < numCols; j++)
                        {
                            // new tile for each col
                            if (mines[i][j] == 1)
                                realBoard.board[i][j]._isMine = true;
                            else
                                realBoard.board[i][j]._isMine = false;
                            realBoard.board[i][j]._isFlag = false;
                            realBoard.board[i][j]._isRevealed = false;
                        }
                    }
                    

                }





                //IF CLICKED TESTBOARD 3 BUTTON
                if ((mousePosition.x > 691 && mousePosition.x < 756)
                    && (mousePosition.y > 512 && mousePosition.y < 576))
                {

                    //Read in testboard3
                    vector<vector<int>> mines;
                    mines.resize(numRows, std::vector<int>(numCols));
                    ifstream inFile3("boards/testboard3.brd");
                    if (inFile3.is_open())
                    {
                        //int mine = dataChar;
                        char dataChar;
                        for (int i = 0; i < numRows; i++)
                        {
                            // new row
                            vector<int> row;
                            for (int j = 0; j < numCols; j++)
                            {
                                // new tile for each col

                                inFile3.get(dataChar);
                                //cout << dataChar;

                                int dataInt = static_cast<int>(dataChar);
                                dataInt = dataInt - 48;

                                mines[i][j] = dataInt;
                                //cout << mines[i][j];
                            }
                            inFile3.get(dataChar);
                            //mines.push_back(row);
                        }

                        //Print testboard3
                        for (size_t i = 0; i < mines.size(); ++i)
                        {
                            for (size_t j = 0; j < mines[i].size(); ++j)
                                std::cout << mines[i][j] << " ";
                            std::cout << std::endl;
                        }
                        cout << endl;
                    }

                    //Copy testboard3 into the empty board
                    Board realBoard = Board(numRows, numCols, numMines, board);
                    for (int i = 0; i < numRows; i++)
                    {
                        // new row
                        //vector<Tile> row;
                        for (int j = 0; j < numCols; j++)
                        {
                            // new tile for each col
                            if (mines[i][j] == 1)
                                realBoard.board[i][j]._isMine = true;
                            else
                                realBoard.board[i][j]._isMine = false;
                            realBoard.board[i][j]._isFlag = false;
                            realBoard.board[i][j]._isRevealed = false;
                        }
                    }


                }




                //SMILEY BUTTON
                if ((mousePosition.x > 349 && mousePosition.x < 414)
                    && (mousePosition.y > 512 && mousePosition.y < 576))
                {

                    //Set board to random numbers
                    int counter = 0;
                    int howManyTimes = 0;
                    for (int i = 0; i < numRows; i++)
                    {
                        // new row
                        //vector<Tile> row;
                        for (int j = 0; j < numCols; j++) {
                            // new tile for each col
                            for (int k = 0; k < uniqueRandomNumbers.size(); k++)
                                if (uniqueRandomNumbers[k] == counter)
                                {
                                    realBoard.board[i][j]._isMine = true;
                                    howManyTimes++;
                                }

                            counter++;
                        }
                    }

                    cout << "Counter: " << counter << endl;
                    cout << "Many: " << howManyTimes << endl;
                }









                for (int j = 0; j < numCols; j++)
                {
                        for (unsigned int i = 0; i < numRows; i++)
                        {
                            if (realBoard.board[i][j].Contains(mousePosition.x, mousePosition.y))
                            {
                                realBoard.board[i][j].LeftClick();
                                break;
                            }
                        }
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
            {
                auto mousePosition = sf::Mouse::getPosition(window);
                for (int j = 0; j < numCols; j++)
                {
                    for (unsigned int i = 0; i < numRows; i++)
                    {
                        if (realBoard.board[i][j].Contains(mousePosition.x, mousePosition.y))
                        {
                            realBoard.board[i][j].RightClick();
                            break;
                        }
                    }
                }
            }
        }

        window.clear();

        //Draw board
        for (auto& row : realBoard.board)
        {
            for (auto& tile : row)
            {
                if (tile._isRevealed)
                {
                    window.draw(tile._tileSpriteRevealed);
                }
                else
                {
                    window.draw(tile._tileSpriteHidden);
                }

                if (tile._isMine)
                {
                    window.draw(tile._tileSpriteMine);
                }

                if (tile._isFlag)
                {
                    window.draw(tile._tileSpriteFlag);
                }
            }
        }

        //Draw buttons
        window.draw(debug);
        window.draw(test_1);
        window.draw(test_2);
        window.draw(test_3);
        window.draw(face_happy);

        window.display();
    }

    TextureManager::Clear();

    return 0;
}
