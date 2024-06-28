#include <QApplication>
#include "processed_image.h"
#include "tests.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    ProcessedImage image("sunset.png");
    performConversion(image);
    // performConversionWithFile(image);
    // performConversionWithFiles(image);

    return a.exec();
}
