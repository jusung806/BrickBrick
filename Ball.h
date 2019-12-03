#ifndef BRICKBRICKBALLV2_BALL_H
#define BRICKBRICKBALLV2_BALL_H

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include "Entity.h"
#include "Paddle.h"

#include <math.h>

// Define a ball speed in pixels per second
const float BALL_SPEED = 550;

class Ball : public Entity
{
public:
	Ball(SDL_Renderer* renderer);
	~Ball();

	void Update(float delta);
	void Render(float delta);

	void SetDirection(float dirx, float diry, const Paddle &paddle);

	float dirx, diry;




private:
	SDL_Texture* texture;

};


#endif //BRICKBRICKBALLV2_BALL_H
