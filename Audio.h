#ifndef AUDIO_H
#define AUDIO_H
#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <SDL_mixer.h>


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

#endif
