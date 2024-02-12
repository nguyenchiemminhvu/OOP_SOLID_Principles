/**
 * @brief Demonstration of the Dependency of Inversion principle in OOP design.
 * The Dependency of Inversion Principle states that High-level modules should not depend on low-level modules. Both should depend on abstractions (e.g. interfaces).
 * Abstractions should not depend on details. Details (concrete implementations) should depend on abstractions.
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include "compliant.h"

int main()
{
	GnssCorrectionDownloader downloader(new UbloxPointPerfectService());
	downloader.downloadCorrectionData();
	return 0;
}
