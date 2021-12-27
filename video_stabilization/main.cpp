#include "./include/DataLoader.h"
#include "./include/Stabilizer.h"

int main()
{
    cv::String video_pth = "/home/botan/workspace/hobby_projects/video_stabilization/resources/5.avi";
    DataLoader video_src = DataLoader(video_pth);
    std::string extractor_type = "SIFT";
    Stabilizer stabilizer(extractor_type);

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