//#include <iostream>
#include <fstream>
#include "Board.h"

using namespace std;


struct RGB {
    uint8_t red, green, blue;
public:
    RGB() : red(255) , green(255) , blue(255) {}
    RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};


class Image{

private:
    RGB* image;
    int dim;
    void drawTable(int cell);
    void drawX(int row , int col , int cell);
    void drawO(int row , int col , int cell);




public:
    Image(int dim);
    ~Image();
    string createPPM(Pair** pr , uint size);

};