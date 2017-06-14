#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include "globals.h"
#include "tile.h"

class Graphics;
struct SDL_Texture;

class Level
{
public:
	Level();
	Level(std::string mapName, Vector2 spawnPoint, Graphics& graphics);

	~Level();

	void update(int elapsedTime);

	void draw(Graphics& graphics);

private:
	std::string mapName;

	Vector2 spawnPoint;

	Vector2 size;

	SDL_Texture* plainsTexture;

	SDL_Texture* forestTexture;

	SDL_Texture* mountainTexture;


	void loadMap(std::string mapName, Graphics& graphics);

	std::vector<std::vector<Tile>> mapTiles;
};

#endif