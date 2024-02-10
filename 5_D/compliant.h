#include "locationdata.h"

/**
 * @brief Compliant design #1
 * In this improved version, the responsibilities of parsing NMEA and UBX data are handled by separate NmeaParser and UbxParser classes.
 * The LocationProvider class is now focused solely on coordinating the data processing based on the format
 */
class NmeaParser
{
public:
    LocationData parseNmeaData(const std::string& data)
    {
        // Parse string data following NMEA format
        // Return parsed location data
    }
};

class UbxParser
{
public:
    LocationData parseUbxData(const std::string& data)
    {
        // Parse string data following UBX format
        // Return parsed location data
    }
};

class LocationProvider
{
private:
    NmeaParser nmeaParser;
    UbxParser ubxParser;

public:
    LocationData processData(const std::string& data, const std::string& format)
    {
        LocationData loc;
        if (format == "NMEA")
        {
            loc = nmeaParser.parseNmeaData(data);
        }
        else if (format == "UBX")
        {
            loc = ubxParser.parseUbxData(data);
        }
        else
        {
            // Handle unsupported format
        }
        return loc;
    }
};

/**
 * @brief Compliant design #2
 * The responsibilities have been divided to the separated classes.
 */
class GnssDataReader
{
public:
    std::string readGnssData()
    {
        // Open GNSS filesystem and read raw data from it
        // std::string raw_data = file.open("/dev/gnss").read();
        // return raw_data;
    }
};

class LocationUtils
{
public:
    static double calculateDistance(const LocationData& from, const LocationData& to)
    {
        // Calculate the distance between two locations
        // ...
        // return distance;
    }
};

class LocationStorage
{
public:
    void storeLocation(const LocationData& data)
    {
        // Store the current Location data to NVM (non-volatile memory)
        // ...
    }

    void reloadLocation(LocationData& data)
    {
        // Reload the latest fix position from NVM (non-volatile memory)
        // ...
    }
};

class GnssConfigManager
{
public:
    void readVehicleConfigs()
    {
        // Read the vehicle configs and apply them to the GNSS chipset
        // ...
    }

    void writeVehicleConfigs()
    {
        // Write the vehicle configs to the GNSS chipset
        // ...
    }
};

class LocationService
{
private:
    LocationData mData;
    LocationStorage mStorage;
    GnssConfigManager mConfigManager;

public:
    void updateLocation(const LocationData& data)
    {
        mData = data;
        notifyLocationUpdate();
    }

    void getLocationData(LocationData& loc_data)
    {
        loc_data = mData;
    }

    void processGnssData()
    {
        GnssDataReader reader;
        std::string raw_data = reader.readGnssData();

        LocationData loc;
        NmeaParser nmeaParser;
        loc = nmeaParser.parseNmeaData(raw_data);

        updateLocation(loc);
    }

    void notifyLocationUpdate()
    {
        // Notify location updates to registered services/applications
        // ...
    }

    void storeLocationData()
    {
        mStorage.storeLocation(mData);
    }

    void reloadLocationData()
    {
        mStorage.reloadLocation(mData);
    }

    void readVehicleConfigs()
    {
        mConfigManager.readVehicleConfigs();
    }

    void writeVehicleConfigs()
    {
        mConfigManager.writeVehicleConfigs();
    }
};

/**
 * @brief Compliant design #3
 * 
 */
class SatelliteSignalChecker
{
public:
    void checkSignalStrength()
    {
        // Code to check satellite signal strength
    }

    void checkSignalQuality()
    {
        // Code to check satellite signal quality
    }
};

class PositionAccuracyChecker
{
public:
    void checkAccuracy()
    {
        // Code to check the accuracy of the GNSS position
    }
};

class DiagnosticsLogger
{
public:
    void logDiagnosticsData()
    {
        // Code to log diagnostics data to a file
    }
};

class DiagnosticsReporter
{
public:
    void sendDiagnosticsReport()
    {
        // Code to send the diagnostics report to a remote server
    }
};

class GnssDiagnosticsService
{
private:
    SatelliteSignalChecker signalChecker;
    PositionAccuracyChecker accuracyChecker;
    DiagnosticsLogger diagnosticsLogger;
    DiagnosticsReporter diagnosticsReporter;

public:
    void performDiagnostics()
    {
        signalChecker.checkSignalStrength();
        signalChecker.checkSignalQuality();
        accuracyChecker.checkAccuracy();
        diagnosticsLogger.logDiagnosticsData();
        diagnosticsReporter.sendDiagnosticsReport();
    }
};