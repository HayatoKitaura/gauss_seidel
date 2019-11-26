#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gauss_seidel.h"

int main (void){
    int dim;
    double *x;
    double *vector;
    double **matrix;
    init_gui();
    scanf("%d", &dim);
    printf("xの初期値を入力してください。\n");
    x = init_x(dim);
    x = input_x(x, dim);
    printf("b行列を入力してください。\n");
    vector = init_vector(dim);
    vector = input_vector(vector, dim);
    printf("係数(a行列)を入力してください。\n");
    matrix = init_matrix(dim);
    matrix = input_matrix(matrix, dim);
    gauss_seidel(matrix, vector, x, dim);
    return 0;
}
