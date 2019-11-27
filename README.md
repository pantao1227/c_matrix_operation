# C语言实现矩阵相关运算

## 函数说明
| 函数名 | 用途 |
|---|---|
| `matrix matrix_create(int rows, int cols)` | 创建一个`rows * cols`的矩阵 |
| `void matrix_assign_all(matrix *mat, ...)` | 给已知矩阵整体赋值 |
| `void matrix_assign(matrix *m, int row, int col, double val)` | 给已知矩阵指定元素赋值 |
| `matrix mat_add(matrix *m1, matrix *m2)` | 矩阵加法 |
| `matrix mat_minus(matrix *m1, matrix *m2)` | 矩阵减法 |
| `matrix mat_mul(matrix *m1, matrix *m2)` | 矩阵乘法 |
| `double vec_dot(matrix *m1, matrix *m2)` | 内积 |



