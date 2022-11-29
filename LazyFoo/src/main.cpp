#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[])
{
	// The window we'll be rendering to
	SDL_Window* window = NULL;

	// The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	// Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		std::cerr << "SDL could not initialize! SDL_Error: " <<
			SDL_GetError() << std::endl;
		return -1;
	}

	// Create window
	window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN );

	if(window == NULL)
	{
		std::cerr << "Window could not be created! SDL_Error: " <<
			SDL_GetError() << std::endl;
	}

	return 0;
}
