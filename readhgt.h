//
// Created by ali on 12/25/20.
//
#ifndef READHGT_READHGT_H
#define READHGT_READHGT_H

#include <vector>
#include <array>
#include <cstdint>
#include <string>

typedef uint16_t PIXEL;

class HGT {
public:
    int size;
    PIXEL min{};
    PIXEL max{};
    std::vector<std::vector<PIXEL>> arr;
    explicit HGT(int size) {
        this->size = size;
        this->arr.resize(size);
        for (int i = 0; i < size; i++) {
            this->arr.at(i).resize(size);
        }
    }
};
HGT readhgt(const std::string &path);

#endif //READHGT_READHGT_H
