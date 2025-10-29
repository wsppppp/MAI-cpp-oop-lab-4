#include <gtest/gtest.h>
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "figure_array.h"
#include <memory>

TEST(ArrayTest, RemoveElement) {
    Array<std::shared_ptr<Figure<int>>> figures(3);
    figures[0] = std::make_shared<Pentagon<int>>();
    figures[1] = std::make_shared<Hexagon<int>>();
    figures[2] = std::make_shared<Octagon<int>>();

    ASSERT_EQ(figures.size(), 3);
    figures.remove(1);
    ASSERT_EQ(figures.size(), 2);
    ASSERT_NE(dynamic_cast<Octagon<int>*>(figures[1].get()), nullptr);
}

TEST(PentagonTest, AreaAndCenter) {
    Pentagon<double> p;
    auto& points = p.getPoints();
    points[0] = Point<double>(0, 0);
    points[1] = Point<double>(2, 0);
    points[2] = Point<double>(3, 2);
    points[3] = Point<double>(1, 3);
    points[4] = Point<double>(-1, 2);

    Point<double> center = p.getCenter();
    ASSERT_DOUBLE_EQ(center.x, 1.0);
    ASSERT_DOUBLE_EQ(center.y, 1.4);
    ASSERT_DOUBLE_EQ(p.getArea(), 8.0);
}

TEST(HexagonTest, AreaAndCenter) {
    Hexagon<double> h;
    auto& points = h.getPoints();
    points[0] = Point<double>(1, 0);
    points[1] = Point<double>(2, 0);
    points[2] = Point<double>(3, 1);
    points[3] = Point<double>(2, 2);
    points[4] = Point<double>(1, 2);
    points[5] = Point<double>(0, 1);

    Point<double> center = h.getCenter();
    ASSERT_DOUBLE_EQ(center.x, 1.5);
    ASSERT_DOUBLE_EQ(center.y, 1.0);
    ASSERT_DOUBLE_EQ(h.getArea(), 4.0);
}

TEST(OctagonTest, AreaAndCenter) {
    Octagon<double> o;
    auto& points = o.getPoints();
    points[0] = Point<double>(1, 0);
    points[1] = Point<double>(2, 0);
    points[2] = Point<double>(3, 1);
    points[3] = Point<double>(3, 2);
    points[4] = Point<double>(2, 3);
    points[5] = Point<double>(1, 3);
    points[6] = Point<double>(0, 2);
    points[7] = Point<double>(0, 1);

    Point<double> center = o.getCenter();
    ASSERT_DOUBLE_EQ(center.x, 1.5);
    ASSERT_DOUBLE_EQ(center.y, 1.5);
    ASSERT_DOUBLE_EQ(o.getArea(), 7.0); 
}