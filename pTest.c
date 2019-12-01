#include<stdio.h>
#include "matrix_op.h"

matrix *createMat(int nRows, int nCols){
    matrix *Mat = (matrix *)malloc(sizeof(int)*2+sizeof(double)*nRows*nCols);

    return Mat;
}

int main(){

    return 0;
}