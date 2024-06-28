#include "tests.h"

void colorConversion(ProcessedImage& image){
    image.displayImage();
    QImage converted = image.RGBToYCbCr();
    image.displayOther(&converted);
    converted = image.YCbCrToRGB(converted);
    image.displayOther(&converted);
}

void dimensions(ProcessedImage& image){
    QImage converted = image.RGBToYCbCr();
    converted = image.YCbCrToRGB(converted);
    cout << "After conversion to YCbCr: " << converted.height() << " " << converted.width() << endl << endl;
    vector<vector<vector<int>>> downsampled_data = image.downsampling(converted);
    cout << "After downsampling: " << endl;
    cout << downsampled_data[0].size() << " " << downsampled_data[0][0].size() << endl;
    cout << downsampled_data[1].size() << " " << downsampled_data[1][0].size() << endl;
    cout << downsampled_data[2].size() << " " << downsampled_data[2][0].size() << endl;
    vector<vector<vector<vector<int>>>> blocks = image.divideInto8x8(downsampled_data);
    cout << "Splitted into blocks: " << endl;
    cout << blocks[0].size() << " " << blocks[0][0].size() << " " << blocks[0][0][0].size() << endl;
    cout << blocks[1].size() << " " << blocks[1][0].size() << " " << blocks[1][0][0].size() << endl;
    cout << blocks[2].size() << " " << blocks[2][0].size() << " " << blocks[2][0][0].size() << endl;
    vector<vector<vector<vector<float>>>> after_DCT = image.performDCT(blocks);
    cout << "After DCT: " << endl;
    cout << after_DCT[0].size() << " " << after_DCT[0][0].size() << " " << after_DCT[0][0][0].size() << endl;
    cout << after_DCT[1].size() << " " << after_DCT[1][0].size() << " " << after_DCT[1][0][0].size() << endl;
    cout << after_DCT[2].size() << " " << after_DCT[2][0].size() << " " << after_DCT[2][0][0].size() << endl;
    vector<vector<int>> zigzaged = image.zigzagScan(after_DCT);
    cout << "Zigzaged: " << endl;
    cout << zigzaged[0].size() << endl;
    cout << zigzaged[1].size() << endl;
    cout << zigzaged[2].size() << endl;
    vector<vector<int>> rled = image.RLE(zigzaged);
    cout << "After RLE: " << endl;
    cout << rled[0].size() << endl;
    cout << rled[1].size() << endl;
    cout << rled[2].size() << endl;
    vector<vector<string>> huffmaned = image.HuffmanEncoding(rled);
    cout << "After Huffman encoding: " << endl;
    cout << huffmaned.size() << endl;
    cout << huffmaned[0].size() << endl;
    cout << huffmaned[1].size() << endl;
    cout << huffmaned[2].size() << endl;
    vector<vector<string>> encoded = image.encode();
    cout << "Finished encoding: " << endl;
    cout << encoded.size() << endl;
    cout << encoded[0].size() << endl;
    cout << encoded[1].size() << endl;
    cout << encoded[2].size() << endl;
}

void conversionsTesting(ProcessedImage& image){
    cout << "Huffman testing\n";
    vector<vector<int>> exampleData = {{1, 1, 1, 2, 2, 3, 3, 3},
                                       {4, 4, 5, 5, 5, 5, 6, 6, 6, 6},
                                       {3, 3, 3, 3, 1, 1},
                                       {2, 4, 4, 4}};
    cout << "rle data\n";
    vector<vector<int>> after_RLE = image.RLE(exampleData);

    for(const auto& channel : after_RLE){
        for(const auto& i : channel){
            cout << i << " ";
        }
        cout << endl;
    }
    cout << "h data\n";
    vector<vector<string>> after_h = image.HuffmanEncoding(after_RLE);

    for(const auto& channel : after_h){
        for(const auto& i : channel){
            cout << i << " ";
        }
        cout << endl;
    }
    cout << "back to rle \n";
    vector<vector<int>> back_to_rle = image.HuffmanDecoding((after_h));

    for(const auto& channel : back_to_rle){
        for(const auto& i : channel){
            cout << i << " ";
        }
        cout << endl;
    }
}


void scaling(ProcessedImage& image){
    image.displayImage();
    QImage converted = image.RGBToYCbCr();
    image.displayOther(&converted);
    vector<vector<vector<int>>> downsampled_data = image.downsampling(converted);
    QImage back = image.upscaling(downsampled_data);
    image.displayOther(&back);
}

void zigzagTest(ProcessedImage& image){
    QImage ycbcr_img = image.RGBToYCbCr();
    vector<vector<vector<int>>> downsampled_data = image.downsampling(ycbcr_img);
    vector<vector<vector<vector<int>>>> blocks2 = image.divideInto8x8(downsampled_data);
    vector<vector<vector<vector<float>>>> after_DCT = image.performDCT(blocks2);
    vector<vector<int>> zigzaged = image.zigzagScan(after_DCT);
    vector<vector<vector<vector<int>>>> back = image.backToBlocksFromZigzag(zigzaged);
    cout << after_DCT.size() << " " << back.size() << endl;
    cout << after_DCT[0].size() << " " << back[0].size() << endl;
    cout << after_DCT[0][0].size() << " " << back[0][0].size() << endl;
    cout << after_DCT[0][0][0].size() << " " << back[0][0][0].size() << endl;
    cout << after_DCT.size() << " " << back.size() << endl;
    cout << after_DCT[1].size() << " " << back[1].size() << endl;
    cout << after_DCT[1][0].size() << " " << back[1][0].size() << endl;
    cout << after_DCT[1][0][0].size() << " " << back[1][0][0].size() << endl;
}

void HuffmanTesting(ProcessedImage& image){
    vector<vector<int>> rle_data = {{10, 12, 10, 10, 15, 20, 10, 12},
                                    {30, 35, 30, 30, 32, 30, 28, 29},
                                    {20, 22, 20, 25, 27, 22, 20, 21}};
    vector<vector<string>> encoded_data = image.HuffmanEncoding(rle_data);
    image.callPrintHuffmanTree(rle_data);
    vector<vector<int>> decoded_data = image.HuffmanDecoding(encoded_data);

    for(int ch = 0; ch < decoded_data.size(); ch++){
        cout << "Channel " << ch << " decoded data:" << endl;
        for(int val : decoded_data[ch]){
            cout << val << " ";
        }
        cout << endl;
    }
}

void blocksTesting(ProcessedImage& image){
    QImage ycbcr_img = image.RGBToYCbCr();
    vector<vector<vector<int>>> downsampled_data = image.downsampling(ycbcr_img);
    vector<vector<vector<vector<int>>>> blocks3 = image.divideInto8x8(downsampled_data);
    vector<vector<vector<int>>> reversed_blocks = image.reverseBlocks(blocks3);
    bool truth = downsampled_data == reversed_blocks;
    cout << truth << endl;
}

void DCTTesting(ProcessedImage& image){
    QImage ycbcr_img = image.RGBToYCbCr();
    vector<vector<vector<int>>> downsampled_data = image.downsampling(ycbcr_img);
    vector<vector<vector<vector<int>>>> blocks = image.divideInto8x8(downsampled_data);
    vector<vector<vector<vector<float>>>> after_DCT = image.performDCT(blocks);
    vector<vector<vector<vector<int>>>> reversed_dct = image.reverseDCT(castToInteger(after_DCT));
    cout << "blocks4 " << blocks.size() << " " << reversed_dct.size() << endl;
    cout << "blocks4 " << blocks[0].size() << " " << reversed_dct[0].size() << endl;
    cout << "blocks4 " << blocks[0][0].size() << " " << reversed_dct[0][0].size() << endl;
    cout << "blocks4 " << blocks[0][0][0].size() << " " << reversed_dct[0][0][0].size() << endl;
    vector<int>& block = blocks[0][0][0];

    for(int i = 0; i < block.size(); i++){
        cout << block[i] << " ";
        if((i + 1) % 8 == 0){
            cout << endl;
        }
    }
    cout << endl;
    vector<int>& block2 = reversed_dct[0][0][0];

    for(int i = 0; i < block2.size(); i++){
        cout << block2[i] << " ";
        if((i + 1) % 8 == 0){
            cout << endl;
        }
    }
}

void performConversion(ProcessedImage& image){
    image.displayImage();
    vector<vector<string>> encoded = image.encode();
    QImage* decoded = image.decode(encoded);
    image.displayOther(decoded);
    image.saveConverted(decoded);
    delete decoded;
}

void performConversionWithFile(ProcessedImage &image){
    image.displayImage();
    vector<vector<string>> encoded = image.encode();
    image.writeToFileEncoded(encoded);
    QImage* decoded = image.decodeFromFile();
    image.displayOther(decoded);
    delete decoded;
}

void performConversionWithFiles(ProcessedImage &image){
    image.displayImage();
    vector<vector<string>> encoded = image.encode();
    image.writeToFileEncoded(encoded);
    image.writeToFileMap();
    QImage* decoded = image.decodeFromFiles();
    image.displayOther(decoded);
    delete decoded;
}
