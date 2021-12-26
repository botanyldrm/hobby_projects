#ifndef FEATURE_EXTRACTOR_H
#define FEATURE_EXTRACTOR_H

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include <string>
#include <iostream>
#include <vector>

#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"

class FeatureExtractor
{
    public:
        FeatureExtractor();
        // std::vector<cv::KeyPoint> getSurfFeatures(cv::Mat gray_img);
        void getSurfFeatures(cv::Mat gray_img, std::vector<cv::KeyPoint> &keypoints, cv::Mat &descriptors);

    private:
        int m_minHessian = 400;
        cv::Ptr<cv::xfeatures2d::SURF> m_surf_detector;

};
#endif //FEATURE_EXTRACTOR_H

