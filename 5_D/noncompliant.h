#include <string>

/**
 * @brief Non-compliant design #1
 * The high-level componet depends on a low-level functionality. This is fine.
 * But they depend on an interface. It means that they are coupled to a very specific implementation.
 * At some point, if the system needs to use another correction cloud service, we will need to reimplement GnssCorrectionDownloader class.
 */
class GnssCloudService
{
public:
    std::string downloadPointPerfectCorrections()
    {
        return "Ublox PointPerfect corrections";
    }
};

class GnssCorrectionDownloader
{
public:
    GnssCorrectionDownloader(GnssCloudService* pService)
    {
        mCorrectionService = pService;
    }

    void downloadCorrectionData()
    {
        std::string corrections = mCorrectionService->downloadPointPerfectCorrections();
        
        // Process correction data
    }

private:
    GnssCloudService* mCorrectionService;
};
