// Radian/Degree example
// converting constructors
// pass by value, pass by reference, pass by constant reference
// implicit/explicit constructors
// user-defined literals
// operator+ overload for Radian/Degree

#include <iostream>

const double PI = 3.1459;

struct Radian;

struct Degree
{
    double angle;

    Degree(double angle) : angle(angle) { }
    Degree(const Radian& radian);
};

struct Radian
{
    double angle;

    Radian(double angle) : angle(angle) { }
    Radian(const Degree& degree) : angle(degree.angle/180.0*PI) { }

    auto operator+(const Radian& right)
    {
        return Radian(angle + right.angle);
    }
};

Degree::Degree(const Radian& radian) : angle(radian.angle/PI*180.0) { }


void print(const Radian& value)
{
    std::cout << "Radian = " << value.angle << std::endl;
}

void print(const Degree& value)
{
    std::cout << "Degree = " << value.angle << std::endl;
}

auto operator"" _degree(long double value)
{
    return Degree(value);
}

auto operator"" _radian(long double value)
{
    return Radian(value);
}

//auto operator+(const Radian& left, const Radian& right)
//{
//    return Radian(left.angle + right.angle);
//}
