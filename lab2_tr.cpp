//Создать класс Triangle1 для представления треугольника. Поля данных должны
//включать 3 стороны.Требуется реализовать операции : получения и изменения
//полей, вычисление площади по формуле Герона, периметра, вычисление высот,
//а также определения вида треугольника(равносторонний, равнобедренный
//или прямоугольный), перегрузку сравнения треугольников, основываясь
//на их площади), вычисление всех углов.
// 
//Во всех упражнениях, помимо указанных методов, обязательно должны быть
//реализованы функции ввода данных с клавиатуры и из файла, функции вывода данных
//на экран и в файл, метод преобразования в строку to_string.Для класса необходимо
//выполнить перегрузку операторов(+, -, *, / , битовые операторы, операторы
//сравнения — <=> и == ), если это возможно. Реализовывая операции нельзя использовать приведение к другим, более
// вместительным типам.Например, нельзя просто засунуть два long - а в longlong,сложить, а 
// затем разделить обратно на лонги в задаче №17 на класс LongLong.
// Аналогично, нельзя загонять массивы в большие числа или в тип string.
// Задача должна демонстрировать работу всех методов, для этого пользователь
//  должен мочь ввести Объект_A и Объект_B.

//Михайловская 11

#include <iostream>
#include <fstream>
#include <optional>
#include <numbers>
#include "Triangle1.h"

//class Triangle1
//{
//private:
//    double side_a;
//    double side_b;
//    double side_c;
//    bool validateTriangle(double a, double b, double c)
//    {
//        bool flag = true;
//        if ((a <= 0 || b <= 0 || c <= 0) &&
//            (a + b <= c || a + c <= b || b + c <= a))
//        {
//            flag = false;
//        }
//        return flag;
//    }
//public:
//    Triangle1(double a, double b, double c)
//    {
//        if (validateTriangle(a, b, c))
//        {
//            side_a = { a };
//            side_b = { b };
//            side_c = { c };
//        }
//        else
//            std::cout << "A triangle is not possible with such sides\n";
//    }
//    friend std::ostream& operator<<(std::ostream& out, const Triangle1& triangle) {
//        out << triangle.side_a << ' ' << triangle.side_b << ' ' << triangle.side_c << '\n';
//        return out;
//    }
//
//    friend std::istream& operator>>(std::istream& in, Triangle1& triangle) {
//        char c{' '};
//        in >> triangle.side_a >> c >> triangle.side_b >> c >> triangle.side_c;
//        return in;
//    }
//    /*bool validateTriangle()
//    {
//        bool flag = true;
//        if ((side_a <= 0 || side_b <= 0 || side_c <= 0) &&
//            (side_a + side_b <= side_c || side_a + side_c <= side_b || side_b + side_c <= side_a))
//        {
//            flag = false;
//        }
//        return flag;
//    }
//public:
//    Triangle1(double a, double b, double c)
//    {
//        side_a = { a };
//        side_b = { b };
//        side_c = { c };
//        if (!validateTriangle())
//            std::cout << "A triangle is not possible with such sides\n";
//    }
//    Triangle1(const std::string& file_name)
//    {
//        std::istringstream file(file_name);
//        file >> side_a >> side_b >> side_c;
//        if (!validateTriangle())
//            std::cout << "A triangle is not possible with such sides\n";
//    }*/
//    double  get_side_a() const { return side_a; }
//    double get_side_b() const { return side_b; }
//    double get_side_c() const { return side_c; }
//    
//    double perimeter() const
//    {
//        return side_a + side_b + side_c;
//    }
//    double area() const
//    {
//        double s = perimeter() / 2;
//        return std::sqrt(s * (s - side_a) * (s - side_b) * (s - side_c));
//    }
//    std::optional<double> height(double base) const
//    {
//        if (base <= 0 || (base != side_a && base != side_b && base != side_c))
//            return std::nullopt; // Если основание некорректно, возвращаем std::nullopt
//        return (2 * area()) / base;
//    }
//    std::string type() const
//    {
//        std::string type{};
//
//        if (side_a == side_b && side_b == side_c) {
//            type = "Equilateral";
//        }
//        else if (side_a == side_b || side_a == side_c || side_b == side_c) {
//            type = "Isosceles";
//        }
//        else if ((side_a * side_a + side_b * side_b == side_c * side_c) ||
//            (side_a * side_a + side_c * side_c == side_b * side_b) ||
//            (side_b * side_b + side_c * side_c == side_a * side_a)){
//                type =  "Right-angled";
//        }
//        else type =  "Scalene";
//        return type;
//    }
//    std::tuple<double, double, double> angles() const
//    {  // Вычисление углов в радианах 
//        double angleA = std::acos((side_b * side_b + side_c * side_c - side_a * side_a) / (2 * side_b * side_c));
//        double angleB = std::acos((side_a * side_a + side_c * side_c - side_b * side_b) / (2 * side_a * side_c));
//        double angleC = std::numbers::pi - angleA - angleB; // Сумма углов в треугольнике равна π
//        return std::make_tuple(angleA, angleB, angleC);
//    }
//    bool operator<(const Triangle1& other) const
//    {
//        return area() < other.area();
//    }
//    bool operator>(const Triangle1& other) const
//    {
//        return area() > other.area();
//    }
//
//    bool operator==(const Triangle1& other) const
//    {
//        return std::abs(area() - other.area()) < 1e-9;
//    };
//
//};

template<typename T>
T get_file();
bool condition(int x, int border);
void read_and_check(int& x, bool(*condition)(int, int), int border);
int menu(const std::string message, bool(*condition)(int, int), int border);
int exit();

template<typename T>
void print(T obj, std::ostream& stream = std::cout);
void set_tr(Triangle1& tr, std::istream& stream = std::cin);
template<typename T>
void print_res(std::string messege, T res );

int main()
{
    Triangle1 tr, tr2;
    double res_double{};
    std::string res_str{};
    std::tuple<double, double, double> angles{};
    int choice_task{};
    do
    {
        choice_task = menu("Tasks:\n1. Area of the triangle\n2.Perimeter of the triangle\n3.Triangle heights\n"
        "4.Type of triangle\n5.Сomparison of 2 triangles\n6.The angles of the triangle\n"
        "7.Output of the sides of the triangle\n8.Exit\n", condition, 9);
        if (choice_task != 8)
        {
            int choice_inp = menu("How to input?\n1.From the keyboard\n2.From the file\n", condition, 3);
            int choice_out = menu("How to output?\n1.On the screen\n2.In the file\n", condition, 3);
            switch (choice_inp)
            {
            case 1:
            {
                std::ifstream file = get_file<std::ifstream>();
                set_tr(tr, file);
                break;
            }
            case 2:
            {
                std::cout << "Input side of the triangle: ";
                set_tr(tr);
                break;
            }
            default:
                break;
            }
            if (choice_task == 5)
            {
                std::cout << "Input side of the 2 triangle: ";
                set_tr(tr2);
            }
            switch (choice_task)
            {
            case 1://Area of the triangle
            {
                res_double = tr.area();
                break;
            }
            case 2://Perimeter of the triangle
            {
                res_double = tr.perimeter();
                break;
            }
            case 3://Triangle heights
            {
                int choice_base = menu("Choose which side of the triangle you want to calculate the height for:\n"
                    "1.a\n2.b\n3.c\n", condition, 4);
                switch(choice_base)
                {
                case 1:
                    res_double = tr.height(tr.get_side_a());
                    break;
                case 2:
                    res_double = tr.height(tr.get_side_b());
                    break;
                default:
                    res_double = tr.height(tr.get_side_c());
                    break;
                }
                break;
            }
            case 4://Type of triangle
            {
                res_str = tr.type();
                break;
            }
            case 5://Сomparison of 2 triangles
            {
                int compare = tr.compare(tr2);
                switch (compare)
                {
                case 1:
                    res_str = "1 triangle is larger than 2";
                    break;
                case 2:
                    res_str = "1 triangle is less than 2";
                    break;
                default:
                    res_str = "the triangles are equal";
                    break;
                }
                break;
            }
            case 6://6.The angles of the triangle
            {
                angles = tr.angles();
                break;
            }
            default:
                break;
            }
            switch (choice_out)
            {
            case 1:
            {
                if (choice_task == 6)
                    print(angles);
                else
                {
                    if (choice_task == 4 || choice_task == 5)
                        print(angles);
                    else
                        if (choice_task != 7)
                            print(res_double);
                        else
                            print(tr);
                }
                break;
            }
            case 2:
            {
                std::ofstream file = get_file<std::ofstream>();
                if (choice_task == 6)
                    print(angles, file);
                else
                {
                    if (choice_task == 4 || choice_task == 5)
                        print(angles, file);
                    else
                        if (choice_task != 7 && choice_task != 8)
                            print(res_double, file);
                        else
                            print(tr, file);
                }
                break;
            }
            default:
                break;
            }
        }
        choice_task = exit();
    } while (choice_task != 8);
    return 0;
}


template<typename T>
T get_file()
{
    std::cout << "Введите имя файла:\n>";
    std::string file_name;
    std::cin >> file_name;
    T file(file_name);
    while (!file)
    {
        std::cout << "Файл не найден! Введите корректное название файла!\n-> ";
        std::cin.clear();
        std::string file_name;
        std::cin >> file_name;
        file.open(file_name);
    }
    return file;
}

template<typename T>
void print(T obj, std::ostream& stream)
{
    stream << obj;
}

template<typename T>
void print_res(std::string messege, T res)
{
    std::cout << messege << ": " << res << std::endl;
}

bool condition(int x, int border)
{
    return x > 0 && x < border;
}

void read_and_check(int& x, bool(*condition)(int, int), int border)
{
    std::cout << "\n->";
    while (!(std::cin >> x && condition(x, border))) {
        std::cout << "Ошибка! Введите корректное значение:\n";
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
        std::cout << "\n->";
    }
}

int menu(const std::string message, bool(*condition)(int, int), int border)
{
    std::cout << message;
    int option{};
    read_and_check(option, condition, border);
    std::cout << "\n";
    return option;
}

int exit()
{
	std::cout << "\nЗавершить работу? (Y/любая клавиша): ";
	char is_exit;
	short option_exit{};
	std::cin >> is_exit;
	if (is_exit == 'Y' || is_exit == 'y')
		option_exit = 8;
	return option_exit;
}

void set_tr(Triangle1& tr, std::istream& stream)
{
    stream >> tr;
}

