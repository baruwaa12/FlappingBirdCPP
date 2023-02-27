#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *args[])
{

  // This line renders the window to the screen
  SDL_Window *window = NULL;

  // The surface which is held by the window
  SDL_Surface *screenSurface = NULL;

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
  }
  else
  {
    // Create window
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
      std::cout << "Window Created!\n";

      // Get the window surface
      screenSurface = SDL_GetWindowSurface(window);

      // This fills the surface with white
      SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

      // Update the surface window
      SDL_UpdateWindowSurface(window);

      // Trick to get the window to stay open
      SDL_Event e;
      bool quit = false;
      while (quit == false)
      {
        while (SDL_PollEvent(&e))
        {
          if (e.type == SDL_QUIT)
            quit = true;
        }
      }
    }
  }

  // Destroy the window to free up memory
  SDL_DestroyWindow(window);

  // Quit SDL subsystems
  SDL_Quit();

  return 0;
}