#include<stdio.h>
#include "matrix_op.h"

typedef matrix* mat_p;

mat_p createMat(int nRows, int nCols){
    mat_p mat = (matrix *)malloc(sizeof(int)*2+sizeof(double)*nRows*nCols);

    return mat;
}

int main(){

    return 0;
}
