#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;
    
    return 0;
}

// int main ( void ) {
//     Fixed x(3.5f);
//     Fixed y(2.0f);
    
//     std::cout << (x > y) << std::endl;
//     std::cout << (x < y) << std::endl;
//     std::cout << (x == y) << std::endl;
//     std::cout << (x + y) << std::endl;
//     std::cout << (x - y) << std::endl;
//     std::cout << (x / y) << std::endl;
    
//     Fixed z(5.0f);
//     std::cout << --z << std::endl;
//     std::cout << z-- << std::endl;
    
//     Fixed p(10.5f);
//     Fixed q(7.25f);
//     std::cout << Fixed::min(p, q) << std::endl;
//     std::cout << Fixed::max(p, q) << std::endl;
    
//     return 0;
// }
