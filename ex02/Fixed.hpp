#pragma once
#include <string>
#include <iostream>
#include <cmath>

class Fixed {
    private:
        int fpoint = 0;
        static const int bits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other); //cpy const
        Fixed& operator=(const Fixed& other);
        int getRawBits(void) const;
        void setRawBits(int const raw);

        Fixed(const int num);
        Fixed(const float num);
        float toFloat(void) const;
        int toInt(void) const;

        bool operator>(const Fixed& comop) const;
        bool operator<(const Fixed& comop) const;
        bool operator>=(const Fixed& comop) const;
        bool operator<=(const Fixed& comop) const;
        bool operator==(const Fixed& comop) const;
        bool operator!=(const Fixed& comop) const;

        Fixed operator+(const Fixed& aritmop) const;
        Fixed operator-(const Fixed& aritmop) const;
        Fixed operator*(const Fixed& aritmop) const;
        Fixed operator/(const Fixed& aritmop) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b); 
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);