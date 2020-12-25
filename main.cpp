#include <iostream>
#include <fstream>
#include <vector>
#include "readhgt.h"
#define path "files/ali.bin"

int main() {

    std::ifstream input(path, std::ios::binary | std::ios::in); // construct file object as binary
    std::vector<PIXEL> arr;
    PIXEL pixel;
    int i = 0;
    if (!input.is_open()) {
        std::cout << "error opening file\n";
        return 1;
    }
    input.seekg(1);
    while(!input.eof()) {
        input.read((char *) &pixel, 2);
        arr.push_back(pixel);
    }
    for (unsigned short px : arr) {
        std::cout << px << " ";
    }
    return 0;
}