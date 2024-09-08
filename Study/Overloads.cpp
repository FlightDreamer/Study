#pragma once
#include <iostream>
#include "Classes.h"


std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "Point(" << point.x << ", " << point.y << ")";
    return os;
}
bool Point::operator<(const Point& other) const {
    return (x * x + y * y) < (other.x * other.x + other.y * other.y);
}
bool Point::operator>(const Point& other) const {
    return (x * x + y * y) > (other.x * other.x + other.y * other.y);
}
bool Point::operator==(const Point& other) const {
    return (x == other.x) && (y == other.y);
}
bool Point::operator!=(const Point& other) const {
    return!(*this == other);
}
bool Point::operator<=(const Point& other) const {
    return (*this < other) || (*this == other);
}
bool Point::operator>=(const Point& other) const {
    return (*this > other) || (*this == other);
}