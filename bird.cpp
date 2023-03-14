#include "bird.hpp"
#include "loadTexture.hpp"

Bird::Bird(SDL_Renderer *renderer);
    renderer(renderer),
    Bird1("bird_wing_up.bmp"),
    Bird2("bird_wing_down.bmp"),
    {

    }

void Bird::draw()
{
    auto res = SDL_RenderCopy(renderer, bird1, nullptr, nullptr):
}
