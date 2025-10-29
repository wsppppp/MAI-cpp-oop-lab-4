#pragma once

#include <iostream>
#include <cmath>
#include <type_traits>

// Концепт для проверки, является ли тип скалярным (арифметическим)
template <class T>
concept is_scalar = std::is_arithmetic_v<T>;

template <is_scalar T>
class Point {
public:
    T x, y;

    Point() : x(0), y(0) {}
    Point(T x, T y) : x(x), y(y) {}

    bool operator==(const Point<T>& other) const {
        return (this->x == other.x && this->y == other.y);
    }

    Point<T>& operator=(const Point<T>& other) {
        if (this != &other) {
            this->x = other.x;
            this->y = other.y;
        }
        return *this;
    }
};

template <is_scalar T>
std::istream& operator>>(std::istream& is, Point<T>& p) {
    is >> p.x >> p.y;
    return is;
}

template <is_scalar T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}