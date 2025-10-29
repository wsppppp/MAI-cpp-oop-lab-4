#pragma once
#include "Figure.h"
#include <cmath>

template <is_scalar T>
class Hexagon : public Figure<T> {
public:
    Hexagon() : Figure<T>(6) {}

    Point<T> getCenter() const override {
        T centerX = 0, centerY = 0;
        for (size_t i = 0; i < this->n; ++i) {
            centerX += this->p[i].x;
            centerY += this->p[i].y;
        }
        return Point<T>(centerX / this->n, centerY / this->n);
    }

    double getArea() const override {
        double area = 0.0;
        for (size_t i = 0; i < this->n; ++i) {
            const Point<T>& p1 = this->p[i];
            const Point<T>& p2 = this->p[(i + 1) % this->n];
            area += (p1.x * p2.y - p2.x * p1.y);
        }
        return std::abs(area) / 2.0;
    }

    operator double() const override {
        return getArea();
    }
};