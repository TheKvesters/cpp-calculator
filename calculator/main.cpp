#include "calculator.h"

int main()
{

	bool cycle_success = false;

	try
	{
		cycle_success = RunCalculatorCycle();
	}
	catch (const std::exception &error)
	{
		std::cerr << error.what();
	}

	return cycle_success ? 0 : 1;
}
