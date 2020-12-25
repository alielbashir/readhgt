#include <iostream>
#include <opencv2/opencv.hpp>

#include "readhgt.h"
#define path "files/N42E104.hgt"
using namespace cv;
int main() {

    HGT hgt = readhgt(path);

    std::cout << hgt.arr.size() << " " << hgt.arr.at(1200).size() << "\n";
    std::cout << hgt.arr.at(0).at(0) << " " << hgt.arr.at(1200).at(45);
    imshow("hgt", hgt.arr);
    waitKey(0);
    return 0;
}