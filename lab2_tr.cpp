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
//9

#include <iostream>
#include <fstream>
#include <sstream>
#include <numbers>
//#include "Triangle1.h"
import Triangle1;

template<typename T>
T get_file();
bool condition(int x, int border);
void read_and_check(int& x, bool(*condition)(int, int), int border);
int menu(const std::string message, bool(*condition)(int, int), int border);
int exit();

template<typename T>
void print(T obj, std::ostream& stream = std::cout);
void set_tr(Triangle1& tr, std::istream& stream = std::cin);
//bool is_triangle(const Triangle1& tr);

int main()
{
    Triangle1 tr, tr2;
    Triangle1* diff;
    double res_double{};
    std::string res_str{};
    int choice_task{};
    do
    {/*5.Comparison of 2 triangles*/
        choice_task = menu("Tasks:\n1. Area of the triangle\n2.Perimeter of the triangle\n3.Triangle heights\n"
        "4.Type of triangle\n5.Perform operations with triangles\n6.The angles of the triangle\n"
        "7.Output of the sides of the triangle\n8.Exit\n", condition, 9);
        if (choice_task != 8)
        {
            int choice_inp = menu("How to input?\n1.From the keyboard\n2.From the file\n", condition, 3);
            int choice_out = menu("How to output?\n1.On the screen\n2.In the file\n", condition, 3);
            bool is_tr{};
            do {

            
                switch (choice_inp)
                {
                case 1:
                {
                    std::cout << "Input side of the triangle: ";
                    set_tr(tr);
                    break;
                }
                case 2:
                {
                    std::ifstream file = get_file<std::ifstream>();
                    set_tr(tr, file);
                    break;
                }
                default:
                    break;
                }
                is_tr = tr.validate_triangle();
                if (!is_tr)
                    std::cout << "There is no such triangle.\n";
            } while (!is_tr);
            
            int choice_operations{};
            int scalar{};
            if (choice_task == 5)
            {
                choice_operations = menu("1.Multiply a triangle by a given number\n2.Divide the triangle by a given number\n"
                "3.Compare triangles by area\n", condition, 4);
                if (choice_operations == 3)
                {
                    do {
                        std::cout << "Input side of the 2 triangle: ";
                        set_tr(tr2);
                        is_tr = tr2.validate_triangle();
                        if (!is_tr)
                            std::cout << "There is no such triangle.\n";
                    } while (is_tr);
                        
                }
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
                /*int choice_base = menu("Choose which side of the triangle you want to calculate the height for:\n"
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
                }*/

                double a{}, b{}, c{};
                std::tie(a, b, c) = tr.heights();
                std::ostringstream oss;
                oss << a << ' ' << b  << ' ' << c;
                res_str = oss.str();

                break;
            }
            case 4://Type of triangle
            {
                res_str = tr.type();
                break;
            }
            case 5://Perform operations with triangles
            {
                /*"1.Perform the addition of triangles\n2.Perform triangle subtraction\n"
                    "3.Multiply a triangle by a given number\n4.Divide the triangle by a given number\n"
                    "5.Compare triangles by area\n"*/
                switch (choice_operations)
                {
                case 1:
                {
                    std::cout << "Enter the number by which you want to multiply the triangle: ";
                    std::cin >> scalar;
                    res_str = (tr * scalar).to_string();
                    break;
                }
                case 2:
                {
                    std::cout << "Enter the number by which you want to divide the triangle:";
                    std::cin >> scalar;
                    if (scalar != 0)
                        res_str = (tr / scalar).to_string();
                    else
                        std::cout << "\nYou can't divide by zero!";
                    break;
                }
                default:
                {
                    int compare = tr.compare(tr2);
                    switch (compare)
                    {
                    case 1:
                        res_str = "1 triangle is larger than 2";
                        break;
                    case -1:
                        res_str = "1 triangle is less than 2";
                        break;
                    default:
                        res_str = "the triangles are equal";
                        break;
                    }
                    break;
                }
                }
                break;
            }
            case 6://6.The angles of the triangle
            {
                /*double* res = tr.angles();
                std::ostringstream oss;
                oss << res[0] * 180 / std::numbers::pi << ' ' << res[1] * 180 / std::numbers::pi << ' ' << res[2] * 180 / std::numbers::pi;
                res_str = oss.str();
                break;*/
                double a{}, b{}, c{};
                std::tie(a, b, c) = tr.angles();
                std::ostringstream oss;
                oss  << a * 180 / std::numbers::pi << ' '<< b * 180 / std::numbers::pi << ' ' << c * 180 / std::numbers::pi;
                res_str = oss.str();
                break;
            }
            default:
                break;
            }
            switch (choice_out)
            {
            case 1:
            {
                 if (choice_task == 4 || choice_task == 5 || choice_task == 6 || choice_task == 3)
                    print(res_str);
                 else
                    if (choice_task != 7)
                        print(res_double);
                    else
                        print(tr);
                break;
            }
            case 2:
            {
                std::ofstream file = get_file<std::ofstream>();
                if (choice_task == 4 || choice_task == 5 || choice_task == 6 || choice_task == 3)
                    print(res_double, file);
                else
                    if (choice_task != 7 && choice_task != 8)
                        print(res_double, file);
                    else
                        print(tr, file);
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
    std::cout << "Enter the file name:\n>";
    std::string file_name;
    std::cin >> file_name;
    T file(file_name);
    while (!file)
    {
        std::cout << "The file was not found! Enter the correct file name!\n-> ";
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

bool condition(int x, int border)
{
    return x > 0 && x < border;
}

void read_and_check(int& x, bool(*condition)(int, int), int border)
{
    std::cout << "\n->";
    while (!(std::cin >> x && condition(x, border))) {
        std::cout << "Mistake! Enter the correct value:\n";
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
	std::cout << "\nFinish the job? (Y/any key): ";
	char is_exit;
	short option_exit{};
	std::cin >> is_exit;
	if (is_exit == 'Y' || is_exit == 'y')
		option_exit = 8;
	return option_exit;
}

void set_tr(Triangle1& tr, std::istream& stream)
{
    std::cin.clear();
    stream >> tr;
}

//bool is_triangle(const Triangle1& tr)
//{
//    if(tr.get_side_a() <= 0 || tr.get_side_b() <= 0 || tr.get_side_c() <= 0 ||)
//    return tr.get_side_a() && tr.get_side_b() && tr.get_side_c();
//}

