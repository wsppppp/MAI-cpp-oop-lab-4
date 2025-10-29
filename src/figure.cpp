#include "../include/Figure.h"

template <is_scalar T>
std::istream& operator>>(std::istream& is, Figure<T>& figure) {
    std::cout << "Enter " << figure.n << " points (x y):" << std::endl;
    for (size_t i = 0; i < figure.n; ++i) {
        is >> figure.p[i];
    }
    return is;
}

template <is_scalar T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& figure) {
    for (size_t i = 0; i < figure.n; ++i) {
        os << figure.p[i] << " ";
    }
    return os;
}