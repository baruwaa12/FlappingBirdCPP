#pragma once
#include <src/include/SDL2/SDL.h>

class Bird {
    public:
    Bird(SDL_Renderer *renderer);
    private:
    SDL_Texture *Bird1;
    SDL_Texture *Bird2;
    SDL_Renderer *renderer;
};