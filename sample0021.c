#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 1000
int main()
{
    int i, a[N], b[N];
    #pragma omp parallel for // Tự động chia miền tính toán.
        for (i = 0; i < N; ++i){
            b[i] = i;
            a[i] = b[i] * b[i];
        }
    
    for (i = 0; i < 20; i++) printf("%4d", a[i]);
        
    return 0;
}