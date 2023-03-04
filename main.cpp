// Import SDL and Standard IO

#include <SDL2/SDL.h>
#include <stdio.h>

// These are the dimensions of the window 
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


// Game Loop

int main ( int argc, char* args[] )
{
    // Window that we are rendering to
    SDL_Window* window = NULL;

    // The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        // Create the window
        window = SDL_CreateWindow("FlappyBirdSDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if ( window == NULL )
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError() );

        }
        else
        {
            // Get Window Surface
            screenSurface = SDL_GetWindowSurface(window);

            // This fills the surface with white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface -> format, 0xFF, 0xFF, 0xFF) );

            // Update the surface
            SDL_UpdateWindowSurface( window );

            // Trick to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ) { while (SDL_PollEvent( &e ) ){ if (e.type == SDL_QUIT) quit = true; } }
        }
    }

    // Destroys the window 
    SDL_DestroyWindow( window );

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}



