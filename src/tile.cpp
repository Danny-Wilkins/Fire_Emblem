#include <SDL2/SDL.h>
#include "level.h"
#include "tile.h"
#include <iostream>

Tile::Tile()
{
	terrain = static_cast<Terrain>(rand() % 3);
	std::cout << terrain << std::endl;
}

Tile::~Tile()
{

}