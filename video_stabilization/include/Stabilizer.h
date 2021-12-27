
#include "FeatureExtractor.h"
#include <opencv2/calib3d.hpp>

class Stabilizer
{
    public:
        Stabilizer(std::string extractor_type);
        std::vector<cv::DMatch> featureMatcher(cv::Mat descriptors1, cv::Mat descriptors2);
        cv::Mat getStabilizedImage(cv::Mat gray_img);

    private:
        cv::Ptr<cv::DescriptorMatcher> m_matcher;
        std::string m_feature_extractor_type = "SURF";
        FeatureExtractor m_feature_extractor;
        int m_img_counter = 0;
        int m_update_frequency = 10;

        std::vector<cv::KeyPoint> m_base_keypoints;
        cv::Mat m_base_descriptors;


};

