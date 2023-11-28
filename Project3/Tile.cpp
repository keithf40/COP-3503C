//Tile.cpp
#include "Tile.h"
#include "Board.h"
using namespace std;

Tile::Tile(unsigned int row, unsigned int column)
{
	_sprite.setTexture(TextureManager::GetTexture("tile_hidden"));
	_tileSpriteHidden.setTexture(TextureManager::GetTexture("tile_hidden"));
	_tileSpriteRevealed.setTexture(TextureManager::GetTexture("tile_revealed"));
	_tileSpriteMine.setTexture(TextureManager::GetTexture("mine"));
	_tileSpriteFlag.setTexture(TextureManager::GetTexture("flag"));
	_isRevealed = false;
	_isMine = false;
	_isFlag = false;
	_row = row;
	_column = column;
	_sprite.setPosition(column * 32.0f, row * 32.0f);
	_tileSpriteHidden.setPosition(column * 32.0f, row * 32.0f);
	_tileSpriteRevealed.setPosition(column * 32.0f, row * 32.0f);
	_tileSpriteMine.setPosition(column * 32.0f, row * 32.0f);
	_tileSpriteFlag.setPosition(column * 32.0f, row * 32.0f);
}

sf::Sprite& Tile::GetSprite()
{
	if (_isRevealed)
		return _tileSpriteRevealed;
	else if (_isMine)
		return _tileSpriteMine;
	else if (_isFlag)
		return _tileSpriteFlag;
	else
		return _tileSpriteHidden;
}

void Tile::SetPosition(float x, float y)
{
	_tileSpriteHidden.setPosition(x, y);
	_tileSpriteRevealed.setPosition(x, y);
	_tileSpriteMine.setPosition(x, y);
	_tileSpriteFlag.setPosition(x, y);
}

void Tile::LeftClick()
{
	if (!_isFlag && !_isMine)
		_isRevealed = !_isRevealed;
	else if (!_isFlag && _isMine)
		_tileSpriteHidden = _tileSpriteMine;
}

void Tile::RightClick()
{
	if (!_isFlag)
		_flagCounter++;
	else if (_isFlag)
		_flagCounter--;
	//if (_tileSpriteHidden = _tileSpriteMine)
		_isFlag = !_isFlag;
	cout << "Flag counter : " << _flagCounter << endl;
}

bool Tile::Contains(float x, float y)
{
	return _tileSpriteHidden.getGlobalBounds().contains(x, y);
	return _tileSpriteRevealed.getGlobalBounds().contains(x, y);
	return _tileSpriteMine.getGlobalBounds().contains(x, y);
	return _tileSpriteFlag.getGlobalBounds().contains(x, y);
}
