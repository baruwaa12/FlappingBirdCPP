#pragma once
#include "application.hpp"
#include "sdlpp.hpp"



class Pipe
{
public:
    Pipe(sdl::Renderer &renderer, sdl::Texture &texture, int y, bool isFacingUP);
    void tick();
    void draw();
private:
    sdl::Renderer &renderer;
    sdl::Texture &texture;
public:
    float x = Application::Width + 128;
    float y:
    bool isPipeFacingUp;
};