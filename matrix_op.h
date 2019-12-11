#ifndef __MATRIX_OP_H_
#define __MATRIX_OP_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>

// I think the shape of a matrix can not be changed.
typedef struct matrix{
  const unsigned int nRows;
  const unsigned int nCols;
  double *DATA;
}matrix;

// This macro definition is used to access the Matrix element.
#define ELEMENT( MATRIX, COL, ROW ) ( MATRIX.DATA[MATRIX.nCols*(ROW-1)+(COL-1)] )

void mat_print(const matrix *m){
  for(int i=0;i<m->nRows*m->nCols;i++){
    printf("%lf%s",*(m->DATA+i),(i+1) % m->nCols == 0 ? "\n":"\t");
  }
}

matrix mat_trans(const matrix *m){
  double *pA = (double *)malloc(sizeof(double)*m->nRows*m->nCols);
  matrix mat = {m->nCols,m->nRows,pA};
  for(int i=0; i < mat.nRows; i++){
    for(int j=0; j < mat.nCols; j++){
      pA[mat.nCols * i + j] = m->DATA[m->nCols * j + i];
    }
  }

  return mat;
}

matrix matrix_create(int nRows, int nCols){
  double *pA = (double *)malloc(sizeof(double)*nRows*nCols);
  memset(pA, 0, sizeof(double)*nRows*nCols);
  matrix mat = {nRows,nCols,pA};

  return mat;
}

void matrix_close(matrix *m){
  if(m->DATA != NULL){
    free(m->DATA);
    m->DATA = NULL;
  }else{
    printf("Matrix had been close.\n");
  }
}

void matrix_assign_all(const matrix *mat, ...){
  int cnt = mat->nRows * mat->nCols;
  va_list ap;
  va_start(ap,mat);
  for(int i=0;i<cnt;i++){
        mat->DATA[i] = va_arg(ap,double);
  }
  va_end(ap);
}

void matrix_assign(const matrix *m, int row, int col, double val){
  if((row < 1)||(row > m->nRows)||(col < 1)||(col > m->nCols)){
    printf("Index out of bounds!\n");
  }else{
    m->DATA[m->nCols * (row-1) + (col-1)] = val;
  }
}

matrix mat_add(const matrix *m1, const matrix *m2){
  if((m1->nRows == m2->nRows)&&(m1->nCols == m2->nCols)){
    double *pA = (double *)malloc(sizeof(double)*m1->nRows*m1->nCols);
    memset(pA,0,sizeof(double)*m1->nRows*m2->nCols);
    matrix mat = {m1->nRows, m2->nCols, pA};
    for(int i=0; i < m1->nRows * m1->nCols; i++){
      pA[i] = m1->DATA[i] + m2->DATA[i];
    }

    return mat;
  }else{
    matrix mat = {m1->nRows, m2->nCols, 0};
    printf("ERROR! Matrix dimensions must agree!\n");
    
    return mat;
  }
}

matrix mat_minus(const matrix *m1, const matrix *m2){
  if((m1->nRows == m2->nRows)&&(m1->nCols == m2->nCols)){
    double *pA = (double *)malloc(sizeof(double)*m1->nRows*m1->nCols);
    memset(pA,0,sizeof(double)*m1->nRows*m2->nCols);
    matrix mat = {m1->nRows, m2->nCols, pA};
    for(int i=0; i < m1->nRows * m1->nCols; i++){
      pA[i] = m1->DATA[i] - m2->DATA[i];
    }

    return mat;
  }else{
    matrix mat = {m1->nRows, m2->nCols, 0};
    printf("ERROR! Matrix dimensions must agree!\n");
    
    return mat;
  }
}

matrix mat_mul(const matrix *m1, const matrix *m2){
  if(m1->nCols != m2->nRows){
    matrix mat = {m1->nRows, m2->nCols, 0};
    printf("ERROR! Matrix dimensions must agree!\n");
    
    return mat;
  }else{
    double *pA = (double *)malloc(sizeof(double)*m1->nRows*m2->nCols);
    memset(pA,0,sizeof(double)*m1->nRows*m2->nCols);
    matrix mat = {m1->nRows, m2->nCols, pA};
    for(int i=0; i < m1->nRows; i++){
      for(int j=0; j < m2->nCols; j++){
        double sum = 0;
        for(int ii=0; ii < m1->nCols; ii++){
          sum += m1->DATA[m1->nCols * i + ii] * m2->DATA[m2->nCols * ii + j];
        }
        pA[m2->nCols * i + j] = sum;
      }
    }

    return mat;
  }
}

double vec_dot(const matrix *m1, const matrix *m2){
  double result=0;
  if((m1->nRows != 1)&&(m1->nCols != 1)){
    printf("m1 is not a vector!\n");
  }else if((m2->nRows != 1)&&(m2->nCols != 1)){
    printf("m2 is not a vector!\n");
  }else if((m1->nRows + m1->nCols != m2->nRows + m2->nCols)){
    printf("Vector dimensions must agree!\n");
  }else{
    for(int i=0; i < m1->nRows + m1->nCols; i++){
      result += m1->DATA[i] * m2->DATA[i];
    }
  }

  return result;
}

#endif
