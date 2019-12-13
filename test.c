#include<stdio.h>
#include "matrix_op.h"

// This segment of program demonstrates the use of "matrix_op.h".

int main(){
  matrix A = matrix_create(3,2);matrix_assign_all(&A, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0);
  matrix B = matrix_create(2,4);matrix_assign_all(&B, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);
  matrix C = mat_mul(&A, &B);
  matrix D = mat_trans(&A);
  matrix E = mat_add(&A, &A);
  matrix F = mat_minus(&A, &A);

  double x = ELEMENT(A, 3, 1);  // Use ELEMENT to get value.
  ELEMENT(A, 3, 1) = 456.654; // Use ELEMENT to assign value.
  double y = ELEMENT(A, 3, 1);
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
  printf("\nVec1 = \n");mat_print(&vec1);
  printf("\nVec2 = \n");mat_print(&vec2);
  printf("\nVec1 dot Vec2 = %lf\n",vec_dot(&vec1,&vec2));
  printf("\nVec1 dot Vec1 = %lf \n",vec_dot(&vec1,&vec1));
  printf("\nVec2 dot Vec2 = %lf \n",vec_dot(&vec2,&vec2));

  //copy matrix
  matrix A_copy = matrix_copy(&A);
  mat_print(&A_copy);

  matrix_close(&A);
  matrix_close(&A_copy);

  matrix_close(&A);matrix_close(&B);matrix_close(&C);matrix_close(&D);matrix_close(&E);matrix_close(&F);
  matrix_close(&A);matrix_close(&B);matrix_close(&C);matrix_close(&D);matrix_close(&E);matrix_close(&F);

  return 0;
}