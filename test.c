#include<stdio.h>
#include "matrix_op.h"

int main(){
  matrix A = matrix_create(3,2);matrix_assign_all(&A, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0);
  matrix B = matrix_create(2,4);matrix_assign_all(&B, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);
  matrix C = mat_mul(&A, &B);
  matrix D = mat_trans(&A);
  matrix E = mat_add(&A, &A);
  matrix F = mat_minus(&A, &A);

  double x = ELEMENT(A,1,1);
  A.DATA[0] = 456.654;
  double y = ELEMENT(A,1,1);
  printf("\n\n%lf-----%lf\n\n",x,y);

  printf("\nA = \n");mat_print(&A);
  printf("\nB = \n");mat_print(&B);
  printf("\nC = A * B = \n");mat_print(&C);
  printf("\nD = A^T = \n");mat_print(&D);
  printf("\nE = A + A = \n");mat_print(&E);
  printf("\nF = A - A  \n");mat_print(&F);

  matrix_assign(&A, 1, 1, 123.321);
  printf("\nA = \n");mat_print(&A);
  
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