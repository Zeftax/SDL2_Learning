#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

using namespace std;

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	:window(NULL), renderer(NULL)
{
	// Open a new window of size p_w x p_y
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	// Check whether window initialized
	if(window == NULL)
		cout << "Window failed to init. Error" << SDL_GetError() << endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if(texture == NULL)
		cout << "Failed to load texture. Error: " << SDL_GetError() << endl;

	return texture;
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* p_tex)
{
	SDL_RenderCopy(renderer, p_tex, NULL, NULL);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}
