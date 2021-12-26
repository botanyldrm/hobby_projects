#include "DataLoader.h"
#include <sys/types.h>
#include <dirent.h>
#include <exception>


DataLoader::DataLoader(cv::String video_pth)
{
    cap.open(video_pth);
    if(!cap.isOpened()){
	    std::cout << "Error opening video stream or file" << std::endl;
	    throw std::exception();
	  }
}

cv::Mat DataLoader::getBGRImage()
{
    cv::Mat bgr_img;
    cap >> bgr_img;
    if (bgr_img.empty())
        throw std::exception();
    return bgr_img;
}

cv::Mat DataLoader::getGrayImage()
{
    cv::Mat bgr_img;
    cap >> bgr_img;
    if (bgr_img.empty())
        throw std::exception();
    cv::Mat gray_img;
    cv::cvtColor(bgr_img, gray_img, cv::COLOR_BGR2GRAY);
    return gray_img;
}
