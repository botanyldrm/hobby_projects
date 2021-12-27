#ifndef FEATURE_EXTRACTOR_H
#define FEATURE_EXTRACTOR_H

#include<opencv2/imgproc.hpp>
#include "opencv2/xfeatures2d.hpp"

class FeatureExtractor
{
    public:
        FeatureExtractor();
        // std::vector<cv::KeyPoint> getSurfFeatures(cv::Mat gray_img);
        void getSurfFeatures(cv::Mat gray_img, std::vector<cv::KeyPoint> &keypoints, cv::Mat &descriptors);
        void getSiftFeatures(cv::Mat gray_img, std::vector<cv::KeyPoint> &keypoints, cv::Mat &descriptors);
        void getFeatures(cv::Mat gray_img, std::vector<cv::KeyPoint> &keypoints, cv::Mat &descriptors, std::string extractor_type);

    private:
        int m_minHessian = 400;
        cv::Ptr<cv::xfeatures2d::SURF> m_surf_detector;
        cv::Ptr<cv::SiftFeatureDetector> m_sift_detector;

};
#endif //FEATURE_EXTRACTOR_H

