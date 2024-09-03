#include <iostream>
#include "RungeKutta.h"

float func(float x, float y) {
    return x * y;                           // Example differential equation dy/dx = x * y
}

int main() {
    RungeKutta rk(0.01); // Step size of 0.01

    float x0 = 0.0;
    float y0 = 1.0; // Initial condition
    float x_end = 1.0;

    float result = rk.solve(x0, y0, x_end, func);

    std::cout << "The solution at x = " << x_end << " is y = " << result << std::endl;

    return 0;
}