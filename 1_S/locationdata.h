#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <string>

struct LocationData
{
    uint64_t timestamp;
    double lat;
    double lon;
    double alt;
    double speed;
    double direction;
    float horAcc;
    float verAcc;
};