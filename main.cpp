#include <iostream>
#include <vector>
#include "readhgt.h"
#define path "files/N42E104.hgt"

int main() {

    std::vector<std::vector<PIXEL>> arr;
    arr = readhgt(path);
    std::cout << arr.size() << " " << arr.at(1200).size() << "\n";
    std::cout << arr.at(0).at(0) << " " << arr.at(1200).at(45);

    return 0;
}