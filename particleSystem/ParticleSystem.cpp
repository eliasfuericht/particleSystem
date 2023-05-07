#include "ParticleSystem.h"

int strength = 10;

Vector2 gravity = Vector2(0, 9.81);

std::vector<Particle> ParticleSystem::createPoints(int n)
{
	for (int i = 0; i < n; i++) {
		Particle particle{ Vector2(rand() % systemWidth, rand() % screenHeight), Vector2(rand(),rand()), Vector2(), Vector2(rand() % systemWidth, rand() % screenHeight), color };
		particles.push_back(particle);
	}
	return particles;
}

void ParticleSystem::update(double dt)
{
	for (size_t i = 0; i < particles.size(); i++) {
		Vector2 dir = particles[i].position.subtract(Mouse);
		float distance = dir.magnitude();
		dir.normalize();
		particles[i].position.x += dir.x * dt; 
		particles[i].position.y += dir.y * dt;
	}
}

void ParticleSystem::drawPoints()
{
	for (size_t i = 1; i < particles.size(); ++i) {
		Particle const& p = particles[i];
		Particle const& pBefore = particles[i-1];
		SDL_SetRenderDrawColor(renderer, p.color.r, p.color.g, p.color.b, p.color.a);
		SDL_RenderDrawPoint(renderer, p.position.x, p.position.y);
		
	}
	SDL_RenderPresent(renderer);
}

void ParticleSystem::setMouse(Vector2& m)
{
	this->Mouse = m;
}
