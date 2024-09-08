#include <iostream>
#include "Classes.h"
#include <string>
#include <sstream>
#include <regex>

double Distant_points(Point point1, Point point2);
void func(Line& obj);
bool isValidInput(const std::string& input);
bool check_input(const std::string& xStr, const std::string& yStr, Polygon& polygon);
void print_endl();
void input_func(Polygon& polygon);
void calculate_func(Polygon& polygon);
void print_hello_func();
int main(int argc, char** argv)
{
    /*int size = 5;
    Point* mass_points = new Point[size];
    mass_points[0].setX(0);
    mass_points[0].setY(0);
    mass_points[1].setX(2);
    mass_points[1].setY(0);
    mass_points[2].setX(4);
    mass_points[2].setY(2);
    mass_points[3].setX(2);
    mass_points[3].setY(4);
    mass_points[4].setX(0);
    mass_points[4].setY(4);
    Triangle triangle1(mass_points[0], mass_points[1], mass_points[2]);
    Line line(mass_points[0], mass_points[1]);
    Polygon polygon(mass_points, size);
    polygon.print_info();
    std::cout << "Square = " << triangle1.Square() << std::endl;
    std::cout << "Perimeter = " << triangle1.Perimeter() << std::endl;
    polygon.Add_new_points(mass_points, size);
    polygon.print_info();

    std::cout << "Perimeter = " << polygon.Perimeter() << std::endl;
    std::cout << "Squad = " << polygon.Square() << std::endl;

    if (mass_points[0] == mass_points[1])
        std::cout << "Equal";
    if (mass_points[0] > mass_points[1])
        std::cout << "Bigger Distance";
    if (mass_points[0] < mass_points[1])
        std::cout << "Smaller Distance" << std::endl;
    func(polygon);
    func(line);
    func(triangle1);
    //Point* a = new Line;
    //delete a;
    delete[] mass_points;*/
    Polygon* polygon = new Polygon[1];
    print_hello_func();
    while (true) 
    {
        std::cout << "1.Set a new Dots" << std::endl;
        std::cout << "2.Add a new Dots" << std::endl;
        std::cout << "3.Go to calculations" << std::endl;
        std::cout << "4.Print info about dots" << std::endl;
        std::cout << "5.Exit" << std::endl;
        std::string input_line;
        std::getline(std::cin, input_line);

        if (input_line == "1") {
            delete[] polygon;
            polygon = new Polygon[1];
            input_func(polygon[0]);
            std::cout << "Polygon was formed" << std::endl;
            print_endl();
        }
        if (input_line == "2") {
            input_func(polygon[0]);
            std::cout << "Polygon was formed" << std::endl;
            print_endl();
        }
        if (input_line == "3") {
            calculate_func(polygon[0]);
            print_endl();
        }
        if (input_line == "4") {
            polygon->print_info();
        }
        if (input_line == "5") {
            print_endl();
            break;
        }
    }
    if (polygon != nullptr)
        delete[] polygon;
    return 0;
}

/*class A
{
public:
    A()
    {
        std::cout << "new231";
    };
};
class B : public A
{
public:
    B()
    {
        std::cout << "new";
    };
};
int main()
{
    A* a = new B;
    delete a;
    return 0;
}*/