//
// Created by jusung on 11/25/19.
//

#ifndef BRICKBRICKBALLV2_ENTITY_H
#define BRICKBRICKBALLV2_ENTITY_H

#include "SDL.h"
#include "SDL_image.h"

class Entity {
public:
    Entity(SDL_Renderer* renderer);
    virtual ~Entity();

    float x, y, width, height;

    virtual void Update(float delta);
    virtual void Render(float delta);

    bool Collides(Entity* other);
protected:
    SDL_Renderer* renderer;

};

#endif //BRICKBRICKBALLV2_ENTITY_H
