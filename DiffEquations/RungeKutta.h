#pragma once

// This class performs Runge-Kutta method to solve ODEs of
// the form dy/dx = f(x,y)

#include <functional>

class RungeKutta {

//private properties
private:

	float _h;														// step size

// No public properties

//public methods
public:

	RungeKutta(float StepSize);										// Constructor
	~RungeKutta();													// Destructor
	float solve(float x0, float y0, float xend, std::function<float(float, float)> func);				//solve over an interval

// private methods
private:
	float step(float x, float y, std::function<float(float, float)> func);		//Perform a single step
};

// Note: std::function<outputType(InputType1, InputType2)> Name of function