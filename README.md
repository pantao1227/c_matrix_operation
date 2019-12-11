# C语言实现矩阵相关运算

## 矩阵的存储

矩阵是二维数组，但是内存是一维的，所以不妨用一维数组存储矩阵，同时需要两个整型变量存储矩阵的尺寸。矩阵初始化后，不可更改尺寸。因此使用结构体：

``` C
typedef struct matrix{
  const unsigned int nRows;
  const unsigned int nCols;
  double *DATA;
}matrix;
```

一维数组虽不如二维数组那样直接与实际矩阵对应，但是其结构简单，只需要一级指针就可以对其进行相关操作，并且，使用如下宏定义访问矩阵元素：
``` C
#define ELEMENT( MATRIX, COL, ROW ) ( MATRIX.DATA[MATRIX.nCols*(ROW-1)+(COL-1)] )
```
可以很简单的访问矩阵的元素。

## 函数说明
| 函数名 | 用途 |
|---|---|
| `matrix matrix_create(int rows, int cols)` | 创建一个`rows * cols`的矩阵 |
| `void matrix_close(matrix *m)` | 释放malloc函数申请的内存 |
| `void matrix_assign_all(matrix *m, ...)` | 给已知矩阵整体赋值 |
| `void matrix_assign(matrix *m, int row, int col, double val)` | 给已知矩阵指定元素赋值 |
| `matrix mat_add(matrix *m1, matrix *m2)` | 矩阵加法 |
| `matrix mat_minus(matrix *m1, matrix *m2)` | 矩阵减法 |
| `matrix mat_mul(matrix *m1, matrix *m2)` | 矩阵乘法 |
| `double vec_dot(matrix *m1, matrix *m2)` | 内积 |

## 待完成

`matrix_create` 函数返回的是一个结构体，包含两个整型变量以及一个浮点型指针`*DATA`。这个指针指向的是malloc申请的一片内存，在某些情况下，需要考虑使用`matrix_close`函数释放这片内存避免内存泄漏。需要进一步完成的是考虑有无更加方便的内存管理方式。
 

