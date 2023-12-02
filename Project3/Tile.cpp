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
	_tileSprite1.setTexture(TextureManager::GetTexture("number_1"));
	_tileSprite2.setTexture(TextureManager::GetTexture("number_2"));
	_tileSprite3.setTexture(TextureManager::GetTexture("number_3"));
	_tileSprite4.setTexture(TextureManager::GetTexture("number_4"));
	_tileSprite5.setTexture(TextureManager::GetTexture("number_5"));
	_tileSprite6.setTexture(TextureManager::GetTexture("number_6"));
	_tileSprite7.setTexture(TextureManager::GetTexture("number_7"));
	_tileSprite8.setTexture(TextureManager::GetTexture("number_8"));
	_tileSprite1.setPosition(column * 32.0f, row * 32.0f);
	_tileSprite2.setPosition(column * 32.0f, row * 32.0f);
	_tileSprite3.setPosition(column * 32.0f, row * 32.0f);
	_tileSprite4.setPosition(column * 32.0f, row * 32.0f);
	_tileSprite5.setPosition(column * 32.0f, row * 32.0f);
	_tileSprite6.setPosition(column * 32.0f, row * 32.0f);
	_tileSprite7.setPosition(column * 32.0f, row * 32.0f);
	_tileSprite8.setPosition(column * 32.0f, row * 32.0f);
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
	_sprite.setPosition(x, y);
	_tileSpriteHidden.setPosition(x, y);
	_tileSpriteRevealed.setPosition(x, y);
	_tileSpriteMine.setPosition(x, y);
	_tileSpriteFlag.setPosition(x, y);
	_tileSprite1.setPosition(x, y);
	_tileSprite2.setPosition(x, y);
	_tileSprite3.setPosition(x, y);
	_tileSprite4.setPosition(x, y);
	_tileSprite5.setPosition(x, y);
	_tileSprite6.setPosition(x, y);
	_tileSprite7.setPosition(x, y);
	_tileSprite8.setPosition(x, y);
}

void Tile::LeftClick()
{
	//_neighbors = 8;
	//_neighbors = 
	_isRevealed = true;
}

void Tile::RightClick()
{
	if (!_isRevealed && !_isMine && !_isFlag)
	{
		_isFlag = true;
		_flagCounter++;
	}


	else if (!_isRevealed && _isMine && !_isFlag)
	{
		_isFlag = true;
		_flagCounter++;
	}

	else if (!_isRevealed && !_isMine && _isFlag)
	{
		_isFlag = false;
		_flagCounter--;
	}

	else if (!_isRevealed && _isMine && _isFlag)
	{
		_isFlag = false;
		_flagCounter--;
	}

	else if (_isRevealed && !_isMine && !_isFlag)
		;

	else if (_isRevealed && !_isMine && _isFlag)
		;

	else if (_isRevealed && _isMine && !_isFlag)
		;

	else if (_isRevealed && _isMine && _isFlag)
		;

	//cout << "Flag counter : " << _flagCounter << endl;
}

bool Tile::Contains(float x, float y)
{
	return _tileSpriteHidden.getGlobalBounds().contains(x, y);
	return _tileSpriteRevealed.getGlobalBounds().contains(x, y);
	return _tileSpriteMine.getGlobalBounds().contains(x, y);
	return _tileSpriteFlag.getGlobalBounds().contains(x, y);
	return _tileSprite1.getGlobalBounds().contains(x, y);
	return _tileSprite2.getGlobalBounds().contains(x, y);
	return _tileSprite3.getGlobalBounds().contains(x, y);
	return _tileSprite4.getGlobalBounds().contains(x, y);
	return _tileSprite5.getGlobalBounds().contains(x, y);
	return _tileSprite6.getGlobalBounds().contains(x, y);
	return _tileSprite7.getGlobalBounds().contains(x, y);
	return _tileSprite8.getGlobalBounds().contains(x, y);
}
