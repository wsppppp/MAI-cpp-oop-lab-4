#pragma once
#include "Figure.h"

template <is_scalar T>
class Hexagon : public Figure<T> {
public:
    Hexagon();

    virtual Point<T> getCenter() const override;
    virtual double getArea() const override;
    virtual operator double() const override;
};

