#include "RungeKutta.h"


// Constructor
RungeKutta::RungeKutta(float stepSize) : _h(stepSize) {};			//Member initialisation

//Destrucot
RungeKutta::~RungeKutta() {};										//Destructor

// Method to perform a single step of the Runge-Kutta method
float RungeKutta::step(float x, float y, std::function<float(float, float)> func) {
    float k1 = _h * func(x, y);
    float k2 = _h * func(x + _h / 2.0, y + k1 / 2.0);
    float k3 = _h * func(x + _h / 2.0, y + k2 / 2.0);
    float k4 = _h * func(x + _h, y + k3);

    return y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
}

// Method to solve the ODE over an interval using the Runge-Kutta method
float RungeKutta::solve(float x0, float y0, float xend, std::function<float(float, float)> func) {
    float y = y0;
    for (float x = x0; x < xend; x += _h) {
        y = step(x, y, func);
    }
    return y;
}