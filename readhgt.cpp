//
// Created by ali on 12/25/20.
//
#include "readhgt.h"
#include <fstream>
#include <iostream>
#include <algorithm>

void convert(HGT src, const int range[2]) {
    // FIXME: endiannes is wrong, sharp edges in image
    double outMin = range[0];
    double outMax = range[1];
    double inDiff = src.max - src.min;
    double outDiff = outMax - outMin;
    int n = src.size;
    double temp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp = src.arr[i][j] - src.min;
            temp /= inDiff;
            temp *= (outDiff + outMin);
            src.arr[i][j] = (uint8_t) temp;
            std::cout << src.arr[i][j] << " ";
        }

        std::cout << "\n";
    }
}

HGT readhgt(const std::string &path) {
    std::ifstream input(path, std::ios::binary | std::ios::in); // construct file object as binary
    int n = 1201; // 3-second arc photo size
    HGT hgt(n);
    std::vector<std::vector<PIXEL>> arr(n, std::vector<PIXEL>(n));
    PIXEL pixel;
    if (!input.is_open()) {
        std::cout << "error opening file\n";
        exit(1);
    }
    input.seekg(1);
    int max;
    int min;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input.read((char *) &pixel, 2);
            if (i == 0 && j == 0) {
                min = pixel;
                max = pixel;
            }
            arr[i][j] = pixel;
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


