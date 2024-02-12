#include <string>

/**
 * @brief Compliant design #1
 * The GnssCorrectionDownloader class depends on the GnssCloudService abstraction, not on specific implementations of the service.
 * This allows for flexibility and extensibility, as different implementations of GnssCloudService can be used without modifying the GnssCorrectionDownloader class.
 */
class GnssCloudService
{
public:
    virtual std::string downloadCorrectionData() = 0;
};

class UbloxPointPerfectService : public GnssCloudService
{
public:
    virtual std::string downloadCorrectionData() override
    {
        return "UBlox PointPerfect corrections";
    }
};

class TrimbleRTXService : public GnssCloudService
{
public:
    virtual std::string downloadCorrectionData() override
    {
        return "Trimble RTX corrections";
    }
};

class TopconTopNetLiveService : public GnssCloudService
{
public:
    virtual std::string downloadCorrectionData() override
    {
        return "TopCon TopNet Live corrections";
    }
};

class NovatelTerraStarService : public GnssCloudService
{
public:
    virtual std::string downloadCorrectionData() override
    {
        return "NovAtel TerraStar corrections";
    }
};

//...

class GnssCorrectionDownloader
{
public:
    GnssCorrectionDownloader(GnssCloudService* pService)
    {
        mCorrectionService = pService;
    }

    void downloadCorrectionData()
    {
        std::string corrections = mCorrectionService->downloadCorrectionData();
        
        // Process correction data
    }

private:
    GnssCloudService* mCorrectionService;
};