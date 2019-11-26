#ifndef GAUSS_SEIDEL_H
#define GAUSS_SEIDEL_H

void init_gui();
double *init_x(int dim);
double *input_x(double *vector, int dim);
double *init_vector(int dim);
double *input_vector(double *vector, int dim);
double **input_matrix(double **matrix, int dim);
double **init_matrix(int dim);
double *gauss_seidel(double **a, double *b, double *x, int dim);

#endif
