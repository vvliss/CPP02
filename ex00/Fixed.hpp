#pragma once
#include <string>
#include <iostream>

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
};