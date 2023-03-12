#pragma once
#include "application.hpp"
#include "sdlpp.hpp"


// Pipe
class Pipe
{
    // Shows which functions are private or public within the pipe class
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