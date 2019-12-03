ifndef TILE_H
#define TILE_H

#include <string>
#include <SDL.h>
#include <stdio.h>
#include <fstream>

// Screen Dimension constants
const int Screen_Width = 600;
const int Screen_Height = 400;

// The dimensions of the level
const int Level_Width = 1000;
const int Level_Height = 800;

// Tile Constants
const int Tile_Width = 25;
const int Tile_Height = 25;
const int Total_Tiles = 40;
const int Total_Tile_Sprites = 12;

// Different tile sprites
const int Tile_Empty = 0;
const int Tile_Broken = 1;
const int Tile_Damaged = 2;
const int Tile_Healthy = 3;

// Tile
class Tile
{
public:
	Tile(int x, int y, int tileType);

	// Show the tile
	void render(SDL_Rect);

	// Get the tile
	int getType();

	// collision box;
	SDL_Rect getBox();

private:
	// attributes of the tiles
	SDL_Rect mBox;

	// Tile type
	int mType;
};

#endif
