#include "ParticleSystem.h"

std::vector<Particle> ParticleSystem::createPoints(int n)
{
	for (int i = 0; i < n; i++) {
		Particle particle{ Vector2(rand() % screenWidth, rand() % screenHeight), Vector2(), Vector2(), Vector2(), Color(255,0,0,255) };
		particles.push_back(particle);
	}
	return particles;
}

void ParticleSystem::update(double dt, std::vector<Particle>& particles)
{
	for (size_t i = 0; i < particles.size() - 1; i++) {
		Vector2 dir = { screenWidth / 2.0 - particles[i].position.x, screenHeight / 2.0 - particles[i].position.y };
		dir.normalize();
		particles[i].position.x += dir.x * dt;
		particles[i].position.y += dir.y * dt;
	}
}

void ParticleSystem::drawPoints(SDL_Renderer* r, std::vector<Particle>& particles)
{
	SDL_SetRenderDrawColor(r, 0, 0, 0, 0);
	SDL_RenderClear(r);
	for (Particle const p : particles) {
		SDL_SetRenderDrawColor(r, p.color.r, p.color.g, p.color.b, p.color.a);
		SDL_RenderDrawPoint(r, p.position.x, p.position.y);
	}
	SDL_RenderPresent(r);
}