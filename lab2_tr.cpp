//Создать класс Triangle1 для представления треугольника. Поля данных должны
//включать 3 стороны.Требуется реализовать операции : получения и изменения
//полей, вычисление площади по формуле Герона, периметра, вычисление высот,
//а также определения вида треугольника(равносторонний, равнобедренный
//или прямоугольный), перегрузку сравнения треугольников, основываясь
//на их площади), вычисление всех углов.


//Михайловская 11

#include <iostream>


class Triangle1
{
private:
    double sideA;
    double sideB;
    double sideC;
    void validateTriangle() const
    {
        if (sideA <= 0 || sideB <= 0 || sideC <= 0)
        {
            throw std::invalid_argument("Sides must be positive.");
        }
        if (sideA + sideB <= sideC || sideA + sideC <= sideB || sideB + sideC <= sideA)
        {
            throw std::invalid_argument("Invalid triangle sides.");
        }
    }
public:
    Triangle1(double a, double b, double c)
    {
        sideA = { a };
        sideB = { b };
        sideC = { c };
        validateTriangle();
    }
    double  getSideA() const { return sideA; }
    double getSideB() const { return sideB; }
    double getSideC() const { return sideC; }
    void setSides(double a, double b, double c)
    {
        sideA = { a };
        sideB = { b };
        sideC = { c };
        validateTriangle();
    }




};











int main()
{
    




    return 0;
}

