#include "loadTexture.hpp"
#include <stdexcept>

SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *filename)
{
    auto surface = SDL_LoadBMP(filename);
    if (!surface)
    {
        throw std::runtime_error(std::string("SDL_LoadBMP(") + fileName + "): " + SDL_GetError());
    }
    auto result = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return result;
}