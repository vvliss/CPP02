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
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);