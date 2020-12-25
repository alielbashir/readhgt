//
// Created by ali on 12/25/20.
//
#ifndef READHGT_READHGT_H
#define READHGT_READHGT_H

#include <cstdint>
#include <vector>
#include <array>
#include <cstdint>
#include <string>

// BMP-related data types based on Microsoft's own


/**
 * Common Data Types
 *
 * The data types in this section are essentially aliases for C/C++
 * primitive data types.
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/cc230309.aspx.
 * See http://en.wikipedia.org/wiki/Stdint.h for more on stdint.h.
 */
typedef uint8_t BYTE;
typedef uint32_t DWORD;
typedef int32_t LONG;
typedef uint16_t PIXEL;

/**
 * BITMAPFILEHEADER
 *
 * The BITMAPFILEHEADER structure contains information about the type, size,
 * and layout of a file that contains a DIB [device-independent bitmap].
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/dd183374(VS.85).aspx.
 */
typedef struct {
    PIXEL bfType;
    DWORD bfSize;
    PIXEL bfReserved1;
    PIXEL bfReserved2;
    DWORD bfOffBits;
} __attribute__((__packed__))
        BITMAPFILEHEADER;

/**
 * BITMAPINFOHEADER
 *
 * The BITMAPINFOHEADER structure contains information about the
 * dimensions and color format of a DIB [device-independent bitmap].
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/dd183376(VS.85).aspx.
 */
typedef struct {
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    PIXEL biPlanes;
    PIXEL biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} __attribute__((__packed__))
        BITMAPINFOHEADER;

/**
 * RGBTRIPLE
 *
 * This structure describes a color consisting of relative intensities of
 * red, green, and blue.
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/aa922590.aspx.
 */
typedef struct {
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} __attribute__((__packed__))
        RGBTRIPLE;

class HGT {
public:
    int size;
    std::vector<std::vector<PIXEL>> arr;
    HGT(int size) {
        this->size = size;
        this->arr.resize(size);
        for (int i = 0; i < size; i++) {
            this->arr.at(i).resize(size);
        }
    }
};

HGT readhgt(const std::string &path);

#endif //READHGT_READHGT_H
