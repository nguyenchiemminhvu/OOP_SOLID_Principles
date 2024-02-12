/**
 * @brief Demonstration of the Liskov substituation principle in OOP design.
 * The Liskov Substituation Principle (SRP) states that objects of a superclass should be replaceable with objects of its subclass without affecting the correctness of the program.
 * This means that a subclass should be able to substitute its parent class without changing the behavior of the program.
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include "compliant.h"

int main()
{
	DrEngine engine;
	engine.updatePosition();
	return 0;
}
