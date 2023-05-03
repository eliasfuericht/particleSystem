#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include "main.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Point* createPoints() {
	SDL_Point* myPoints[3] ;
	return *myPoints;
}

int main(int argc, char* args[]) {
	SDL_Window* window = NULL;
	
	SDL_Surface* screensurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		window = SDL_CreateWindow("Particle-System", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else {
			screensurface = SDL_GetWindowSurface(window);

			SDL_FillRect(screensurface, NULL, SDL_MapRGB(screensurface->format, 0xff, 0xff, 0xff));

			SDL_UpdateWindowSurface(window);

			SDL_Event e;

			bool quit = false;

			//call function that creates points and draws triangle

			//createPoints();

			while (!quit) {
				//Application updateloop here
				while (SDL_PollEvent(&e)) {
					if (e.type == SDL_QUIT) {
						quit = true;
					}
				}
			}
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}