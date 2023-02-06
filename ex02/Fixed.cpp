#include <cmath>

#include "Fixed.hpp"

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

Fixed::Fixed() : fixedPointValue(0)
{
}

Fixed::Fixed(const Fixed &fixed)
{
    *this = fixed;
}

Fixed::Fixed(const int intValue)
{
    this->fixedPointValue = intValue << this->fractionalBits;
}

Fixed::Fixed(const float floatingPointValue)
{
    this->fixedPointValue = roundf(floatingPointValue * (1 << this->fractionalBits));
}

Fixed::~Fixed()
{
}

///////////////////////////////////////////////////////////////////////////////
// Operators
//
// https://en.cppreference.com/w/cpp/language/operators
//
// Criteria:
//
//      Mutability: Member functions could modify the state. Friends should not.
//      Semantic consistency: c = a + b; // a should not change
//      Access control: friends cannot access private methods
//
///////////////////////////////////////////////////////////////////////////////

Fixed &Fixed::operator=(const Fixed &fixed)
{
    if (this != &fixed)
    {
        this->fixedPointValue = fixed.getRawBits();
    }
    return *this;
}

Fixed &Fixed::operator++()
{
    this->fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed copyBeforeIncrement(*this);
    ++this->fixedPointValue;
    return copyBeforeIncrement;
}

Fixed &Fixed::operator--()
{
    this->fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed copyBeforeDecrement(*this);
    --this->fixedPointValue;
    return copyBeforeDecrement;
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

Fixed &Fixed::min(Fixed &left, Fixed &right)
{
    return left < right ? left : right;
}

Fixed &Fixed::max(Fixed &left, Fixed &right)
{
    return left > right ? left : right;
}

const Fixed &Fixed::min(const Fixed &left, const Fixed &right)
{
    return left < right ? left : right;
}

const Fixed &Fixed::max(const Fixed &left, const Fixed &right)
{
    return left > right ? left : right;
}

///////////////////////////////////////////////////////////////////////////////
// Non-Member functions
///////////////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    return os << fixed.toFloat();
}

bool operator>(const Fixed &left, const Fixed &right)
{
    return left.getRawBits() > right.getRawBits();
}

bool operator<(const Fixed &left, const Fixed &right)
{
    return left.getRawBits() < right.getRawBits();
}

bool operator>=(const Fixed &left, const Fixed &right)
{
    return left.getRawBits() >= right.getRawBits();
}

bool operator<=(const Fixed &left, const Fixed &right)
{
    return left.getRawBits() <= right.getRawBits();
}

bool operator==(const Fixed &left, const Fixed &right)
{
    return left.getRawBits() == right.getRawBits();
}

bool operator!=(const Fixed &left, const Fixed &right)
{
    return left.getRawBits() != right.getRawBits();
}

Fixed operator+(const Fixed &left, const Fixed &right)
{
    return Fixed(left.toFloat() + right.toFloat());
}

Fixed operator-(const Fixed &left, const Fixed &right)
{
    return Fixed(left.toFloat() - right.toFloat());
}

Fixed operator*(const Fixed &left, const Fixed &right)
{
    return Fixed(left.toFloat() * right.toFloat());
}

Fixed operator/(const Fixed &left, const Fixed &right)
{
    return Fixed(left.toFloat() / right.toFloat());
}
