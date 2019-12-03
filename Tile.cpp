#include "Tile.h"
#include <string>
#include <SDL.h>
#include <stdio.h>
#include <fstream>

bool loadBrick(Tile* tiles[]);

// Sets tiles from tile map
bool setTiles(Tile *tiles[]);

Tile::Tile(int x, int y, int tileType)
{
	// Get the offsets
	mBox.x = x;
	mBox.y - y;

	// Set the Collision Box
	mBox.w = Tile_Width;
	mBox.h = Tile_Height;

	// Get the tile type
	mtype = tileType;
}

void Tile::render(SDL_Rect)
{
	// If the tile is on screen
	if (checkCollision(camera, mBox))
	{
		// Show the tile
		gTileTexture.render(mBox.x - mBox.y - &gTileClips[mType]);
	}
}

int Tile::getType()
{
	return mTypes;
}

SDL_Rect Tile::getBox()
{
	return mBox;
}

bool loadBrick(Tile* tiles[])
{
	// Loading success flag
	bool success = true;

	// Load tile texture
	if (!gTileTexture.load("healthy_brick"))
	{
		printf("Failed to load healthy brick!\n");
		success = false;
	}
	if (!gTileTexture.load("damaged_brick"))
	{
		printf("Failed to load damaged brick!\n");
		success = false;
	}
	if (!gTileTexture.load("broken_brick"))
	{
		printf("Failed to load broken brick!\n");
		success = false;
	}

	// Load tile Map
	if (!setTiles(tiles))
	{
		printf("Failed to load tile set!\n");
		success = false;
	}

	return success;
}

bool setTiles(Tile* tiles[])
{
	// Success Flag
	bool tilesLoaded = true;

	// Tile offsets
	int x = 0;
	int y = 0;

	// Open the Map
	std::ifstream map("BrickBreaker.map");

	// If the map couldn't load
	if (map.fail())
	{
		printf("Unable to load map file!\n");
		tilesLoaded = false;
	}
	else
	{
		// Initialize the tiles
		for (int i = 0; i < Total_Tiles; i++)
		{
			// Determines what kind of tile will be made
			int tileType = -1;

			// Read tile from map file
			map >> tileType;

			// If the was a problem in reading the map
			if (map.fail())
			{
				// Stop Loading Map
				printf("Error loading map: End of File!\n");
				tilesLoaded = false;
				break;
			}

			// If the number is a valid tile number
			if ((tileType >= 0) && (tileType < Total_Tile_Sprites))
			{
				tiles[i] = new Tile(x, y, tileType);
			}
			// If we don't recognize the tile type
			else
			{
				// Stop loading map
				printf("Error loading map: Invalid tile type at %d!\n", i);
				tilesLoaded = false;
				break;
			}
			// Move to the next tile spot
			x += Tile_Width;

			// If we have gone too far
			if (x >= Level_Width)
			{
				// Move back
				x = 0;

				// Move to the next row
				y += Tile_Height;
			}
		}
		// Clip the Sprite sheet
		if (tileLoaded)
		{
			gTileClips[Tile_Empty].x = 0;
			gTileClips[Tile_Empty].y = 0;
			gTileClips[Tile_Empty].w = TILE_WIDTH;
			gTileClips[Tile_Empty].h = TILE_HEIGHT;

			gTileClips[Tile_Broken].x = 0;
			gTileClips[Tile_Broken].y = 25;
			gTileClips[Tile_Broken].w = TILE_WIDTH;
			gTileClips[Tile_Broken].h = TILE_HEIGHT;

			gTileClips[Tile_Damaged].x = 0;
			gTileClips[Tile_Damaged].y = 50;
			gTileClips[Tile_Damaged].w = TILE_WIDTH;
			gTileClips[Tile_Damaged].h = TILE_HEIGHT;

			gTileClips[Tile_Healthy].x = 0;
			gTileClips[Tile_Healthy].y = 75;
			gTileClips[Tile_Healthy].w = TILE_WIDTH;
			gTileClips[Tile_Healthy].h = TILE_HEIGHT;
		}
	}
	// If the map was loaded fine
	return tilesLoaded;
}
