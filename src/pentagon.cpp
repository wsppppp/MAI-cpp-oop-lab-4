#include "../include/Pentagon.h"
#include <cmath>

template <is_scalar T>
Pentagon<T>::Pentagon() : Figure<T>(5) {}

template <is_scalar T>
Point<T> Pentagon<T>::getCenter() const {
    T centerX = 0, centerY = 0;
    for (size_t i = 0; i < this->n; ++i) {
        centerX += this->p[i].x;
        centerY += this->p[i].y;
    }
    return Point<T>(centerX / this->n, centerY / this->n);
}

template <is_scalar T>
double Pentagon<T>::getArea() const {
    double area = 0.0;
    for (size_t i = 0; i < this->n; ++i) {
        Point<T> p1 = this->p[i];
        Point<T> p2 = this->p[(i + 1) % this->n];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return std::abs(area) / 2.0;
}

template <is_scalar T>
Pentagon<T>::operator double() const {
    return getArea();
}