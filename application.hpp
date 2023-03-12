// Pragma - Allows additional information to be added to the compiler.
#pragma once
#include "sdlpp.hpp"

class Application {

public:
    static const auto Width = 900
    static const auto Height = 507
    Application();
    int exec();
private:
    sdl:: Init init;
    sdl:: Window window;
    sdl::Renderer renderer;
}

