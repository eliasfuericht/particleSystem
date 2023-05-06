#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include "main.h"
#include "Vector2.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int NUM_PARTICLES = 2000;

SDL_Color drawColor = { 0,150,255,255 };

struct Vector2
{
	double x;
	double y;

	void normalize() {
		float length = std::sqrt(x * x + y * y);
		if (length != 0.0f) {
			x /= length;
			y /= length;
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector2& v) {
		os << "(" << v.x << ", " << v.y << ")";
		return os;
	}
};

std::vector<SDL_Point> createPoints(int n) {
	std::vector<SDL_Point> points;
	for (int i = 0; i < n; i++) {
		SDL_Point p = { rand() % 640,rand() % 480 };
		points.push_back(p);
	}
	return points;
}

void updatePoints(double dt, std::vector<SDL_Point>& points) {
	//get targetdirection by vectorsubtraction of next point
	for (size_t i = 0; i < points.size() - 1; i++) {
		Vector2 dir = { 640/2 - points[i].x, 480/2 - points[i].y };
		dir.normalize();
		points[i].x += dir.x * dt;
		points[i].y += dir.y * dt;
	}
}

void drawPoints(SDL_Renderer* r, SDL_Color c, std::vector<SDL_Point>& points) {
	SDL_SetRenderDrawColor(r, 0, 0, 0, 0);
	SDL_RenderClear(r);
	SDL_SetRenderDrawColor(r, c.r, c.g, c.b, c.a);
	for (SDL_Point p : points) {
		SDL_RenderDrawPoint(r, p.x, p.y);
	}
	SDL_RenderPresent(r);
}

int main(int argc, char* args[]) {

	SDL_Window* window = SDL_CreateWindow("Particle-System", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	std::vector<SDL_Point> points = createPoints(NUM_PARTICLES);

	SDL_Event e;

	bool quit = false;

	Uint32 startTime = SDL_GetTicks();
	int frameCount = 0;

	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}

		//Game Loop
		Uint32 elapsedTime = SDL_GetTicks() - startTime;

		updatePoints(elapsedTime, points);

		drawPoints(renderer, drawColor, points);

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