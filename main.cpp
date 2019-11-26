#include <iostream>

#define SDL_MAIN_HANDLED

#include <SDL.h>
//#include <SDL_mixer.h>
#include <string>


using namespace std;

class Audio {
public:
	Audio();
	void load(const char* filename);
	void play();
private:
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8* wavBuffer;
	SDL_AudioDeviceID deviceID;
};

Audio::Audio() {
	SDL_CloseAudioDevice(deviceID);
	SDL_FreeWAV(wavBuffer);
}

void Audio::load(const char* filename)
{
	if (SDL_LoadWAV(filename, &wavSpec, &wavBuffer, &wavLength) == NULL)
	{
		return;
	}
		SDL_LoadWAV(filename, &wavSpec, &wavBuffer, &wavLength);
		deviceID = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);

	
}

void Audio::play()
{
	SDL_QueueAudio(deviceID, wavBuffer, wavLength);
	SDL_PauseAudioDevice(deviceID, 0);
}

// test program 

class GameState {
public:
	float player_x, player_y; //need to add more here
};

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
	switch (event.type) {
	case SDL_QUIT: 
			isRunning = false;
			break;

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

void Game::input() {

}

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

			//double current = getCurrentTime(); these two functions will keep the game from running to slowly or to quickly between frames of the ball and player moving
			//double elapsed = current - lastTime;
			// processInput(); this function will process user input calls on sub system user input functions -user input(player movement, ball being shot)
			// update(elasped); this funtion should update the input to the system 
			// render(); this should update the system to the screen the ball moving across the screen the player see's this
			//lastTime = current;

			// update(&gamestate); 

			// draw(&gamestate);

	}

	game->clean();

	return 0;

}