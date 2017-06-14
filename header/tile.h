#ifndef TILE_H
#define TILE_H

#include "player.h"

#include <stdlib.h>
#include <time.h>

/*
 * Tiles are an object, a "square" on the map that hold data about the terrain, players, and enemies.	
 * The appearance of a tile will vary depending on the terrain.
 * A tile can hold one Player OR Enemy.
 */

 enum Terrain
 {
 	DESERT = 0,
 	PLAINS = 0,
 	FOREST = 1,
 	MOUNTAIN = 2
 };

struct Tile
{
	Tile();

	~Tile();

	Player* occupied_by;

	int terrain;
};

#endif