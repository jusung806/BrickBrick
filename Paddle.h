

#ifndef BRICKBRICKBALLV2_PADDLE_H
#define BRICKBRICKBALLV2_PADDLE_H

#include "Entity.h"
#include <math.h>

class Paddle: public Entity {
public:
    Paddle(SDL_Renderer* renderer);
    ~Paddle();

    void Update(float delta);
    void Render(float delta);

private:
    SDL_Texture* texture;
};

#endif //BRICKBRICKBALLV2_PADDLE_H
