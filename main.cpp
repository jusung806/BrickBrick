#include <iostream>

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include "SDL_image.h"
#include "Paddle.h"
#include "Ball.h"
#include "Audio.h"
#include "Tile.h"
#include "Entity.h"
#include "game.h"
#include <SDL_mixer.h>
#include <string>

using namespace std;

// test program 

class GameState {
public:
	float player; //need to add more here
	// wouldn't this be connected to paddle, like this?
};


Game *game = nullptr;

int main()
{
	GameState gamestate;

	game = new Game();

	game->init("Brick Breaker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	//bool isDead = false, gameCompletion = false;
	//int lives = 3;
	// double lastTime = getCurrentTime();

	static int lastTime;
	int frameCount, lastFrame;

	//Audio effects;
	//effects.load("doh.wav"); //this needs to alway pass in the file path
	//effects.play();

	while (game->running())
	{
		lastFrame = SDL_GetTicks();
		if (lastFrame >= (lastTime + 1000)) {
			lastTime = lastFrame;
			frameCount = 0;
		}

		//game->input();
		game->handleEvents(); // i think this is input


		game->update();


		game->render();

	}

	game->clean();

	return 0;

}
