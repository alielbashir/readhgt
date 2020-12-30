//
// Created by ali on 12/25/20.
//
#include "readhgt.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sys/stat.h>
#include <math.h>

HGT convert(HGT src, const int range[2]) {
    HGT hgt(1201);
    hgt.min = range[0];
    hgt.max = range[1];
    int outMin = range[0];
    int outMax = range[1];
    double inDiff = src.max - src.min;
    double outDiff = outMax - outMin;
    int n = src.size;
    double temp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp = (((double) (src.arr[i][j] - src.min) * outDiff) / (double) inDiff) + outMin;
            hgt.arr[i][j] = (u_int8_t) temp;
            std::cout << src.arr[i][j] << " ";
        }

        std::cout << "\n";
    }
    return hgt;
}

long GetFileSize(std::string filename) {
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}


HGT readhgt(const std::string &path) {

    std::ifstream input(path, std::ios::binary | std::ios::in); // construct file object as binary
    std::ofstream output("log.txt", std::ios::out);
    long filesize = GetFileSize(path);
    int n = sqrt(filesize / 2); // 3-second arc photo size
    HGT hgt(n);
    std::vector<std::vector<PIXEL>> arr(n, std::vector<PIXEL>(n));
    PIXEL pixel;
    if (!input.is_open()) {
        std::cout << "error opening file\n";
        exit(1);
    }
    input.seekg(0);
    input.read((char *) &pixel, 2);
    pixel = (pixel >> 8) | (pixel << 8);
    int max = pixel;
    int min = pixel;
    input.seekg(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input.read((char *) &pixel, 2);
            pixel = (pixel >> 8) | (pixel << 8);

            // if void set to min
            if (pixel > 65400) {
                arr[i][j] = min;
            } else {
                arr[i][j] = pixel;
            }
            output << std::to_string(arr[i][j]) << " ";
            if (arr[i][j] > max) {
                max = arr[i][j];
            } else if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
        output << "\n";
    }
    hgt.arr = arr;
    hgt.max = max;
    hgt.min = min;
//    std::cout << "minimum = " << hgt.min << "\n";
//    std::cout << "maximum = " << hgt.max << "\n";
    return hgt;
}


