#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include "readhgt.h"
using namespace cv;
int main() {
    std::string root = "files/";
    std::cout << "Enter the coordinates: ";
    std::string coords;
    std::cin >> coords;
    std::string path = root.append(coords).append(".hgt");
    HGT hgt = readhgt(path);

    Mat mat2(hgt.arr.size(), hgt.arr.at(0).size(), CV_16UC1);
    for (int i = 0; i < mat2.rows; i++) {
        for (int j = 0; j < mat2.cols; j++) {
            mat2.at<uint16_t>(i, j) = hgt.arr.at(i).at(j);
        }
    }

    cv::Size newSize(600, 600);
    cv::resize(mat2, mat2, newSize);
    cv::normalize(mat2, mat2, 0, 65535, cv::NORM_MINMAX);
    imshow("hgt", mat2);
    waitKey(0);
    return 0;
}