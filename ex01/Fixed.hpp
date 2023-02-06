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

private:
    int fixedPointValue;
    static const int fractionalBits = 8;
};

// https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes
// Although friend keyword is not allowed in the subject
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
