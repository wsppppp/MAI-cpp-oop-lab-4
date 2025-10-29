#pragma once
#include "Figure.h"

template <is_scalar T>
class Pentagon : public Figure<T> {
public:
    Pentagon();

    virtual Point<T> getCenter() const override;
    virtual double getArea() const override;
    virtual operator double() const override;
};

