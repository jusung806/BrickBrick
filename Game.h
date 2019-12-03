#ifndef GAME_H
#define GAME_H

#define SDL_MAIN_HANDLED

#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();
	void input();

	bool running() { return isRunning; }
private:
	int counter; //this is just to see it updating on console;
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};
#endif 
