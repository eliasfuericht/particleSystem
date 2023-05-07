#pragma once
#include <iostream>
#include <cmath>

class Vector2 {
public:
    double x;
    double y;

    Vector2(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    void normalize() {
        double length = magnitude();
        if (length != 0.0) {
            x /= length;
            y /= length;
        }
    }

    Vector2 subtract(Vector2& end) {
        return Vector2(end.x - x, end.y - y);
    }

    float magnitude() {
        return std::sqrt(x * x + y * y);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};

