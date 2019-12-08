
#include "Game.h"

SDL_Brick newSDL_Brick(int x, int y, int widths, int heights)
{
    SDL_Brick brick;
    brick.x = x;
    brick.y = y;
    brick.w = widths;
    brick.h = heights;
    return brick;
}
int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) //Init the video driver
    {
        printf("SDL_Error: %s\n", SDL_Error());
    }
    else
    {
        if (window == NULL)
        {
            printf("SDL_Error: %s\n", SDL_Error());
        }
        else
        {
            SDL_Renderer* renderer = NULL;
            renderer = SDL_CreateRenderer(window, 0, SDL_Renderer_Accelerated); //renderer used to color brick

            SDL_RenderColor(renderer, 153, 255, 102); //Color: #99ff66
            SDL_RenderClear(renderer);

            for (int i = 0; i < 14; i++)
                for (int j = 0; j < 12; j++)
                {
                    brick[i][j] = newSDL_Brick(20 + i * 42, 20 + j * 42, 40, 40);
                    SDL_RenderColor(renderer, 255, 102, 153); //Color: #ff6699
                    SDL_RenderFillBrick(renderer, &brick[i][j]);
                }
            SDL_UpdateWindow(window);
        }
    }
    SDL_DestroyWindow(window);
    return 0;
}

SDL_Brick newSDL_Brick(int x, int y, int widths, int heights)
{
    SDL_Brick brick;
    brick.x = x;
    brick.y = y;
    brick.w = widths;
    brick.h = heights;
    return brick;
}