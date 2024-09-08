#pragma once
#include <iostream>
#include "Classes.h"
#include <cmath>
#define TRIANGLE_POLYGON 2

double Distant_points(Point point1, Point point2);

Point::Point() : x(0), y(0) {}
Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}
double Point::getX()
{
    return x;
}
double Point::getY()
{
    return y;
}
void Point::setX(double x)
{
    this->x = x;
}
void Point::setY(double y)
{
    this->y = y;
}

Line::Line(Point a, Point b)
{
    this->a1 = a;
    this->a2 = b;
}
void Line::print_info()
{
    std::cout << this->a1 << std::endl;
    std::cout << this->a2 << std::endl;
}
void Line::Set_points(Point a, Point b)
{
    this->a1 = a;
    this->a2 = b;
}
double Line::Perimeter()
{
    double P = Distant_points(this->a1, this->a2);
    return P;
}

Triangle::Triangle(Point a, Point b, Point c)
{
    this->a1 = a;
    this->a2 = b;
    this->a3 = c;
}
void Triangle::print_info()
{
    std::cout << this->a1 << std::endl;
    std::cout << this->a2 << std::endl;
    std::cout << this->a3 << std::endl;
}
void Triangle::Set_points(Point a, Point b, Point c)
{
    this->a1 = a;
    this->a2 = b;
    this->a3 = c;
}
double Triangle::Square()
{
    double s;
    s = abs((((a1.getX() - a3.getX()) * (a2.getY() - a3.getY())) -
        ((a1.getY() - a3.getY()) * (a2.getX() - a3.getX()))) / 2);
    return s;
}
double Triangle::Perimeter()
{
    double P = sqrt(pow(a2.getX() - a1.getX(), 2) + pow(a2.getY() - a1.getY(), 2)) +
        sqrt(pow(a3.getX() - a2.getX(), 2) + pow(a3.getY() - a2.getY(), 2)) +
        sqrt(pow(a1.getX() - a3.getX(), 2) + pow(a1.getY() - a3.getY(), 2));
    return P;
}

Polygon::Polygon(Point* mass_points, int size):
    point_count(size)
{
    this->points = new Point[size];
    for (int i = 0; i < size; i++)
    {
        this->points[i] = mass_points[i];
    }
    Triangle_recalculation();
}
Polygon::Polygon() :
    point_count(0),
    triangles_count(0)
{
    this->points = nullptr;
    this->trianges = nullptr;
}
Polygon::~Polygon()
{
    if(this->points != nullptr)
        delete[] points;
    if(this->trianges != nullptr)
        delete[] trianges;
}

void Polygon::print_info()
{
    std::cout << "Count of dots = " << this->point_count << std::endl;
    std::cout <<  "Count of triangle polygons = " << this->triangles_count << std::endl;
    for (int i = 0; i < point_count; i++)
    {
        std::cout << points[i] << std::endl;
    }
}
void Polygon::Add_new_points(Point* mass_points, int size)
{
    Point* new_mass_points = new Point[this->point_count + size];
    for (int i = 0; i < this->point_count; i++)
        new_mass_points[i] = this->points[i];
    for (int i = 0; i < size; i++)
        new_mass_points[i + this->point_count] = mass_points[i];
    this->point_count += size;
    Set_new_points(new_mass_points, this->point_count);
    delete[] new_mass_points;
}
void Polygon::Set_new_points(Point* mass_points, int size)
{
    if (this->points != nullptr)
        delete[] points;
    this->points = new Point[size];
    for (int i = 0; i < size; i++)
    {
        this->points[i] = mass_points[i];
    }
    Triangle_recalculation();
}
double Polygon::Perimeter()
{
    double P = 0;
    if (this->point_count > 1)
    {
        for (int i = 0; i < this->point_count - 1; i++)
        {
            P = P + Distant_points(this->points[i], this->points[i + 1]);
        }
        P = P + Distant_points(this->points[0], this->points[this->point_count - 1]);
    }
    return P;
}
double Polygon::Square()
{
    double S = 0;
    if (this->triangles_count != 0)
    {
        for (int i = 0; i < this->triangles_count; i++)
        {
            S = S + this->trianges[i].Square();
        }
    }
    return S;
}
void Polygon::Triangle_recalculation()
{
    if (trianges != nullptr)
        delete[] trianges;
    if (this->point_count >= 3)
    {
        this->triangles_count = this->point_count - TRIANGLE_POLYGON;
        this->trianges = new Triangle[this->point_count - TRIANGLE_POLYGON];
        this->triangles_count = this->point_count - TRIANGLE_POLYGON;
    }
    else
        this->trianges = nullptr;
    for (int i = 0; i < this->point_count - TRIANGLE_POLYGON; i++)
    {
        this->trianges[i].Set_points(this->points[0], this->points[i + 1], this->points[i + 2]);
    }
}