#include "Fixed.hpp"

Fixed::Fixed() : fpoint(0) {
    std::cout << "Default constructor called" << std::endl;
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