#include "Fixed.hpp"
#include <cstdint>
#include <cmath>

Fixed::Fixed() : fpoint(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
    std::cout << "Int constructor called" << std::endl;
    fpoint = num * (1 << bits);
}

Fixed::Fixed(const float num) {
        std::cout << "Float constructor called" << std::endl;
            fpoint = static_cast<int>(roundf(num * (1 << bits)));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : fpoint(other.fpoint) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
        this->fpoint = other.fpoint;
    return  *this;
}

int Fixed:: getRawBits(void) const {
    std::cout << "getRawBits function called" << std::endl;
    return this->fpoint;
}

void Fixed::setRawBits(int const raw) {
    this->fpoint = raw;
}

float Fixed::toFloat(void) const {
    return fpoint / (float)(1 << bits);
}

int Fixed::toInt(void) const {
    return fpoint / (1 << bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& comop) const {
    return this->fpoint>comop.fpoint;
}

bool Fixed::operator<(const Fixed& comop) const {
    return this->fpoint<comop.fpoint;
}

bool Fixed::operator>=(const Fixed& comop) const {
    return this->fpoint>=comop.fpoint;
}

bool Fixed::operator<=(const Fixed& comop) const {
    return this->fpoint<=comop.fpoint;
}

bool Fixed::operator==(const Fixed& comop) const {
    return this->fpoint==comop.fpoint;
}

bool Fixed::operator!=(const Fixed& comop) const {
    return this->fpoint!=comop.fpoint;
}

Fixed Fixed::operator+(const Fixed& aritmop) const {
    Fixed val;
    val.fpoint = this->fpoint + aritmop.fpoint;
    return val;
}

Fixed Fixed::operator-(const Fixed& aritmop) const {
    Fixed val;
    val.fpoint = this->fpoint - aritmop.fpoint;
    return val;
}

Fixed Fixed::operator*(const Fixed& aritmop) const {
    Fixed val;
    int64_t product = int64_t(this->fpoint) * int64_t(aritmop.fpoint);
    int64_t scale = int64_t(1) << bits;
    int64_t adjusted;
    if (product >= 0)
        adjusted = product + scale / 2;
    else
        adjusted = product - scale / 2;
    int result = static_cast<int>(adjusted / scale);
    val.fpoint = result;
    return val;
}
