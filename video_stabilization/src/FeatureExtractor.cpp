#include "FeatureExtractor.h"

FeatureExtractor::FeatureExtractor()
{
    m_surf_detector = cv::xfeatures2d::SURF::create( m_minHessian );
    m_sift_detector = cv::SiftFeatureDetector::create();
}

void FeatureExtractor::getSurfFeatures(cv::Mat gray_img, std::vector<cv::KeyPoint> &keypoints, cv::Mat &descriptors)
{
    m_surf_detector->detectAndCompute( gray_img, cv::noArray(), keypoints, descriptors);
}

void FeatureExtractor::getSiftFeatures(cv::Mat gray_img, std::vector<cv::KeyPoint> &keypoints, cv::Mat &descriptors)

{
    m_sift_detector->detectAndCompute( gray_img, cv::noArray(), keypoints, descriptors);
}

void FeatureExtractor::getFeatures(cv::Mat gray_img, std::vector<cv::KeyPoint> &keypoints, cv::Mat &descriptors, std::string extractor_type)
{
    if(!extractor_type.compare("SURF"))
        getSurfFeatures( gray_img, keypoints, descriptors);
    else if(!extractor_type.compare("SIFT"))
        getSiftFeatures( gray_img, keypoints, descriptors);
}