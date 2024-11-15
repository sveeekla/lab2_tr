#include "Triangle1.h"

bool Triangle1::validateTriangle(double a, double b, double c)
{
    bool flag = true;
    if ((a <= 0 || b <= 0 || c <= 0) &&
        (a + b <= c || a + c <= b || b + c <= a))
    {
        flag = false;
    }
    return flag;
}

Triangle1::Triangle1()
{
    side_a = side_b = side_c = {};
}

Triangle1::Triangle1(double a, double b, double c)
{
    if (validateTriangle(a, b, c))
    {
        side_a = { a };
        side_b = { b };
        side_c = { c };
    }
    else
        std::cout << "A triangle is not possible with such sides\n";
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
    int res{};
    if (*this > other)
        res = 1;
    else
    {
        if (*this < other)
            res = 2;
        else
            res = 3;
    }
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

double Triangle1::height(double base) const
{
    return (2 * area()) / base;
}

std::string Triangle1::type() const
{
    std::string type{};

    if (side_a == side_b && side_b == side_c) {
        type = "Equilateral";
    }
    else if (side_a == side_b || side_a == side_c || side_b == side_c) {
        type = "Isosceles";
    }
    else if ((side_a * side_a + side_b * side_b == side_c * side_c) ||
        (side_a * side_a + side_c * side_c == side_b * side_b) ||
        (side_b * side_b + side_c * side_c == side_a * side_a)) {
        type = "Right-angled";
    }
    else type = "Scalene";
    return type;
}

std::tuple<double, double, double> Triangle1::angles() const
{  // Вычисление углов в радианах 
    double angleA = std::acos((side_b * side_b + side_c * side_c - side_a * side_a) / (2 * side_b * side_c));
    double angleB = std::acos((side_a * side_a + side_c * side_c - side_b * side_b) / (2 * side_a * side_c));
    double angleC = std::numbers::pi - angleA - angleB; // Сумма углов в треугольнике равна π
    return std::make_tuple(angleA, angleB, angleC);
}

bool Triangle1::operator<(const Triangle1& other) const
{
    return area() < other.area();
}

bool Triangle1::operator>(const Triangle1& other) const
{
    return area() > other.area();
}

bool Triangle1::operator==(const Triangle1& other) const
{
    return std::abs(area() - other.area()) < 1e-9;
}

std::partial_ordering Triangle1::operator<=>(const Triangle1& other) const
{
    std::partial_ordering res{ area() <=> other.area() };
    return res;
}
