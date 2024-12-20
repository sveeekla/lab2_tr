﻿#include "Triangle1.h"

void Triangle1::validate_triangle()
{
    if (side_a <= 0 || side_b <= 0 || side_c <= 0)
    {
        throw std::invalid_argument("Sides must be positive.");
    }
    if (side_a + side_b <= side_c || side_a + side_c <= side_b || side_b + side_c <= side_a)
    {
        throw std::invalid_argument("Invalid triangle sides.");
    }
}

Triangle1::Triangle1()
{
    side_a = side_b = side_c = {};
}

Triangle1::Triangle1(double a, double b, double c)
{
    side_a = { a };
    side_b = { b };
    side_c = { c };
    validate_triangle();
}

std::string Triangle1::to_string()
{
    std::ostringstream str;
    str << side_a << " " << side_b << " " << side_c;
    return str.str();
}

double Triangle1::get_side_a() const
{
    return side_a;
}

double Triangle1::get_side_b() const
{
    return side_b;
}

double Triangle1::get_side_c() const
{
    return side_c;
}

int Triangle1::compare(const Triangle1& other)
{
    /*int res{};
    if (*this > other)
        res = 1;
    else
    {
        if (*this < other)
            res = 2;
        else
            res = 3;
    }
    return res;*/
    int res{ };
    std::partial_ordering id{ (*this) <=> other };
    if (id == std::partial_ordering::greater)
        res = 1;
    else
        if (id == std::partial_ordering::less)
            res = -1;
    return res;
}

double Triangle1::perimeter() const
{
    return side_a + side_b + side_c;
}

double Triangle1::area() const
{
    double s = perimeter() / 2;
    return std::sqrt(s * (s - side_a) * (s - side_b) * (s - side_c));
}

//double Triangle1::height(double base) const
//{
//    return (2 * area()) / base;
//}

std::string Triangle1::type() const
{
    std::string type{};

    if (side_a == side_b && side_b == side_c)
        type = "Equilateral";
    else
    {
        if (side_a == side_b || side_a == side_c || side_b == side_c)
            type = "Isosceles";
        else
        {
            if ((side_a * side_a + side_b * side_b == side_c * side_c) || //
                (side_a * side_a + side_c * side_c == side_b * side_b) ||
                (side_b * side_b + side_c * side_c == side_a * side_a))
            {
                type = "Right-angled";
            }
            else type = "Scalene";
        }
    }
    return type;
}

//double* Triangle1::angles() const
//{  // Вычисление углов в радианах 
//    double* res = new double[3];
//    res[0] = std::acos((side_b * side_b + side_c * side_c - side_a * side_a) / (2 * side_b * side_c));
//    res[1] = std::acos((side_a * side_a + side_c * side_c - side_b * side_b) / (2 * side_a * side_c));
//    res[2] = std::numbers::pi - res[0] - res[1]; // Сумма углов в треугольнике равна ?
//    return res;
//}

std::tuple<double, double, double> Triangle1::angles() const
{  // Вычисление углов в радианах 
    double angleA = std::acos((side_b * side_b + side_c * side_c - side_a * side_a) / (2 * side_b * side_c));
    double angleB = std::acos((side_a * side_a + side_c * side_c - side_b * side_b) / (2 * side_a * side_c));
    double angleC = std::numbers::pi - angleA - angleB; // Сумма углов в треугольнике равна pi
    return std::make_tuple(angleA, angleB, angleC);
}

bool Triangle1::operator==(const Triangle1& other) const
{
    return std::abs(area() - other.area()) < 1e-9;
}

bool Triangle1::operator!=(const Triangle1& other) const
{
    return std::abs(area() - other.area()) > 1e-9;
}

Triangle1 Triangle1::operator*(double scalar) const
{
    return Triangle1(side_a * scalar, side_b * scalar, side_c * scalar);
}

Triangle1 Triangle1::operator/(double scalar) const
{
    return Triangle1(side_a / scalar, side_b / scalar, side_c / scalar);
}

std::partial_ordering Triangle1::operator<=>(const Triangle1& other) const
{
    std::partial_ordering res;
    if (area() != other.area())
        res = area() <=> other.area();
    return res;
}

void Triangle1::set_side_a(double value)
{
    side_a = value;
}

void Triangle1::set_side_b(double value)
{
    side_b = value;
}

void Triangle1::set_side_c(double value)
{
    side_c = value;
}

std::tuple<double, double, double> Triangle1::heights() const
{
    double area_tmp = area();
    return std::make_tuple((2 * area()) / side_a, (2 * area()) / side_b, (2 * area()) / side_c);
}
