//WAP in C language to perform addition of elements of 2 arrays in a 3rd array

#include <stdio.h>
#include <stdlib.h>
void main()
{
     int i, n;
     int *a, *b, *c;
     printf("How many Elements in each array...\n");
     scanf("%d", &n);
     a = (int *)malloc(n * sizeof(int));
     b = (int *)malloc(n * sizeof(int));
     c = (int *)malloc(n * sizeof(int));
     printf("Enter Elements of First List\n");
     for (i = 0; i < n; i++)
     {
          scanf("%d", a + i);
     }
     printf("Enter Elements of Second List\n");
     for (i = 0; i < n; i++)
     {
          scanf("%d", b + i);
     }
     for (i = 0; i < n; i++)
     {
          *(c + i) = *(a + i) + *(b + i);
     }
     printf("Resultant List is\n");
     for (i = 0; i < n; i++)
     {
          printf("%d\n", *(c + i));
     }
}