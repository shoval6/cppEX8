#include <cmath>
#include "Image.h"



Image::Image(int dim) : dim(dim) {
    image = new RGB[dim*dim];

}


Image::~Image() {

    delete[] image;
}


string Image::createPPM(Pair** pr ,uint size) {

    int cell = dim/size;
    drawTable(cell);

    for(int i=0; i<size; i++){
        for(int j=0; j<size;j++){
            if(pr[i][j]=='X')
                drawX(i,j,cell);
            if(pr[i][j]=='O')
                drawO(i,j,cell);

        }
    }

    srand(time(0));
    string filename = "image_" + to_string(rand()) + ".ppm";
    ofstream imageFile(filename, ios::out | ios::binary);
    imageFile << "P6" << endl << dim <<" " << dim << endl << 255 << endl;
    imageFile.write(reinterpret_cast<char*>(image), 3*dim*dim);
    imageFile.close();

    return filename;


}


void Image::drawTable(int cell) {

    int jump = cell;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            if((j%jump==0 && j!=0) || (i%jump==0) && i!=0){
                image[dim*i+j].red = 0;
                image[dim*i+j].green = 0;
                image[dim*i+j].blue = 0;
            }
        }
    }

}

void Image::drawX(int row, int col, int cell) {


    int pixrow = row*cell;
    int pixcol = col*cell;
    for(int i=0; i<cell; i++){
        pixcol = col*cell;
        for(int j=0; j<cell; j++){
            if (((i == j || i + j == cell-1))){
                image[pixrow*dim+pixcol].red = 0;
                image[pixrow*dim+pixcol].green = 0;
                image[pixrow*dim+pixcol].blue = 0;

            }
            pixcol++;
        }
        pixrow++;
    }

}

void  Image::drawO(int row, int col, int cell) {

    int dx, dy;
    int r = cell/2 -10;
    int x2_center = cell/2;
    int y2_center = cell/2;
    int pixrow = row*cell;
    int pixcol = col*cell;

    for (int i = 0; i < dim; i++) {
        pixrow = row * cell;
        for (int j = 0; j < dim; j++) {
            dx = x2_center - i;
            dy = y2_center - j;
            double distance = sqrt((dx * dx) + (dy * dy));
            if ((distance >= (r) - 1) && (distance <= (r) + 1)) {
                image[pixrow * dim + pixcol].red = 0;
                image[pixrow * dim + pixcol].green = 0;
                image[pixrow * dim + pixcol].blue = 0;

            }
            pixcol++;
        }
        pixrow++;

    }





}