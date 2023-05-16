#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
void func(int arr[], int n)
{
    int i;
    int max = arr[0];
    int min = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("MAXIMUM IN ARRAY : %d\n", max);
    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("MINIMUM IN ARRAY : %d\n", min);
    return;
}
int main()
{
    int *arr, n, i;
    printf("Enter the elemnts of the array:");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    arr = malloc(sizeof(int *));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The array is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    func(arr, n);
    return 0;
}