#include <SDL2/SDL.h>
#include "level.h"
#include "graphics.h"


Level::Level() {}

Level::Level(std::string mapName, Vector2 spawnPoint, Graphics& graphics) :
			 mapName(mapName), spawnPoint(spawnPoint), size(Vector2(0,0))
{
	loadMap(mapName, graphics);
}

Level::~Level()
{

}

void Level::loadMap(std::string mapName, Graphics& graphics)
{
	plainsTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(),
					  graphics.loadImage("content/backgrounds/bkBlue.png"));
	forestTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(),
					  graphics.loadImage("content/backgrounds/bkMaze.png"));
	mountainTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(),
					  graphics.loadImage("content/backgrounds/bkGreen.png"));
	size = Vector2(1280, 960);

	int mapWidth = size.x / 64;
	int mapHeight = size.y / 64;

	srand(time(NULL));

	for (int x = 0; x < mapWidth; x++)
	{
		std::vector<Tile> column;

		for (int y = 0; y < mapHeight; y++)
		{
		
			Tile t = Tile();
			column.push_back(t);
		}

		mapTiles.push_back(column);
	}
}

void Level::update(int elapsedTime)
{

}

void Level::draw(Graphics& graphics)
{
	int rectSize = 64;

	SDL_Rect sourceRect = {0, 0, rectSize, rectSize};
	SDL_Rect destRect;

	int x = 0;
	
	for(std::vector<Tile> column : mapTiles)
	{
		int y = 0;
		for(Tile t : column)
		{
			//Draw a rectangle at x/y * 64
			destRect.x = x * rectSize;
			destRect.y = y * rectSize;
			destRect.w = rectSize;
			destRect.h = rectSize;
			if(t.terrain == PLAINS)
			{
				graphics.blitSurface(plainsTexture, &sourceRect, &destRect);
			}
			else if(t.terrain == FOREST)
			{
				graphics.blitSurface(forestTexture, &sourceRect, &destRect);
			}
			else if(t.terrain == MOUNTAIN)
			{
				graphics.blitSurface(mountainTexture, &sourceRect, &destRect);
			}
			y++;
		}
		x++;
	}
}