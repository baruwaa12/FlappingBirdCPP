
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

// Load the individual image as a texture
SDL_Texture* loadTexture( std:: string path);

// The window we will be rendering to
SDL_Window *gWindow = NULL;

// The window renderer
SDL_Renderer* gRenderer = NULL;

// The current displayed texture;
SDL_Texture  * gTexture = NULL;

  
bool init()
{

    // Initialisation flag - (checks whether an action or variable has been initalized or not)
    bool success = true;

    // Initialise SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        // If SDL cannot be initialised throw SDL error and set initialisation flag to false
        printf("SDL could not be initialised!  SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {

        // Create the window and express that you dont care about the window position on screen
        gRenderer = SDL_CreateRenderer( gWindow, -1 SDL_RENDERER_ACCELERATED );
        if
    }

    return success;
}

bool loadMedia()
{
    // Loading success flag
    bool success = true;

    {
        printf("Failed to load stretching image! \n");
        success = false;
    }

    return success;
}

void close()
{
    // Deallocate the resources used to create the surface
    SDL_DestroyTexture(gTexture);
    gTexture = NULL;

    // Destroy the window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    // Exit the SDL subsystem
    SDL_Quit();
    IMG_Quit();
}

SDL_Surface *loadSurface(std::string path)
{

    // The final optimzed image
    SDL_Surface *optimzedSurface = NULL;

    // Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str()));
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {

        // Conver the surface to a screen format
        newTexture = SDL_ConvertTextureFromSurface( gRenderer, loadedSurface );
        if ( newTexture == NULL)
        {
            printf("Unable to optimze image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        // Removes old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

int main(int argc, char *args[])
{
    // Start up SDL and create the window
    if (!init())
    {
        printf("Failed to initialise! \n");
    }
    else
    {

        // Load the media
        if (!loadMedia())
        {
            printf("Failed to load the media! \n");
        }
        else
        {
            // Main loop flag - determines whether the user has quit or not
            bool quit = false;

            // Event handler
            SDL_Event e;

            // Do this while the app is running
            while (!quit)
            {

                // Handle events on queue
                while (SDL_PollEvent(&e) != 0)
                {
                    // User request to quit
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                }
                // Sets the color of the stream what last used in SDL_SetRender
                SDL_RenderClear(gRenderer);

                // Render texture to screen
                SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

                // Update screen
                SDL_RenderPresent(gRenderer);

                // Free the resources and close SDL down refers to previous writtten function
                close();

                return 0;
            }