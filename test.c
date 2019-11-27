#include<stdio.h>
#include "matrix_op.c"

int main(){
  matrix A = matrix_create(3,2);matrix_assign_all(&A, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0);
  matrix B = matrix_create(2,4);matrix_assign_all(&B, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);
  matrix C = mat_mul(&A, &B);
  matrix D = mat_trans(&A);
  matrix E = mat_add(&A, &A);
  matrix F = mat_minus(&A, &A);

  mat_print(&A);
  mat_print(&B);
  mat_print(&C);
  mat_print(&D);
  mat_print(&E);
  mat_print(&F);

  matrix_assign(&A, 1, 1, 123.321);
  mat_print(&A);
  
  matrix vec1 = matrix_create(1,5);
  matrix vec2 = matrix_create(5,1);
  matrix_assign_all(&vec1, 1.0, 2.0, 3.0, 4.0, 5.0);
  matrix_assign_all(&vec2, 5.0, 4.0, 3.0, 2.0, 1.0);
  printf("\n");
  mat_print(&vec1);
  mat_print(&vec2);
  printf("%lf\n",vec_dot(&vec1,&vec2));

  return 0;
}