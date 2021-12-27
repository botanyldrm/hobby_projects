#include "Stabilizer.h"

Stabilizer::Stabilizer(std::string extractor_type):m_feature_extractor_type(extractor_type)
{
    m_matcher = cv::DescriptorMatcher::create(cv::DescriptorMatcher::FLANNBASED);
    
}

std::vector<cv::DMatch> Stabilizer::featureMatcher(cv::Mat descriptors1, cv::Mat descriptors2)
{

    std::vector< std::vector<cv::DMatch> > knn_matches;
    m_matcher->knnMatch( descriptors1, descriptors2, knn_matches, 2 );

    const float ratio_thresh = 0.7f;
    std::vector<cv::DMatch> good_matches;
    for (size_t i = 0; i < knn_matches.size(); i++)
    {
        if (knn_matches[i][0].distance < ratio_thresh * knn_matches[i][1].distance)
        {
            good_matches.push_back(knn_matches[i][0]);
        }
    }
    return good_matches;
}


cv::Mat Stabilizer::getStabilizedImage(cv::Mat gray_img)
{
    if(m_img_counter == 0)
    {
        m_img_counter += 1;
        m_feature_extractor.getFeatures(gray_img, m_base_keypoints, m_base_descriptors, m_feature_extractor_type);
        return gray_img;
    }
    else
    {
        
        m_img_counter += 1;
        std::vector<cv::KeyPoint> current_keypoints;
        cv::Mat current_descriptors;
        m_feature_extractor.getFeatures(gray_img, current_keypoints, current_descriptors, m_feature_extractor_type);

        std::vector<cv::DMatch> good_matches = featureMatcher(m_base_descriptors, current_descriptors);

        std::vector<cv::Point2f> srcPoints;
        std::vector<cv::Point2f> dstPoints;

        for (size_t i = 0; i < good_matches.size(); i++) 
        {
            srcPoints.push_back(m_base_keypoints[good_matches[i].queryIdx].pt);
            dstPoints.push_back(current_keypoints[good_matches[i].trainIdx].pt);
        }
        cv::Mat H = cv::findHomography(dstPoints, srcPoints, cv::RANSAC, 1);

        cv::Mat warpedImage;
        cv::warpPerspective(gray_img, warpedImage, H, cv::Size(gray_img.cols, gray_img.rows));
        if((m_img_counter % m_update_frequency) == 0)
        {
            m_feature_extractor.getFeatures(warpedImage, m_base_keypoints, m_base_descriptors, m_feature_extractor_type);
        }
        return warpedImage;
    }
}