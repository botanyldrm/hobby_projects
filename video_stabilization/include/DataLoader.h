#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include <string>
#include <iostream>
#include <vector>

class DataLoader
{
    public:
        DataLoader(cv::String video_pth);
        cv::Mat getBGRImage();
        cv::Mat getGrayImage();
        cv::VideoCapture cap;
    private:
        int m_counter = 0;
        std::vector<std::string> m_image_paths;
};

