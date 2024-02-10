/**
 * @file main.cpp
 * @author nguyenchiemminhvu@gmail.com
 * @brief Demonstration of the Single Responsibility principle in OOP design
 * @date 2024-02-10
 * 
 * The Single Responsibility Principle (SRP) states that a class should have only one reason to change, 
 * or in other words, it should have only one job or responsibility.
 */
#include "compliant.h"

int main()
{
    LocationService service;
    service.processGnssData();
    service.notifyLocationUpdate();
    service.storeLocationData();
    return 0;
}
