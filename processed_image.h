#ifndef PROCESSED_IMAGE_H
#define PROCESSED_IMAGE_H

#include <QObject>
#include <QWidget>
#include <QImage>
#include <QLabel>
#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

class ProcessedImage{
public:
    ProcessedImage(string img_name);
    ~ProcessedImage();

    void loadImage(string img_name);
    void displayImage();
    void displayOther(QImage* other_img);
    void saveConverted(QImage* img_name);

    // encoding

    vector<QImage> separateChannels(QImage img_to_separate);
    vector<vector<vector<int>>> channelsToValues(vector<QImage> channels);
    QImage RGBToYCbCr();
    // channels, height, width
    vector<vector<vector<int>>> downsampling(QImage img_other);
    // channels, blocks y, blocks x, values(1d) of 8x8 = 64 - stored this way to eliminate one layer of nesting
    vector<vector<vector<vector<int>>>> divideInto8x8(vector<vector<vector<int>>> data);
    static vector<float> DCT(vector<int> data);
    static void quantization(vector<vector<vector<vector<float>>>>& data);
     // channels, blocks y, blocks x, values(1d) of 8x8 = 64
    vector<vector<vector<vector<float>>>> performDCT(vector<vector<vector<vector<int>>>> data);
    vector<vector<int>> zigzagScan(vector<vector<vector<vector<float>>>> data);
    vector<vector<int>> RLE(vector<vector<int>> data);

    // Huffman encoding
    struct HuffmanNode {
        int value;
        int frequency;
        HuffmanNode* left;
        HuffmanNode* right;
        HuffmanNode(int value, int frequency);
        ~HuffmanNode();
    };
    struct HuffmanTree {
        int size;
        int capacity;
        HuffmanNode** array;
        HuffmanTree(int capacity);
        ~HuffmanTree();
    };
    static void swapHuffmanNode(HuffmanNode** a, HuffmanNode** b);
    static void minHeapify(HuffmanTree* tree, int id);
    static bool isSizeOne(HuffmanTree* tree);
    static HuffmanNode* extractMin(HuffmanTree* tree);
    static void insertTree(HuffmanTree* tree, HuffmanNode* node);
    static void buildTree(HuffmanTree* tree);
    static bool isLeaf(HuffmanNode* root);
    static HuffmanTree* createAndBuildTree(vector<int> values, vector<int> freq);
    static HuffmanNode* buildHuffmanTree(vector<int> values, vector<int> freq);
    static void generateCodes(HuffmanNode* root, string code, map<int, string>& huffman_codes);
    static map<int, string> getHuffmanCodes(vector<int> values, vector<int> freq);
    vector<vector<string>> HuffmanEncoding(vector<vector<int>> rle_data);

    void writeToFileEncoded(vector<vector<string>> data);
    void writeToFileMap();
    vector<vector<string>> encode();

    // decoding

    // Huffman decoding
    static void printHuffmanTree(HuffmanNode* root, string code);
    void callPrintHuffmanTree(vector<vector<int>> rle_data);
    static void generateHuffmanCodeMap(HuffmanNode* root, string code, map<string, int>& huffman_codes);
    vector<vector<int>> HuffmanDecoding(vector<vector<string>> encoded_data);
    vector<vector<int>> HuffmanDecodingFromFile(vector<vector<string>> encoded_data, vector<map<string, int>> codes);

    vector<vector<int>> RLEDecode(vector<vector<int>> data);
    vector<vector<vector<vector<int>>>> backToBlocksFromZigzag(vector<vector<int>> data);
    vector<float> IDCT(vector<int> block);
    void dequantization(vector<vector<vector<vector<float>>>>& data);
    vector<vector<vector<vector<int>>>> reverseDCT(vector<vector<vector<vector<int>>>> data);
    vector<vector<vector<int>>> reverseBlocks(vector<vector<vector<vector<int>>>> data);
    QImage upscaling(vector<vector<vector<int>>> data);
    QImage YCbCrToRGB(QImage img_to_convert);
    vector<vector<string>> readFromFileEncoded();
    vector<map<string, int>> readFromFileMap();
    QImage* decode(vector<vector<string>> encoded_data);
    QImage* decodeFromFile();
    QImage* decodeFromFiles();

private:
    QImage* img = nullptr;
    string img_name;
    QLabel* label = nullptr;
    int width;
    int height;
    int num_blocks_x_luminance;
    int num_blocks_y_luminance;
    int num_blocks_x_chrominance;
    int num_blocks_y_chrominance;
    vector<HuffmanNode*> tree_channels = {nullptr, nullptr, nullptr};
};

// for testing dct conversion back and forth
vector<vector<vector<vector<int>>>> castToInteger(vector<vector<vector<vector<float>>>> data);

#endif // PROCESSED_IMAGE_H

// concept based on: https://www.baeldung.com/cs/jpeg-compression
// conversion of RGB to YCbCr: https://sistenix.com/rgb2ycbcr.html
// discrete cosine transform: https://eng.libretexts.org/Bookshelves/Electrical_Engineering/Signal_Processing_and_Modeling/Information_and_Entropy_(Penfield)/03%3A_Compression/3.08%3A_Detail-_2-D_Discrete_Cosine_Transformation/3.8.02%3A_Discrete_Cosine_Transformation
//                            https://www.geeksforgeeks.org/discrete-cosine-transform-algorithm-program/
// Huffman coding: https://www.youtube.com/watch?v=iEm1NRyEe5c&ab_channel=PizzeyTechnology
//                 https://www.dcode.fr/huffman-tree-compression
//                 https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
