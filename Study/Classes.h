#pragma once
#include <iostream>
class Point
{
private:
    double x, y;
public:
    double getX();
    double getY();
    void setX(double x);
    void setY(double y);
    Point(double x, double y);
    Point();
    friend std::ostream& operator<<(std::ostream& os, const Point& point); //Overloads for class point
    bool operator<(const Point& other) const;
    bool operator>(const Point& other) const;
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
    bool operator<=(const Point& other) const;
    bool operator>=(const Point& other) const;
};

class Line: public Point
{
private:
    Point a1;
    Point a2;
public:
    Line(Point a, Point b);
    Line() : a1(0, 0), a2(0, 0) {};
    virtual void print_info();
    virtual void Set_points(Point a, Point b);
    virtual double Perimeter();
};

class Triangle: public Line
{
    friend class Polygon;
private:
    Point a1;
    Point a2;
    Point a3;
public:
    Triangle(Point a, Point b, Point c);
    Triangle() : a1(0,0), a2(0,0), a3(0,0) {};
    virtual void print_info();
    virtual void Set_points(Point a, Point b, Point c);
    virtual double Square();
    virtual double Perimeter();
};

class Polygon final: public Triangle
{
private:
    Point* points;
    Triangle* trianges;
    int point_count;
    int triangles_count;
public:
    Polygon();
    Polygon(Point* mass_points, int size);
    virtual ~Polygon();
    void print_info();
    void Set_new_points(Point* mass_points, int size);
    void Add_new_points(Point* mass_points, int size);
    void Triangle_recalculation();
    double Square();
    double Perimeter();
};