// WAP in C language to form a matrix from user input and find it's spiral form

#include <stdio.h>
#include <stdlib.h>
int main()
{
     int n, i, j;
     printf("Enter the number of rows and columns in the matrix:");
     scanf("%d", &n);
     int **matrix = (int **)malloc(n * sizeof(int *));
     for (i = 0; i < n; i++)
     {
          matrix[i] = (int *)malloc(n * sizeof(int));
     }
     int count = 1;
     int startR = 0, endR = n - 1;
     int startC = 0, endC = n - 1;

     while (startR <= endR && startC <= endC)
     {
          for (i = startC; i <= endC; i++)
          {
               matrix[startR][i] = count;
               count++;
          }
          startR++;
          for (i = startR; i <= endR; i++)
          {
               matrix[i][endC] = count;
               count++;
          }
          endC--;
          if (startR <= endR)
          {
               for (i = endC; i >= startC; i--)
               {
                    matrix[endR][i] = count;
                    count++;
               }
               endR--;
          }
          if (startC <= endC)
          {
               for (i = endR; i >= startR; i--)
               {
                    matrix[i][startC] = count;
                    count++;
               }
               startC++;
          }
     }
     printf("The spiral matrix is : \n");
     printf("\n");
     for (i = 0; i < n; i++)
     {

          for (j = 0; j < n; j++)
          {
               printf("%d     ", matrix[i][j]);
          }
          printf("\n");
     }
     printf("\n");
}