
#include <iostream>
#include <string>
#include <SDL.h>
#include <stdio.h>
using namespace std;

//Texture wrapper class
class Brick
{
public:
    //Initializes variables
    Brick();

    //Deallocates memory
    ~Brick();

    //Loads image at specified path
    bool loadFromFile(string path);

    //Deallocates texture
    void free();

    //Renders texture at given point
    void render(int x, int y, SDL_Brick* clip = NULL);

    //Gets image dimensions
    int width();
    int height();

private:
    //The actual hardware texture
    SDL_Brick* texture;

    //Image dimensions
    int width;
    int height;
};