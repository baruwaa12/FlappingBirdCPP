
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

// Dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


// Start up SDL and creates window
bool init();

// Load the media
bool loadMedia();

// Stops the media and shuts down SDL
void close();

// The window we will be rendering to
SDL_Window * gWindow = NULL;

// The surface contained by the window
SDL_Surface * gScreenSurface = NULL;

// The image we will load and show on the screen
SDL_Surface * gStretchedSurface = NULL;

bool init() {

    // Initialisation flag - (checks whether an action or variable has been initalized or not)
    bool success = true;

    // Initialise SDL
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        // If SDL cannot be initialised throw SDL error and set initialisation flag to false
        printf( "SDL could not be initialised!  SDL_Error: %s\n", SDL_GetError() );
        success = false;

    }
    else {

        // Create the window and express that you dont care about the window position on screen
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN );
        if ( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;

        }
        else
        {
            // Get the window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }

    }

    return success;

}

bool loadMedia()
{
    // Loading success flag
    bool success = true;

    gStretchedSurface = loadSurface( "05_optimized_surface_loading_and_soft_stretching/stretch.bmp" );
    if ( gStretchedSurface == NULL )
    {
        printf( "Failed to load stretching image! \n");
        success = false;
    }
    
    return success;
}


void close()
{
    // Deallocate the resources used to create the surface
    SDL_FreeSurface( gStretchedSurface );
    gStretchedSurface = NULL;

    // Destroy the window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    // Exit the SDL subsystem
    SDL_Quit();

}

SDL_Surface* loadSurface( std:: string path)
{

    // The final optimzed image
    SDL_Surface* optimzedSurface = NULL;


    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str()));
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }
    else
    {

        // Conver the surface to a screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface -> format, 0 );
        if ( optimizedSurface == NULL )
        {
            printf( "Unable to optimze image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        SDL_FreeSurface( loadedSurface );

    }

    return optimizedSurface;

} 





int main ( int argc, char* args[ ])
{
    // Start up SDL and create the window
    if (!init() )
    {
        printf( "Failed to initialise! \n");
    }
    else{

        // Load the media
        if ( !loadMedia() )
        {
            printf( "Failed to load the media! \n");
        }
        else
        {
            // Main loop flag - determines whether the user has quit or not 
            bool quit = false;

            // Event handler
            SDL_Event e;

            // Do this while the app is running
            while( !quit )
            {

                // Handle events on queue
                while( SDL_PollEvent ( &e ) != 0)
                {
                    // User request to quit
                    if ( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }

                 }

                 SDL_Rect stretchRect;
                 stretchRect.x = 0
                 stretchRect.y = 0
                 stretchRect.w = SCREEN_WIDTH;
                 stretchRect.h = SCREEN_HEIGHT;
                 SDL_BlitSCaled( gStretchedSurface, NULL, gScreenSurface, &stretchRect );

                 // Update the surface
                 SDL_UpdateWindowSurface( gWindow );
                 


    // Free the resources and close SDL down refers to previous writtten function
    close();

    return 0;
}