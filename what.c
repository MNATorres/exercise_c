#include <stdio.h>
#define N 6


int main()

{
    int v1[N] = {0, 2, 4, 1, 3, 5};
    int v2[N] = {11, 22, 33, 44, 55, 66};
    int x = 1;
    for (x = 0; x < N; x++)
        printf("%d,", v2[v1[x]]);
    return 0;
}