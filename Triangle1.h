#include <iostream>
#include <fstream>
#include <numbers>
#include <sstream>

class Triangle1
{
private:
    double side_a;
    double side_b;
    double side_c;
    void validate_triangle();
public:
    Triangle1();
    Triangle1(double a, double b, double c);
    friend std::ostream& operator<<(std::ostream& out, const Triangle1& triangle) {
        out << triangle.side_a << ' ' << triangle.side_b << ' ' << triangle.side_c << '\n';
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Triangle1& triangle) {
        in >> triangle.side_a >> triangle.side_b >> triangle.side_c;
        triangle.validate_triangle();
        return in;
    }
    std::string to_string();
    double get_side_a() const;
    double get_side_b() const;
    double get_side_c() const;
    void set_side_a(double value);
    void set_side_b(double value);
    void set_side_c(double value);

    int compare(const Triangle1& other);
    double perimeter() const;
    double area() const;
    //double height(double base) const;
    std::tuple<double, double, double> heights() const;

    std::string type() const;
    //double* angles() const;
    std::tuple<double, double, double> angles() const;
    bool operator==(const Triangle1& other) const;
    bool operator!=(const Triangle1& other) const;
    Triangle1 operator *(double scalar) const;
    Triangle1 operator /(double scalar) const;
    std::partial_ordering operator<=>(const Triangle1& other) const;
};
