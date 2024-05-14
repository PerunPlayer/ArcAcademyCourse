
#include <iostream>

#include "TileMap.h"

int main()
{
    TileMap map(3, 5);
    for (const auto& row : map.GetTileMap())
    {
        for (const Tile* tile : row)
        {
            std::cout << tile->coordinateX << " " << tile->coordinateY << std::endl;
        }
    }
}
