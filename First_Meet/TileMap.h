#pragma once

#include <iostream>
#include <vector>


struct Tile
{
	unsigned coordinateX;
	unsigned coordinateY;
};

using TileMatrix = std::vector<std::vector<Tile*>>;

class TileMap
{
public:

	static const unsigned DEFAULT_SIZE = 10;

	TileMap();
	TileMap(unsigned _sizeX, unsigned _sizeY);
	~TileMap();
	
	void Init();

	unsigned GetSizeX() const;
	unsigned GetSizeY() const;
	const TileMatrix& GetTileMap() const;

private:
	unsigned sizeX;
	unsigned sizeY;
	TileMatrix tilemap;
};