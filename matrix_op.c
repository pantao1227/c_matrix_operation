#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>

typedef struct matrix{
  int rows;
  int cols;
  double *DATA;
}matrix;

void mat_print(matrix *m){
  for(int i=0;i<m->rows*m->cols;i++){
    printf("%lf%s",*(m->DATA+i),(i+1) % m->cols == 0 ? "\n":"\t");
  }
}

matrix mat_trans(matrix *m){
  double *pA = (double *)malloc(sizeof(double)*m->rows*m->cols);
  matrix mat = {m->cols,m->rows,pA};
  for(int i=0; i < mat.rows; i++){
    for(int j=0; j < mat.cols; j++){
      pA[mat.cols * i + j] = m->DATA[m->cols * j + i];
    }
  }

  return mat;
}

matrix matrix_create(int rows, int cols){
  double *pA = (double *)malloc(sizeof(double)*rows*cols);
  memset(pA, 0, sizeof(double)*rows*cols);
  matrix mat = {rows,cols,pA};

  return mat;
}

void matrix_assign_all(matrix *mat, ...){
  int cnt = mat->rows * mat->cols;
  va_list ap;
  va_start(ap,mat);
  for(int i=0;i<cnt;i++){
        mat->DATA[i] = va_arg(ap,double);
  }
  va_end(ap);
}

void matrix_assign(matrix *m, int row, int col, double val){
  if((row < 1)||(row > m->rows)||(col < 1)||(col > m->cols)){
    printf("Index out of bounds!\n");
  }else{
    m->DATA[m->cols * (row-1) + (col-1)] = val;
  }
}

matrix mat_add(matrix *m1, matrix *m2){
  if((m1->rows == m2->rows)&&(m1->cols == m2->cols)){
    double *pA = (double *)malloc(sizeof(double)*m1->rows*m1->cols);
    memset(pA,0,sizeof(double)*m1->rows*m2->cols);
    matrix mat = {m1->rows, m2->cols, pA};
    for(int i=0; i < m1->rows * m1->cols; i++){
      pA[i] = m1->DATA[i] + m2->DATA[i];
    }

    return mat;
  }else{
    matrix mat = {m1->rows, m2->cols, 0};
    printf("ERROR! Matrix dimensions must agree!\n");
    
    return mat;
  }
}

matrix mat_minus(matrix *m1, matrix *m2){
  if((m1->rows == m2->rows)&&(m1->cols == m2->cols)){
    double *pA = (double *)malloc(sizeof(double)*m1->rows*m1->cols);
    memset(pA,0,sizeof(double)*m1->rows*m2->cols);
    matrix mat = {m1->rows, m2->cols, pA};
    for(int i=0; i < m1->rows * m1->cols; i++){
      pA[i] = m1->DATA[i] - m2->DATA[i];
    }

    return mat;
  }else{
    matrix mat = {m1->rows, m2->cols, 0};
    printf("ERROR! Matrix dimensions must agree!\n");
    
    return mat;
  }
}

matrix mat_mul(matrix *m1, matrix *m2){
  if(m1->cols != m2->rows){
    matrix mat = {m1->rows, m2->cols, 0};
    printf("ERROR! Matrix dimensions must agree!\n");
    
    return mat;
  }else{
    double *pA = (double *)malloc(sizeof(double)*m1->rows*m2->cols);
    memset(pA,0,sizeof(double)*m1->rows*m2->cols);
    matrix mat = {m1->rows, m2->cols, pA};
    for(int i=0; i < m1->rows; i++){
      for(int j=0; j < m2->cols; j++){
        double sum = 0;
        for(int ii=0; ii < m1->cols; ii++){
          sum += m1->DATA[m1->cols * i + ii] * m2->DATA[m2->cols * ii + j];
        }
        pA[m2->cols * i + j] = sum;
      }
    }

    return mat;
  }
}

double vec_dot(matrix *m1, matrix *m2){
  double result=0;
  if((m1->rows != 1)&&(m1->cols != 1)){
    printf("m1 is not a vector!\n");
  }else if((m2->rows != 1)&&(m2->cols != 1)){
    printf("m2 is not a vector!\n");
  }else if((m1->rows + m1->cols != m2->rows + m2->cols)){
    printf("Vector dimensions must agree!\n");
  }else{
    for(int i=0; i < m1->rows + m1->cols; i++){
      result += m1->DATA[i] * m2->DATA[i];
    }
  }

  return result;
}
