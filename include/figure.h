#pragma once

#include <iostream>
#include <memory>
#include "Point.h"

template <is_scalar T>
class Figure {
public:
    Figure(size_t vertices_count) : n(vertices_count), p(std::make_unique<Point<T>[]>(vertices_count)) {}
    virtual ~Figure() = default;

    virtual Point<T> getCenter() const = 0;
    virtual double getArea() const = 0;
    virtual operator double() const = 0;

    bool operator==(const Figure<T>& other) const {
        return (operator double()) == (double)other;
    }

    size_t getVertexCount() const { return n; }
    const std::unique_ptr<Point<T>[]>& getPoints() const { return p; }
    std::unique_ptr<Point<T>[]>& getPoints() { return p; }


protected:
    size_t n;
    std::unique_ptr<Point<T>[]> p;
};

template <is_scalar T>
std::istream& operator>>(std::istream& is, Figure<T>& figure) {
    size_t n = figure.getVertexCount();
    std::cout << "Enter " << n << " points (x y) for the figure:" << std::endl;
    for (size_t i = 0; i < n; ++i) {
        is >> figure.getPoints()[i];
    }
    return is;
}

template <is_scalar T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& figure) {
    size_t n = figure.getVertexCount();
    for (size_t i = 0; i < n; ++i) {
        os << figure.getPoints()[i] << " ";
    }
    return os;
}