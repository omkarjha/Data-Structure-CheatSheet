// WAP in C language to allocate memory for a 2d Array such that number of columns in each row is equal to the number of rows and access it's elements.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    int **arr;
    printf("Enter the number of rows and columns in the array :");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        arr[i] = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
        printf("Memory not allocated");
    else
    {
        // Taking input for the array
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("Enter the elements in the array [%d][%d]:", i, j);
                scanf("%d", &arr[i][j]);
            }
        }
    }

    // Print the array
    printf("The elements of the array are : \n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%d\t ", arr[i][j]);
    }printf("\n");

    // The address of the 2d array is
    printf("The addresses of the following 2d Array is :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            /* code */
            printf("%d \t", &arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
