// WAP in C language to take input for a 2d Array and print it using dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

int main()
{
     int rows, i, j, column;
     int **arr;
     printf("Enter the number of rows in the array :");
     scanf("%d", &rows);
     printf("Enter the number of columms in the array :");
     scanf("%d", &column);

     arr = (int **)malloc(rows * sizeof(int *));
     for (i = 0; i < rows; i++)
          arr[i] = (int *)malloc(column * sizeof(int));

     if (arr == NULL)
          printf("Memory not allocated");
     else
     {
          // Taking input for the array
          for (i = 0; i < rows; i++)
          {
               for (j = 0; j < column; j++)
               {
                    printf("Enter the elements in the array [%d][%d]:", i, j);
                    scanf("%d", &arr[i][j]);
               }
          }
     }

     // Print the array
     printf("The elements of the array are : \n");
     for (i = 0; i < rows; i++)
     {
          printf("\n");
          for (j = 0; j < column; j++)
               printf("%d ", arr[i][j]);
     }

}
