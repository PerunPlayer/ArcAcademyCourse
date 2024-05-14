
#include "TileMap.h"

TileMap::TileMap()
{
	sizeX = DEFAULT_SIZE;
	sizeY = DEFAULT_SIZE;
	
	Init();
}

TileMap::TileMap(unsigned _sizeX, unsigned _sizeY)
	: sizeX(_sizeX), sizeY(_sizeY)
{
	Init();
}

void TileMap::Init()
{
	tilemap.reserve(sizeX);	// reserving sizeX elements
	for (unsigned i = 0; i < sizeX; ++i)
	{
		std::vector<Tile*> row;
		row.reserve(sizeY);	// reserving sizeY elements
		tilemap.push_back(row);
	}

	for (unsigned i = 0; i < sizeX; i++)
	{
		for (unsigned j = 0; j < sizeY; j++)
		{
			tilemap[i].push_back(new Tile{ i, j });
		}
	}
}

TileMap::~TileMap()
{
	for (unsigned i = 0; i < sizeX; i++)
	{
		for (unsigned j = 0; j < sizeY; j++)
		{
			delete[] tilemap[i][j];		// read about operators 'new', 'delete' and 'delete[]'
		}
	}
}

unsigned TileMap::GetSizeX() const
{
	return sizeX;
}

unsigned TileMap::GetSizeY() const
{
	return sizeY;
}

const TileMatrix& TileMap::GetTileMap() const
{
	return tilemap;
}
