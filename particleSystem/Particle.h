#pragma once
#include <iostream>
#include "Vector2.h"
#include "Color.h"


class Particle
{
public:
	Particle(Vector2 pos, Vector2 vel, Vector2 acc, Vector2 att, Color csol, int life);

	Color GetColor() { return color; }
	Vector2 GetPosition() { return position; }
	Vector2 GetVelocity() { return velocity; }
	Vector2 GetAcceleration() { return acceleration; }
	Vector2 GetAttractor() { return attractor; }
	int GetLifeTime() { return lifeTime; }

	void UpdateXPosition(float dirX);
	void UpdateYPosition(float dirY);

private:
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	Vector2 attractor;

	Color color;

	int lifeTime;
};

