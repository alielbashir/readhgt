#include <iostream>
#include <opencv2/opencv.hpp>

#include "readhgt.h"
#define path "files/N42E104.hgt"
using namespace cv;
int main() {

    HGT hgt = readhgt(path);
    int range[] = {0, 255};
    convert(hgt, range);
    std::cout << hgt.arr.size() << " " << hgt.arr.at(1200).size() << "\n";
    std::cout << hgt.arr.at(0).at(0) << " " << hgt.arr.at(1200).at(45);
//    int arr[4][4];
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            arr[i][j] = 1;
//        }
//    }
    Mat mat(hgt.arr.size(), hgt.arr.at(0).size(), CV_8UC1);
    for (int i = 0; i < mat.rows; i++) {
        std::cout << "\n" << i;
        for (int j = 0; j < mat.cols; j++) {
            mat.at<uint8_t>(i, j) = hgt.arr.at(i).at(j);
        }
    }
//    Mat mat2(100, 100, CV_8UC1);
//    for (int i = 0; i < mat2.rows; i++) {
//        for (int j = 0; j < mat2.cols; j++) {
//            mat2.at<PIXEL>(i, j) = (PIXEL) 65535;
//        }
//    }
    imshow("hgt", mat);
    waitKey(0);
    return 0;
}