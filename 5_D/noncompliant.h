#include "locationdata.h"

/**
 * @brief Non-compliant design #1
 * The class is responsible for processing data, parsing NMEA data, and parsing UBX data, 
 * which indicates that it has multiple reasons to change and takes on multiple responsibilities.
 */
class LocationProvider
{
public:
    LocationData processData(const std::string& data, const std::string& format)
    {
        LocationData loc;
        if (format == "NMEA")
        {
            loc = parseNmeaData(data);
        }
        else if (format == "UBX")
        {
            loc = parseUbxData(data);
        }
        else
        {
            // Handle unsupported format
        }
        return loc;
    }

    LocationData parseNmeaData(const std::string& data)
    {
        // Parse string data following NMEA format
    }

    LocationData parseUbxData(const std::string& data)
    {
        // Parse string data following UBX format
    }
};


/**
 * @brief Non-compliant design #2
 * The LocationService class is responsible for multiple disparate tasks.
 * Such as, obtain location data, store/reload location data, calculating distances, read vehicle configurations...
 */
class LocationService
{
public:
    void ReadGnssData()
    {
        // const std::string FS = "/dev/gnss";
        
        // Open GNSS filesystem and read raw data from it
        // std::string raw_data = file.open(FS).read();

        // static LocationProvider provider;
        // LocationData loc = provider.processData(raw_data, "NMEA");

        // UpdateCurrentLocation(loc);
    }

    void UpdateCurrentLocation(const LocationData& data)
    {
        mData = data;

        // Notify location updates to registered services/applications
        // ...   
    }

    void GetLocationData(LocationData& loc_data)
    {
        loc_data = mData;
    }

    void StoreLocation()
    {
        // Store the current Location data to NVM (non-volatile memory)
        // ...
    }

    void ReloadLocation()
    {
        // Reload the latest fix position from NVM (non-volatile memory)
        // ...
    }

    double CalculateDistance(const LocationData& from, const LocationData& to)
    {
        return 0.0f;
    }

    void LoadVehicleConfigs()
    {
        // Read the vehicle configs and apply them
        // ...
    }

private:
    LocationData mData;
};

/**
 * @brief Non-compliant design #3
 * Sometimes, the non-compliant design appears in a slightly more subtle form.
 * The GnssDiagnosticsService class is responsible for performing GNSS diagnostics:
 * Checking satellite signal, checking position accuracy, logging diagnostics data, and sending the diagnostics report.
 * While each method is related to the overall diagnostics process, the class still has multiple responsibilities.
 */
class GnssDiagnosticsService
{
public:
    void performDiagnostics()
    {
        // Code to perform GNSS diagnostics
        checkSatelliteSignal();
        checkPositionAccuracy();
        createDiagnosticsReport();
        sendDiagnosticsReport();
    }

    void checkSatelliteSignal()
    {
        // Code to check satellite signal strength and quality
    }

    void checkPositionAccuracy()
    {
        // Code to check the accuracy of the GNSS position
    }

    void createDiagnosticsReport()
    {
        // Code to log diagnostics data to a file
    }

    void sendDiagnosticsReport()
    {
        // Code to send the diagnostics report to a remote server
    }
};