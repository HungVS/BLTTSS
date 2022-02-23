// Program 2

#include <stdio.h>
#include <omp.h>

//#include <conio.h>

float fx(float x){

return 2*x*x*x*x+x*x*x+1;

}

int main(){

int N = 20, i;

float a = 1.0, b = 2.0, h, fa, fb, tong = 0, tichphan;

h = (b-a)/N;

fa = fx(a);

fb = fx(b);

//======
/*
for (i=1;i<=N-1;i++)
tong = tong + fx(a+i*h);
*/
#pragma omp parallel for reduction (+:tong)
for (i=1;i<=N-1;i++) {

tong = tong + fx(a+i*h);
}
//======



tichphan = (fa + fb + 2*tong)*h/2;

printf("Tich phan: %f\n",tichphan);

//getch();

return 0;

}