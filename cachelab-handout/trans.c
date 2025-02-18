/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N]){
    if (M == 32)
    	for (int j = 0; j < M; j += 8)
            for (int i = 0; i < N; i++) {
            	int n1 = A[i][j];
            	int n2 = A[i][j+1];
            	int n3 = A[i][j+2];
            	int n4 = A[i][j+3];
            	int n5 = A[i][j+4];
            	int n6 = A[i][j+5];
            	int n7 = A[i][j+6];
            	int n8 = A[i][j+7];
            	B[j][i] = n1;
            	B[j+1][i] = n2;
            	B[j+2][i] = n3;
            	B[j+3][i] = n4;
            	B[j+4][i] = n5;
            	B[j+5][i] = n6;
            	B[j+6][i] = n7;
            	B[j+7][i] = n8;
            }
      else if (M == 64) {
      	  for (int j = 0; j < M; j += 8)
              for (int i = 0; i < N; i += 8) {
            	  for (int x = i; x < i + 4; x++) {
      	  	      int n1 = A[x][j];
            	      int n2 = A[x][j+1];
            	      int n3 = A[x][j+2];
            	      int n4 = A[x][j+3];
            	      int n5 = A[x][j+4];
            	      int n6 = A[x][j+5];
            	      int n7 = A[x][j+6];
            	      int n8 = A[x][j+7];
            	      B[j][x] = n1;
            	      B[j+1][x] = n2;
            	      B[j+2][x] = n3;
            	      B[j+3][x] = n4;
            	      B[j][x+4] = n5;
            	      B[j+1][x+4] = n6;
            	      B[j+2][x+4] = n7;
            	      B[j+3][x+4] = n8;
      		  }
      		  for (int y = j; y < j + 4; y++) {
      	  	      int n1 = A[i+4][y];
            	      int n2 = A[i+5][y];
            	      int n3 = A[i+6][y];
            	      int n4 = A[i+7][y];
            	      int n5 = B[y][i+4];
            	      int n6 = B[y][i+5];
            	      int n7 = B[y][i+6];
            	      int n8 = B[y][i+7];
            	      B[y][i+4] = n1;
            	      B[y][i+5] = n2;
            	      B[y][i+6] = n3;
            	      B[y][i+7] = n4;
            	      B[y+4][i] = n5;
            	      B[y+4][i+1] = n6;
            	      B[y+4][i+2] = n7;
            	      B[y+4][i+3] = n8;
      		  }
      		  for (int y = j + 4; y < j + 8; y++) {
      	  	      int n1 = A[i+4][y];
            	      int n2 = A[i+5][y];
            	      int n3 = A[i+6][y];
            	      int n4 = A[i+7][y];
            	      B[y][i+4] = n1;
            	      B[y][i+5] = n2;
            	      B[y][i+6] = n3;
            	      B[y][i+7] = n4;
      		  }
      	  }
      }
      else {
      	  for (int m = 0; m < M; m += 16)
              for (int n = 0; n < N; n += 16) {
          	  for (int j = m; j < m + 16 && j < M; j++)
            	      for (int i = n; i < n + 16 && i < N; i++) 
            		  B[j][i] = A[i][j];
      }}
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

