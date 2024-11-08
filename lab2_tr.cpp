//Создать класс Triangle1 для представления треугольника. Поля данных должны
//включать 3 стороны.Требуется реализовать операции : получения и изменения
//полей, вычисление площади по формуле Герона, периметра, вычисление высот,
//а также определения вида треугольника(равносторонний, равнобедренный
//или прямоугольный), перегрузку сравнения треугольников, основываясь
//на их площади), вычисление всех углов.


//Михайловская 11

#include <iostream>
#include <optional>
#include <numbers>


class Triangle1
{
private:
    double sideA;
    double sideB;
    double sideC;
    bool validateTriangle(double a, double b, double c)
    {
        bool flag = true;
        if ((a <= 0 || b <= 0 || c <= 0) &&
            (a + b <= c || a + c <= b || b + c <= a))
        {
            flag = false;
        }
        return flag;
    }
public:
    Triangle1(double a, double b, double c)
    {
        if (validateTriangle(a, b, c))
        {
            sideA = { a };
            sideB = { b };
            sideC = { c };
        }
        else
            std::cout << "A triangle is not possible with such sides\n";
    }
    double  getSideA() const { return sideA; }
    double getSideB() const { return sideB; }
    double getSideC() const { return sideC; }
    void setSides(double a, double b, double c)
    {
        if (validateTriangle(a, b, c))
        {
            sideA = { a };
            sideB = { b };
            sideC = { c };
        }
        else
            std::cout << "A triangle is not possible with such sides\n";
    }
    double perimeter() const
    {
        return sideA + sideB + sideC;
    }
    double area() const
    {
        double s = perimeter() / 2;
        return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }
    std::optional<double> height(double base) const
    {
        if (base <= 0 || (base != sideA && base != sideB && base != sideC))
            return std::nullopt; // Если основание некорректно, возвращаем std::nullopt
        return (2 * area()) / base;
    }
    std::string type() const
    {
        std::string type{};

        if (sideA == sideB && sideB == sideC) {
            type = "Equilateral";
        }
        else if (sideA == sideB || sideA == sideC || sideB == sideC) {
            type = "Isosceles";
        }
        else if ((sideA * sideA + sideB * sideB == sideC * sideC) ||
            (sideA * sideA + sideC * sideC == sideB * sideB) ||
            (sideB * sideB + sideC * sideC == sideA * sideA)){
                type =  "Right-angled";
        }
        else type =  "Scalene";
        return type;
    }
    std::tuple<double, double, double> angles() const
    {  // Вычисление углов в радианах 
        double angleA = std::acos((sideB * sideB + sideC * sideC - sideA * sideA) / (2 * sideB * sideC));
        double angleB = std::acos((sideA * sideA + sideC * sideC - sideB * sideB) / (2 * sideA * sideC));
        double angleC = std::numbers::pi - angleA - angleB; // Сумма углов в треугольнике равна π
        return std::make_tuple(angleA, angleB, angleC);
    }
    bool operator<(const Triangle1& other) const
    {
        return area() < other.area();
    }
    bool operator>(const Triangle1& other) const
    {
        return area() > other.area();
    }

    bool operator==(const Triangle1& other) const
    {
        return std::abs(area() - other.area()) < 1e-9;
    };

};











int main()
{
    




    return 0;
}

