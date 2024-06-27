#ifndef TESTS_H
#define TESTS_H

#include "processed_image.h"

// testing color conversion
void colorConversion(ProcessedImage& image);
// testing correctness of the dimensions
void dimensions(ProcessedImage& image);
// RLE testing
void conversionsTesting(ProcessedImage& image);
// testing upscaling
void scaling(ProcessedImage& image);
// testing reverse zigzag
void zigzagTest(ProcessedImage& image);
// testing Huffman decoding
void HuffmanTesting(ProcessedImage& image);
// testing reversing blocks
void blocksTesting(ProcessedImage& image);
// testing reversing dct
void DCTTesting(ProcessedImage& image);
// no file is used
void performConversion(ProcessedImage &image);
// only encoded image is written to file, and decoded with the use of stored Huffman trees in the class
void performConversionWithFile(ProcessedImage &image);
// image and codes of the Huffman encoding are written in the separate files
void performConversionWithFiles(ProcessedImage &image);

#endif // TESTS_H
