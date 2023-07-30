//WAP in C language to take input for a dynamic array from user and print as output

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    int *arr;
    printf("Enter the size of the array :");
    scanf("%d",&n);
    // Allocate memory for 2D array
    arr = (int*)malloc(n * sizeof(int));

    if(arr == NULL)
          printf("Memory not allocated");
    else
    {
          // Populate the array with user input
          printf("Enter the elements in the array:\n");
          for(i=0;i<n;i++)
               scanf("%d",&arr[i]);
          // Print the array
          printf("The elements of the array are : \n");
          for(i=0;i<n;i++)
          {
               printf("%d ",arr[i]);
          }
               
    }
}