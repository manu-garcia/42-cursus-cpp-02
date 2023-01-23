#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{

public:
    Fixed();
    Fixed(Fixed const &fixed);
    ~Fixed();

    Fixed &operator=(Fixed const &fixed);
    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int fixedPointValue;
    static const int fractionalBits = 8;

};
#endif