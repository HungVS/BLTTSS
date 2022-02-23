// Program 1
#include <stdio.h>
#define M 20
int main(){
    int i, X[M], Y[M], Z[M];

 #pragma omp parallel for
    for (i=0; i<M; i++)  { 
        X[i] = i; Y[i] = 2*i;
        Z[i] = 2 * X[i] * Y[i];

    }
    for (i=0; i<M; i++)  printf("%4d ", Z[i]);
    return 0;
}
// 0    4   16   36   64  100  144  196  256  324  400  484  576  676  784  900 1024 1156 1296 1444

/* OUTPUT của SINH VIÊN: 
0    4   16   36   64  100  144  196  256  324  400  484  576  676  784  900 1024 1156 1296 1444
*/