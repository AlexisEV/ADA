
#include <iostream>
#include <stdexcept>

float Addition(float a, float b) {
	return a + b;
}

float Subtraction(float a, float b) {
	return a - b;
}

float Multiplication(float a, float b) {
	return a * b;
}

float Division(float a, float b) {
	if (b == 0) {
		throw std::runtime_error("Error: Division by zero.");
	}
	return a / b;
}

int main()
{
	// Code B
	// User type to simplify the declaration
	typedef float (*lpfnOperation)(float, float);
	// CVector of pointer to functions
	lpfnOperation vpf[4] = { &::Addition, &::Subtraction,
	&::Multiplication, &::Division };
	float a, b, c; int opt;
	// enter the operands
	std::cout << "Ingrese los operandos a y b : ";
	std::cin >> a >> b;
	// enter the operation 0-Addition, 1-Subtraction, 3-Multiplication, 4-Division
	std::cout << "Ingrese la operacion (0-Addition, 1-Subtraction, 2-Multiplication, 3-Division): ";
	std::cin >> opt;
	// The next line replaces the switch and replaces the whole switch
	c = (*vpf[opt])(a, b);
	std::cout << "\nLa respuesta es: " << c;
}
