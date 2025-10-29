#include "../include/Point.h"

template <is_scalar T>
Point<T>::Point() : x(0), y(0) {}

template <is_scalar T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template <is_scalar T>
bool Point<T>::operator==(const Point<T>& other) const {
    return (this->x == other.x && this->y == other.y);
}

template <is_scalar T>
Point<T>& Point<T>::operator=(const Point<T>& other) {
    if (this != &other) {
        this->x = other.x;
        this->y = other.y;
    }
    return *this;
}

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