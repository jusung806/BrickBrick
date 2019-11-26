

//  nano_engine.c
//
//  Created by william herrera
//  Copyright © 2019 william herrera. All rights reserved.
//

#include "nano_engine.h"

SDL_Window *win;
SDL_Renderer *ren;

int Nano_Init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("SDL_Init Error: %s", SDL_GetError());
		return -1;
	}
	return 0;
}

int Nano_PollEvent(Nano_Event *event) {
	return SDL_PollEvent((SDL_Event *)event);
}

int Nano_QuitEvent(Nano_Event *event) {
	SDL_Event *sdl_event = (SDL_Event *)event;
	if (sdl_event->type == SDL_QUIT) {
		return 1;
	}
	return 0;
}

int Nano_KeyDownEvent(Nano_Event *event, int *scancode) {
	SDL_Event *sdl_event = (SDL_Event *)event;
	if (sdl_event->type == SDL_KEYDOWN) {
		*scancode = sdl_event->key.keysym.scancode;
		return 1;
	}
	return 0;
}

