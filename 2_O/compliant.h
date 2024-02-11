#include "locationdata.h"

/**
 * @brief Compliant design #1
 * In practice, the best way to achieve this with C++ is polymorphism.
 * With the use of abstract interfaces, we can extend a class 
 * and specialize its behaviour without changing the interface specification.
 */
class DeadReckoningEngine
{
public:
    virtual void updatePosition(LocationData& loc) = 0;
};

// Inertial Navigation System uses motion sensors (accelerometers), rotation sensors (gyroscopes)
// to continously calculate position, orientation and the velocity of a moving object without the need for external references.
class INS_System : public DeadReckoningEngine
{
public:
    virtual void updatePosition(LocationData& loc)
    {
        // Update position based on accelerometers and rotation sensor data
    }
};

// Doppler Velocity Logger is used for navigation systems of underwater vehicles.
class DVL_System : public DeadReckoningEngine
{
public:
    virtual void updatePosition(LocationData& loc)
    {
        // Update position based on the response of sound waves
    }
};

// Fiber-Optic Gyroscope are used to measure angular velocity and maintain orientation information.
class FOG_System : public DeadReckoningEngine
{
public:
    virtual void updatePosition(LocationData& loc)
    {
        // Update orientation and direction based on gyroscope data
    }
};

// Inertial Measurement Unit integrates accelerometers and gyroscopes on a single chip.
// It reports the acceleration and angular rate, sometimes the orientation of the motion object.
class IMU_System : public DeadReckoningEngine
{
public:
    virtual void updatePosition(LocationData& loc)
    {
        // Update position based on acceleration and angular rate data
    }
};

class ClientApplication
{
public:
    void setDREngine(DeadReckoningEngine* engine)
    {
        mEngine = engine;
    }

    void updatePosition()
    {
        mEngine->updatePosition(mLoc);
    }

private:
    DeadReckoningEngine* mEngine;
    LocationData mLoc;
};