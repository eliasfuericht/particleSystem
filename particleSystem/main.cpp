#include "main.h"

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

const int NUM_PARTICLES = 5001;

Color drawColor = { 0,150,255,255 };

std::vector<Particle> createPoints(int n) {
	std::vector<Particle> particles;
	for (int i = 0; i < n; i++) {
		Particle particle{ Vector2(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT), Vector2(), Vector2(), Vector2(), Color(255,0,0,255)};
		particles.push_back(particle);
	}
	return particles;
}

void updatePoints(double dt, std::vector<Particle>& particles) {
	//get targetdirection by vectorsubtraction of next point
	for (size_t i = 0; i < particles.size() - 1; i++) {
		Vector2 dir = { SCREEN_WIDTH / 2.0 - particles[i].position.x, SCREEN_HEIGHT / 2.0 - particles[i].position.y };
		dir.normalize();
		particles[i].position.x += dir.x * dt;
		particles[i].position.y += dir.y * dt;
	}
}

void drawPoints(SDL_Renderer* r,std::vector<Particle>& particles) {
	SDL_SetRenderDrawColor(r, 0, 0, 0, 0);
	SDL_RenderClear(r);
	for (Particle const p : particles) {
		SDL_SetRenderDrawColor(r, p.color.r, p.color.g, p.color.b, p.color.a);
		SDL_RenderDrawPoint(r, p.position.x, p.position.y);
	}
	SDL_RenderPresent(r);
}

int main(int argc, char* args[]) {

	SDL_Window* window = SDL_CreateWindow("Particle-System", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	ParticleSystem particleSystem = ParticleSystem(window, renderer,SCREEN_WIDTH,SCREEN_HEIGHT, NUM_PARTICLES);
	
	particleSystem.createPoints(NUM_PARTICLES);

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

		double dt = SDL_GetTicks();
		//Game Loop
		Uint32 elapsedTime = dt - startTime;

		particleSystem.update(dt, particleSystem.particles);

		particleSystem.drawPoints(renderer, particleSystem.particles);

		frameCount++;

		if (elapsedTime >= 1000) {
			float fps = static_cast<float>(frameCount) / (elapsedTime / 1000.0f);
			//std::cout << "FPS: " << fps << std::endl;
			startTime = SDL_GetTicks();
			frameCount = 0;
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}