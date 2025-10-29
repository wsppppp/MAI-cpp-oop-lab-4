#pragma once

#include <iostream>
#include <cmath>
#include "concepts.h" // Подключаем концепт

// Используем концепт для ограничения шаблонного параметра T
template <is_scalar T>
class Point {
    template <is_scalar F>
    friend std::istream& operator>>(std::istream& is, Point<F>& p);
    template <is_scalar F>
    friend std::ostream& operator<<(std::ostream& os, const Point<F>& p);

public:
    T x, y;

    Point();
    Point(T x, T y);

    bool operator==(const Point<T>& other) const;
    Point<T>& operator=(const Point<T>& other);
};

