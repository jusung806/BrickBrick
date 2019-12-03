#ifndef BRICKBRICKBALLV2_PADDLE_H
#define BRICKBRICKBALLV2_PADDLE_H

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include "Entity.h"


class Paddle : public Entity
{
public:
	Paddle(SDL_Renderer* renderer);
	~Paddle();

	void Update(float delta);
	void Render(float delta);
	bool fireball;

	float dirx;


private:
	SDL_Texture* texture;

};

#endif //BRICKBRICKBALLV2_PADDLE_H
