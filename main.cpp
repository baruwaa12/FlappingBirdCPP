
#include <SD2/SDL.h>
#include <stdio.h>


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
SDL_Surface * gHelloWorld = NULL;

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

    // Load the default surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "04_key_presses/press.bmp");
    if (gKeyPressSurfaces [ KEY_PRESS_SURFACE_DEFAULT] == NULL )

    {
        printf("Failed to load default image! \n");
        success = false;
    }

    // Load up the surface 
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface( "04_key_presses/up.bmp" );
    if ( gKeyPressSurfaces [ KEY_PRESS_SURFACE_DEFAULT ] == NULL )
    {
        printf( "Failed to load default image! \n ");
        success = false;
    }

    gKeyPressSurfaces [ KEY_PRESS_SURFACE_DOWN ] = loadSurface( "04_key_presses/down.bmp");
    if (gKeyPressSurfaces [KEY_PRESS_SURFACE_DOWN ] == NULL )
    {
        printf( "Failed to load down image! \n ");
        success = false;
    }

    gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( "04_key_presses/right.bmp");
    if (gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
    {
        printf("Failed to load right image! \n ");
        sucess = false;
    }

    gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface( "04_key_presses/left.bmp");
    if (gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
    {
        printf("Failed to load right image! \n ");
        sucess = false;
    }


    // 
    
    return success;
}


void close()
{
    // Deallocate the resources used to create the surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    // Destroy the window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    // Exit the SDL subsystem
    SDL_Quit();

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

                    // User presses a key 
                    else if (e.type == SDL_KEYDOWN )
                    {
                        // Select surfaces based on key press
                        switch( e.key.keysym.sym )
                        {
                            case SDLK_UP:
							gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
							break;

							case SDLK_DOWN:
							gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
							break;

							case SDLK_LEFT:
							gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
							break;

							case SDLK_RIGHT:
							gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
							break;

							default:
							gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
							break;

                        }

                    }

                }

            }


            // Apply the image
            SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );

            // Update the surface of the window 
            SDL_UpdateWindowSurface( gWindow );

        }
    }

    // Free the resources and close SDL down refers to previous writtten function
    close();

    return 0;
}