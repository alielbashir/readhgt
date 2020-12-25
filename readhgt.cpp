//
// Created by ali on 12/25/20.
//
#include "readhgt.h"
#include <fstream>
#include <iostream>

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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input.read((char *) &pixel, 2);
            arr[i][j] = pixel;
        }
    }
    hgt.arr = arr;
    return hgt;
}


