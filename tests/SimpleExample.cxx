// Copyright 2022 Joseph McKenna [legal/copyright]

#include "ErrorCombination.h"

#include <iostream>

int main() {
    edouble a(4);
    edouble b(9);

    edouble c = a + b;
    edouble d = a - b;
    edouble e = a * b;
    edouble f = a / b;
    std::cout << a << " + " << b << " = " << c << std::endl;
    std::cout << a << " - " << b << " = " << d << std::endl;
    std::cout << a << " * " << b << " = " << e << std::endl;
    std::cout << a << " / " << b << " = " << f << std::endl;

    edouble g = a * 2.0;
    edouble h = 2.0 * a;
    std::cout << a << " * " << 2.0 << " = " << g << std::endl;
    std::cout << 2.0 << " * " << a << " = " << h << std::endl;

    edouble j = a / 2.0;
    edouble k = 2.0 / a;
    std::cout << a << " * " << 2.0 << " = " << j << std::endl;
    std::cout << 2.0 << " / " << a << " = " << k << std::endl;

    edouble l = sqrt(a);
    edouble m = pow(a, 2);
    edouble n = a*a;
    std::cout << "sqrt(" << a << ") = " << l << std::endl;
    std::cout << "pow(" << a << ",2) = " << m << std::endl;
    std::cout << a << "*" << a << " = " << n << std::endl;

    // Output:
    //
    // (4 +/- 2) + (9 +/- 3) = (13 +/- 3.60555)
    // (4 +/- 2) - (9 +/- 3) = (-5 +/- 3.60555)
    // (4 +/- 2) * (9 +/- 3) = (36 +/- 21.6333)
    // (4 +/- 2) / (9 +/- 3) = (0.444444 +/- 0.267078)
    // (4 +/- 2) * 2 = (8 +/- 4)
    // (4 +/- 2) * 2 = (2 +/- 1)

    return 0;
}
