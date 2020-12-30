//
// Created by ali on 12/25/20.
//
#include "readhgt.h"
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <cmath>

long GetFileSize(const std::string& filename) {
    struct stat stat_buf{};
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}


HGT readhgt(const std::string &path) {

    std::ifstream input(path, std::ios::binary | std::ios::in); // construct file object as binary
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
            if (arr[i][j] > max) {
                max = arr[i][j];
            } else if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    hgt.arr = arr;
    hgt.max = max;
    hgt.min = min;

    return hgt;
}


