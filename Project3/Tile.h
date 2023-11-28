//Tile.h
#pragma once
#include <iostream>
#include <vector>
#include "TextureManager.h"
using std::string;
using std::vector;

class Tile
{
public:
	sf::Sprite _tileSpriteHidden;
	sf::Sprite _tileSpriteRevealed;
	sf::Sprite _tileSpriteMine;
	sf::Sprite _tileSpriteFlag;
	sf::Sprite _tileBlown;
	sf::Sprite _sprite;
	bool _isRevealed;
	bool _isMine;
	bool _isFlag;
	unsigned int _row;
	unsigned int _column;
	vector<Tile*> _adjacentTiles;
	int _flagCounter = 0;
public:
	Tile(unsigned int row, unsigned int column);
	sf::Sprite& GetSprite();
	void SetPosition(float x, float y);
	void LeftClick();
	void RightClick();
	bool Contains(float x, float y);
};
