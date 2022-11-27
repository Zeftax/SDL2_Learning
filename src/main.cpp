#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	// Check if SDL initialized correctly
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
		cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << endl;
	// Check if SDL IMG iniitialized correctly
	if(!IMG_Init(IMG_INIT_PNG))
		cout << "IMG_Init has failed. Error: " << SDL_GetError() << endl;

	// Create a new window
	RenderWindow window("GAME v1.0", 1280, 780);

	// Load a grass texture
	SDL_Texture* grassTexture =
		window.loadTexture("res/gfx/ground_grass_1.png");

	Entity platform0(100, 50, grassTexture);

	// Should the game stay open
	bool  gameRunning = true;

	// Read SDL events into this
	SDL_Event event;

	while(gameRunning)
	{
		// Gets all SDL events since last asked
		while(SDL_PollEvent(&event))
		{
			// If it is quit, tell the game to stop running
			// (does one last iteration of the game loop)
			if(event.type == SDL_QUIT)
				gameRunning = false;
		}

		// Clears the window
		window.clear();

		// Renders the grass texture onto the window
		window.render(platform0);

		// Displays the window onto screen
		window.display();
	}

	// Clean up and quit.
	window.cleanUp();
	SDL_Quit();
	return 0;
}
