#pragma once
#include <iostream>
#include <cmath>
#include "Classes.h"
#include <string>
#include <sstream>
#include <regex>

double Distant_points(Point point1, Point point2)
{
	double D = 0;
	D = sqrt(pow(point2.getX() - point1.getX(), 2) + pow(point2.getY() - point1.getY(), 2));
	return abs(D);
}

void func(Line& obj)
{
	std::cout << obj.Perimeter() << std::endl;
}

bool isValidInput(const std::string& input) {
	// –егул€рное выражение дл€ проверки формата "(x,y)"
	std::regex pattern(R"(\(\s*([-+]?\d+(\.\d+)?)\s*,\s*([-+]?\d+(\.\d+)?)\s*\))");
	return std::regex_match(input, pattern);
}

bool check_input(const std::string& xStr, const std::string& yStr, Polygon& polygon) {
    try
    {
        double x = std::stod(xStr);
        double y = std::stod(yStr);
        Point* point = new Point[1];
        point->setX(x);
        point->setY(y);
        polygon.Add_new_points(point, 1);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

void print_hello_func()
{
    std::cout << "Welcome to my little program for calculating the area and perimeter of a non-self-intersecting polygon " << std::endl;
    std::cout << "There may be errors here, from the writing side of the code, I am still trying to figure it out) " << std::endl;
}
void print_endl()
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}
void input_func(Polygon& polygon)
{
    std::cout << "Eneter a coord points in format (x,y) or 'stop' for :" << std::endl;
    while (true)
    {
        std::string input_line;
        std::getline(std::cin, input_line);

        if (input_line == "stop") {
            break;
        }

        if (isValidInput(input_line)) {
            // ”дал€ем скобки и разбиваем на координаты
            input_line.erase(0, 1); // удал€ем '('
            input_line.erase(input_line.size() - 1); // удал€ем ')'
            std::istringstream iss(input_line);
            std::string xStr, yStr;
            std::getline(iss, xStr, ',');
            std::getline(iss, yStr);
            if (check_input(xStr, yStr, polygon))
                std::cout << "Dot was inputed:" << std::endl;
            else
                std::cout << "Something went wrong" << std::endl;
        }
        else {
            std::cout << "Incorrect input. Please, enter a dot in format (x,y)." << std::endl;
        }
    }
}
void calculate_func(Polygon& polygon)
{
    while (true)
    {
        std::string input_line;
        std::cout << "1.Square" << std::endl;
        std::cout << "2.Perimeter" << std::endl;
        std::cout << "3.Point info" << std::endl;
        std::cout << "Enter 1,2,3. Or stop to go back" << std::endl;
        std::getline(std::cin, input_line);
        if (input_line == "stop") {
            break;
        }
        if (input_line == "1") {
            std::cout << "Square = " << polygon.Square() << std::endl;
        }
        if (input_line == "2") {
            std::cout << "Perimeter = " << polygon.Perimeter() << std::endl;
        }
        if (input_line == "3") {
            std::cout << "Point info: ";
            polygon.print_info();
            std::cout << std::endl;
        }
    }
}