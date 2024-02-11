#include "locationdata.h"

/**
 * @brief Non-compliant design #1
 * Every time a new model is added, the switch statement would need to be modified,
 * making the code open for modification than closed for modification.
 */
enum EngineType
{
    INERTIAL_NAVIGATION_SYSTEM,
    DOPPLER_VELOCITY_LOGGER,
    FIBER_OPTIC_GYROSCOPE,
    INERITAL_MEASUREMENT_UNIT,
    TOTAL_ENGINE
};

class ClientApplication
{
public:
    void updatePositionForModel(enum EngineType model)
    {
        switch (model)
        {
            case EngineType::INERTIAL_NAVIGATION_SYSTEM:
            {
                updatePositionWithINS(mLoc);
                break;
            }
            case EngineType::DOPPLER_VELOCITY_LOGGER:
            {
                updatePositionWithDVL(mLoc);
                break;
            }
            case EngineType::FIBER_OPTIC_GYROSCOPE:
            {
                updatePositionWithFOG(mLoc);
                break;
            }
            case EngineType::INERITAL_MEASUREMENT_UNIT:
            {
                updatePositionWithIMU(mLoc);
                break;
            }
            default:
            {
                break;
            }
        }
    }
private:
    void updatePositionWithINS(LocationData& loc)
    {
    }

    void updatePositionWithDVL(LocationData& loc)
    {
    }

    void updatePositionWithFOG(LocationData& loc)
    {
    }

    void updatePositionWithIMU(LocationData& loc)
    {
    }

private:
    LocationData mLoc;
};