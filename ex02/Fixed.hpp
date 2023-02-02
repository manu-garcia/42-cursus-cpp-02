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

    int getRawBits(void) const;
    void setRawBits(const int raw);
    float toFloat(void) const;
    int toInt(void) const;

    // https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes
    friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
    friend bool operator>(const Fixed &left, const Fixed &right);
    friend bool operator<(const Fixed &left, const Fixed &right);
    friend bool operator>=(const Fixed &left, const Fixed &right);
    friend bool operator<=(const Fixed &left, const Fixed &right);
    friend bool operator==(const Fixed &left, const Fixed &right);
    friend bool operator!=(const Fixed &left, const Fixed &right);
    friend Fixed operator+(const Fixed &left, const Fixed &right);
    friend Fixed operator-(const Fixed &left, const Fixed &right);
    friend Fixed operator*(const Fixed &left, const Fixed &right);
    friend Fixed operator/(const Fixed &left, const Fixed &right);

private:
    int fixedPointValue;
    static const int fractionalBits = 8;
};

#endif