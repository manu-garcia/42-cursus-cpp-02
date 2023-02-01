#include <cmath>

#include "Fixed.hpp"

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = intValue << this->fractionalBits;
}

Fixed::Fixed(const float floatingPointValue)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(floatingPointValue * (1 << this->fractionalBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Operators
//
// https://en.cppreference.com/w/cpp/language/operators
//
///////////////////////////////////////////////////////////////////////////////

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &fixed)
    {
        this->fixedPointValue = fixed.getRawBits();
    }
    return *this;
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return this->fixedPointValue > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return this->fixedPointValue < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return this->fixedPointValue >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return this->fixedPointValue <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return this->fixedPointValue == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return this->fixedPointValue != fixed.getRawBits();
}

///////////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////////

float Fixed::toFloat(void) const
{
    return ((float)this->fixedPointValue) / (1 << this->fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->fixedPointValue >> this->fractionalBits;
}

int Fixed::getRawBits(void) const
{
    return this->fixedPointValue;
}

void Fixed::setRawBits(const int raw)
{
    this->fixedPointValue = raw;
}

///////////////////////////////////////////////////////////////////////////////
// Non-Member functions
///////////////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    return os << fixed.toFloat();
}
