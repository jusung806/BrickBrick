#include <iostream>
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


int main()
{
	GameState gamestate;

	bool isDead = false, gameCompletion = false;
	int lives = 3;
	// double lastTime = getCurrentTime();

	Audio effects;
	effects.load("C:\\Users\\OWNER\\Desktop\\SoundEffectsWav"); //this needs to alway pass in the file path
	effects.play();
	
	do
	{
		//double current = getCurrentTime(); these two functions will keep the game from running to slowly or to quickly between frames of the ball and player moving
		//double elapsed = current - lastTime;
		// processInput(); this function will process user input calls on sub system user input functions -user input(player movement, ball being shot)
		// update(elasped); this funtion should update the input to the system 
		// render(); this should update the system to the screen the ball moving across the screen the player see's this
		//lastTime = current;

		// update(&gamestate); 

		// draw(&gamestate);

	} while (isDead == false || gameCompletion == false);

	system("PAUSE");

	return 0;

}