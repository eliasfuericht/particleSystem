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

	Color color;

	int systemWidth;
	int screenHeight;
	int particleCount;


	Vector2 Mouse;

	std::vector<Particle> particles;

	ParticleSystem(SDL_Window* w, SDL_Renderer* r, const int& screenWidth, const int& screenHeight, const int& particleCount, const Color& particleColor) : window(w), renderer(r), systemWidth(screenWidth), screenHeight(screenHeight), particleCount(particleCount), color(particleColor) {}

	std::vector<Particle> createPoints(int n);

	void update(double dt);

	void drawPoints();

	void setMouse(Vector2& m);

};

