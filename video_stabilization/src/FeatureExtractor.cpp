#include "FeatureExtractor.h"
#include <sys/types.h>
#include <dirent.h>
#include <exception>


FeatureExtractor::FeatureExtractor()
{
    m_surf_detector = cv::xfeatures2d::SURF::create( m_minHessian );
    
}

// std::vector<cv::KeyPoint> FeatureExtractor::getSurfFeatures(cv::Mat gray_img, std::vector<cv::KeyPoint> &keypoints, cv::Mat &descriptors)
void FeatureExtractor::getSurfFeatures(cv::Mat gray_img, std::vector<cv::KeyPoint> &keypoints, cv::Mat &descriptors)

{
    // std::vector<cv::KeyPoint> keypoints;
    // cv::Mat descriptors;
    // m_surf_detector->detect( gray_img, keypoints );
    m_surf_detector->detectAndCompute( gray_img, cv::noArray(), keypoints, descriptors);
    // return keypoints;
}
