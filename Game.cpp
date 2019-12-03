
#define SDL_MAIN_HANDLED

#include <iostream>
#include <String>
#include "SDL.h"
#include "SDL_image.h"
#include "game.h"

using namespace std;

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Subsystems Initialised!..." << endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			cout << "Window created!" << endl;

		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "Renderer created!" << endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

		/*
		  case SDL_SCANCODE_RIGHT:
			  rect.x += 1; // this should be changed to
			  paddle.dirx+=1;
			  break;
		  case SDL_SCANCODE_LEFT:
			  rect.x -= 1; //this should be changed to
			  paddle.dirx-=1;
			  break;
		  case SDL_SCANCODE_KP_SPACE
				  this should be gamestate.player1.fireball = true;
				  break;
		*/


	default:
		break;
	}
}

void Game::update() {
	counter++;  //will delete later this is where the player will be updated
	cout << counter << endl;
}

void Game::render() {
	SDL_RenderClear(renderer);
	// this is where we would add stuff to render
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleaned" << endl;
}

void Game::input()
{

}
