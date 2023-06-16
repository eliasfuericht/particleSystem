#include "Particle.h"

Particle::Particle(Vector2 pos, Vector2 vel, Vector2 acc, Vector2 att, Color col, int life)
{
	position = pos;
	velocity = vel;
	acceleration = acc;
	attractor = att;
	color = col;
	lifeTime = life;
}

void Particle::UpdateXPosition(float dirX)
{
	position.x += dirX;
}

void Particle::UpdateYPosition(float dirY)
{
	position.y += dirY;
}

