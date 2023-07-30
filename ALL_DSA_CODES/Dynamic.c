// WAP in C language to allocate memory for an integer data and access it.

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *var;         /* pointer variable for malloc below */

    var = (int*) malloc(sizeof(int));
    printf("The number is :");
    scanf("%d",&var);

    printf("var    = %p\n",var);
    
}
