#pragma once
#include "Particle.h"
#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <cmath>

class ParticleSystem
{
public:
	SDL_Window* window;
	SDL_Renderer* renderer;

	int screenWidth;
	int screenHeight;
	int particleCount;

	std::vector<Particle> particles;

	std::vector<Particle> createPoints(int n);

	void update(double dt, std::vector<Particle>& particles);

	void drawPoints(SDL_Renderer* r, std::vector<Particle>& particles);

	ParticleSystem(SDL_Window* w,SDL_Renderer* r, const int& screenWidth, const int& screenHeight, const int& particleCount) : window(w), renderer(r), screenWidth(screenWidth), screenHeight(screenHeight), particleCount(particleCount) {}
};

