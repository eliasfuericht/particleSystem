#pragma once
#include <iostream>
#include "Vector2.h"
#include "Color.h"


class Particle
{
public:
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	Vector2 attractor;

	Color color;

	Particle(const Vector2& pos = Vector2(), const Vector2& vel = Vector2(), const Vector2& acc = Vector2(), const Vector2& att = Vector2(), const Color& col = Color())
		: position(pos), velocity(vel), acceleration(acc), attractor(att), color(col) {}
};

