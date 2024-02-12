/**
 * @brief Demonstration of the Interface segregation principle in OOP design.
 * The Interface Segregation Principle states that a class should not be forced to implement interfaces that it doesn't use.
 * This principle helps in keeping classes focused and prevents them from becoming bloated with unnecessary methods.
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include "compliant.h"

int main()
{
	HardwareAdapterLayer::UART serial;

	char buffer[1024];
	serial.readViaUART(buffer, 1024);
	return 0;
}
