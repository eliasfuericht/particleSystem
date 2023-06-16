#pragma once

#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <cmath>

#include "ParticleSystem.h"

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

const int NUM_PARTICLES = 10000;

int main(int argc, char* args[]) {

	SDL_Window* window = SDL_CreateWindow("Particle-System", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	std::vector<ParticleSystem> particleSystems;
	for (int i = 0; i < 1; i++) {

		ParticleSystem particleSystem = ParticleSystem(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, NUM_PARTICLES, Color(255, 255, 255, 255));

		particleSystems.emplace_back(particleSystem);
	}

	for (ParticleSystem& p : particleSystems) {
		p.createPoints(p.particleCount);
	}

	SDL_Event e;

	bool quit = false;

	Uint32 startTime = SDL_GetTicks();
	int frameCount = 0;

	Vector2 mouse = Vector2();

	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_MOUSEMOTION) {
				mouse.x = e.motion.x;
				mouse.y = e.motion.y;
				for (ParticleSystem& p : particleSystems) {
					p.setMouse(mouse);
				}
			}
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}

		
		// GAME LOOP

		double dt = SDL_GetTicks();

		Uint32 elapsedTime = dt - startTime;
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		for (ParticleSystem& p : particleSystems) {
			p.update(elapsedTime);
			p.drawPoints();
		}

		frameCount++;

		if (elapsedTime >= 1000) {
			float fps = static_cast<float>(frameCount) / (elapsedTime / 1000.0f);
			std::cout << "FPS: " << fps << std::endl;
			startTime = SDL_GetTicks();
			frameCount = 0;
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}