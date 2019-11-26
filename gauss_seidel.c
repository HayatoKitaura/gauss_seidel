#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gauss_seidel.h"

void init_gui(void){
  printf("\033[2;1H");
  printf("\033[2J");
  printf("<<<ガウスザイデル法による連立一次方程式の反復解法>>>\n");
  printf("元数を入力してください：");
}

double *init_x(int dim){
  double *output;
  output = malloc(sizeof(int *) * dim);
  for(int i=0; i < dim; i++){
    output[i] = 0;
  }
  return(output);
}

double *input_x(double *vector, int dim){
  for(int i=0; i < dim; i++){
    printf("x[%d] = ", i+1);
    scanf("%lf", &vector[i]);
  }
  printf("--------------------------------------\n");
  return(vector);
}

double *init_vector(int dim){
  double *output;
  output = malloc(sizeof(int *) * dim);
  for(int i=0; i < dim; i++){
    output[i] = i + 1;
  }
  return(output);
}

double *input_vector(double *vector, int dim){
  for(int i=0; i < dim; i++){
    printf("b[%d] = ", i+1);
    scanf("%lf", &vector[i]);
  }
  printf("--------------------------------------\n");
  return(vector);
}

double **init_matrix(int dim){
  double **output;
  output = malloc(sizeof(int *) * dim);
  for(int i=0; i < dim; i++){
    output[i] = malloc(sizeof(int) * dim);
  }
  for(int i=0; i < dim; i++){
    for(int j = 0; j < dim; j++){
      output[i][j] = 0;
    }
  }
  return(output);
}


double **input_matrix(double **matrix, int dim){
  for(int rows=0; rows < dim; rows++){
    for(int cols=0; cols < dim; cols++){
      if(cols == 0){
        if(rows == 0) printf("/   a[%d][%d]     ", rows+1, cols+1);
        if(0 < rows && rows < dim-1){
          if(rows >= 9){
            printf("|   a[%d][%d]    ", rows+1, cols+1);
          }
          else printf("|   a[%d][%d]     ", rows+1, cols+1);
        }
        if(rows == dim-1){
          if(rows >= 9){
            printf("\\   a[%d][%d]    ", rows+1, cols+1);
          }
          else printf("\\   a[%d][%d]     ", rows+1, cols+1);
        }
      }else if(cols == dim-1){
        if(rows == 0) printf("a[%d][%d]   \\", rows+1, cols+1);
        if(0 < rows && rows < dim-1){
          if(rows >= 9){
            printf("a[%d][%d]  |", rows+1, cols+1);
          }
          else printf("a[%d][%d]   |", rows+1, cols+1);
        }
        if(rows == dim-1){
          if(rows >= 9){
            printf("a[%d][%d]  /", rows+1, cols+1);
          }
          else printf("a[%d][%d]   /", rows+1, cols+1);
        }
      }else{
        if(rows >= 9){
          printf("a[%d][%d]    ", rows+1, cols+1);
        }
        else printf("a[%d][%d]     ", rows+1, cols+1);
      }
    }
    printf("\033[B");
    printf("\033[G");
  }
  for(int rows=0; rows < dim; rows++){
    for(int cols=0; cols < dim; cols++){
      printf("a[%d][%d] =", rows+1, cols+1);
      scanf("%lf", &matrix[rows][cols]);
    }
  }
  printf("--------------------------------------\n");
  return(matrix);
}


double *gauss_seidel(double **a, double *b, double *x, int dim)
{
  int num = 1, count = 0, count_max = 100;
  double EPS = (1e-15);
  double dx, absx, sum, new;
  do{
    dx = 0.0;
    absx = 0.0;
    for(int i=0; i < dim; i++){
      sum = 0;
      for(int j=0; j < dim; j++){
        if(i != j){
          sum += a[i][j] * x[j];
        }
      }
      new = 1.0/a[i][i] * (b[i] - sum);
      dx += fabs(new - x[i]);
      absx += fabs(new);
      x[i] = new;
    }
    printf("<round %d> ", num);
    num++;
    for(int k = 0; k < dim; k++){
      printf("x[%d]:%lf", k, x[k]);
    }
    printf("\n");
    count++;
  }
  while(dx/absx > EPS && count < count_max);
  if(count == count_max) printf("発散しています。\n");
}
