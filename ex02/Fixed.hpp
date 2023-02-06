#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{

public:
    Fixed();
    Fixed(const Fixed &fixed);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();

    Fixed &operator=(const Fixed &fixed);

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    int getRawBits(void) const;
    void setRawBits(const int raw);
    float toFloat(void) const;
    int toInt(void) const;

    static Fixed &min(Fixed &left, Fixed &right);
    static Fixed &max(Fixed &left, Fixed &right);
    static const Fixed &min(const Fixed &left, const Fixed &right);
    static const Fixed &max(const Fixed &left, const Fixed &right);

private:
    int fixedPointValue;
    static const int fractionalBits = 8;
};

// https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes
// Although friend keyword is not allowed in the exercise
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
bool operator>(const Fixed &left, const Fixed &right);
bool operator<(const Fixed &left, const Fixed &right);
bool operator>=(const Fixed &left, const Fixed &right);
bool operator<=(const Fixed &left, const Fixed &right);
bool operator==(const Fixed &left, const Fixed &right);
bool operator!=(const Fixed &left, const Fixed &right);
Fixed operator+(const Fixed &left, const Fixed &right);
Fixed operator-(const Fixed &left, const Fixed &right);
Fixed operator*(const Fixed &left, const Fixed &right);
Fixed operator/(const Fixed &left, const Fixed &right);

#endif