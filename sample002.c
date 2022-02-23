// Program 1
#include <stdio.h>
#include <omp.h>

#define N 1000 

int main(){

int i, a[N], b[N];

for (i=0; i<N; i++) b[i] = i;

    int threadID, numThreads = 10;
    int ms = N/numThreads;
    omp_set_num_threads(numThreads);  
    #pragma omp parallel private(threadID,i)// Biến threadID, i được sử dụng chung => Cần khai báo thành private.
    { 
    threadID = omp_get_thread_num();

for (i=threadID*ms; i<(threadID + 1)*ms; i++) 
    a[i] = b[i] * b[i];

}



for (i=0; i<20; i++) printf("%4d", a[i]);
printf("\n");

return 0;

}