/**
 * @brief Demonstration of the Open/Closed principle in OOP design.
 * The Open/Closed principle states that software entities should be open for extension, but closed for modification.
 * This allows new functionality to be added without changing existing source code.
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include "compliant.h"

int main()
{
	ClientApplication app;
	app.setDREngine(new IMU_System());
	app.updatePosition();
	return 0;
}
