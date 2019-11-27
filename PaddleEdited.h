

#ifndef BRICKBRICKBALLV2_PADDLE_H
#define BRICKBRICKBALLV2_PADDLE_H

class Paddle : public Entity {
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