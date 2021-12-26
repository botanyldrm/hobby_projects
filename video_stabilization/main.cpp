#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include "./include/DataLoader.h"
#include "./include/FeatureExtractor.h"
#include "./include/Stabilizer.h"

int main()
{
    cv::String video_pth = "/home/botan/workspace/hobby_projects/video_stabilization/resources/3.avi";
    DataLoader video_src = DataLoader(video_pth);
    FeatureExtractor feature_extractor;
    Stabilizer stabilizer;

    cv::Mat prev_gray_img;
    std::vector<cv::KeyPoint> prev_keypoints;
    cv::Mat prev_descriptors;

    int counter = 0;
    while(true)
    {
        cv::Mat gray_img = video_src.getGrayImage();
        cv::Mat stabilized_img = stabilizer.getStabilizedImage(gray_img);

        cv::imshow("gray_img", gray_img);
        cv::imshow("stabilized_img", stabilized_img);
        cv::waitKey(1);
    }

    return 0;
}