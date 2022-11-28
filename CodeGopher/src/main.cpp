#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"

int main(int argc, char* argv[])
{
	// Check if SDL initialized correctly
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() <<
			std::endl;
	// Check if SDL IMG iniitialized correctly
	if(!IMG_Init(IMG_INIT_PNG))
		std::cout << "IMG_Init has failed. Error: " << SDL_GetError() <<
			std::endl;

	// Create a new window
	RenderWindow window("GAME v1.0", 1280, 780);
	int windowRefreshRate = window.getRefreshRate();

	// Load a grass texture
	SDL_Texture* grassTexture =
		window.loadTexture("res/gfx/ground_grass_1.png");

	// Grass entities
	std::vector<Entity> entities = {
		Entity(Vector2f(10, 20), grassTexture),
		Entity(Vector2f(100, 67), grassTexture),
		Entity(Vector2f(30, 155), grassTexture)};
	entities.push_back(Entity(Vector2f(67, 100), grassTexture));

	// Should the game stay open
	bool  gameRunning = true;

	// Read SDL events into this
	SDL_Event event;

	const float timeStep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = utils::hireTimeInSeconds();

	while(gameRunning)
	{
		int startTicks = SDL_GetTicks();

		float newTime = utils::hireTimeInSeconds();
		float frameTime = newTime - currentTime;

		currentTime = newTime;

		accumulator += frameTime;

		while(accumulator >= timeStep)
		{
			// Gets all SDL events since last asked
			while(SDL_PollEvent(&event))
			{
				// If it is quit, tell the game to stop running
				// (does one last iteration of the game loop)
				if(event.type == SDL_QUIT)
					gameRunning = false;
			}

			accumulator -= timeStep;
		}

		const float alpha = accumulator / timeStep;

		// Clears the window
		window.clear();

		// Renders the entities onto the window
		for(Entity& entity : entities)
		{
			window.render(entity);
		}

		// Displays the window onto screen
		window.display();

		// Time it took to compute this frame
		int frameTicks = SDL_GetTicks() - startTicks;

		if(frameTicks < 1000 / windowRefreshRate)
		{
			SDL_Delay(1000 / windowRefreshRate - frameTicks);
		}
	}

	// Clean up and quit.
	window.cleanUp();
	SDL_Quit();
	return 0;
}
