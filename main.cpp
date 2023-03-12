// Import SDL and Standard IO

#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>



// These are the dimensions of the window 
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 507;



// Start up SDL and create the window
bool init();

//Load the media
bool loadMedia();

// Shuts down SDL and free the media
void close();

// The window that we will be rendering to
SDL_Window * gameWindow = NULL;

// Surface containing the window
SDL_Surface * BgSurface = NULL;

// Background loaded to the screen
SDL_Surface* gameBackground = NULL;

// Pipe obstacle pair loaded to the screen
SDL_Surface* pipeObstacleUp = NULL;


bool init()
{

    // Initialization flag - (checks whether an action or variable has been initalized or not)
    bool success = true;
     if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        // Create the window
        gameWindow = SDL_CreateWindow("FlappyBirdSDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if ( gameWindow == NULL )
        {
            // If the window cannot be created, retrieve the SDL error and set the flag to false
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;

        }
        else
        {
            // Retrieve the window surface
            BgSurface = SDL_GetWindowSurface( gameWindow );
            {
                // Get the window surface
                BgSurface = SDL_GetWindowSurface ( gameWindow );
            }
        }
    }
    return success;

}

bool loadinMedia()
{
     // Set and load the success flag
     bool success = true;


     // Load in the background
     gameBackground = SDL_LoadBMP("background.bmp");
     if ( gameBackground == NULL )
     {
        printf( "Unable to load image %s! SDL Error: %s\n", "Background.bmp", SDL_GetError() );
        success = false;
     }

     pipeObstacleUp = SDL_LoadBMP("pipeUp.bmp");
     if (pipeObstacleUp == NULL )
     {
        printf("Unable to load image %s! SDL Error: %s\n", "pipeUp.bmp", SDL_GetError() );
        success = false;
     }



     return success;
}

void close()
{
    // Deallocate resources making up the surface for the background
    SDL_FreeSurface( BgSurface );
    BgSurface = NULL;

    // Deallocate resources making up the surface for the pipes
    SDL_FreeSurface( pipeObstacleUp );
    pipeObstacleUp = NULL;

    // Destroy the window
    SDL_DestroyWindow( gameWindow );
    gameWindow = NULL;

    // Quit the SDL subsystems
    SDL_Quit();

}




// Game loop
int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load in necessary media
		if( !loadinMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Apply the image to the window surface
			SDL_BlitSurface( gameBackground, NULL, BgSurface, NULL );

            // Apply the pipe to the window surface
            SDL_BlitSurface( pipeObstacleUp, NULL, BgSurface, NULL);
			
			//Update the surface
			SDL_UpdateWindowSurface( gameWindow );

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
		}
	}

    

	//Free resources then close SDL
	close();

	return 0;
}



