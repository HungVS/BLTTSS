// Program 2
#include <stdio.h>
float fx(float x){
  return x*x*x*x+2*x*x*x+2;  
}
int main(){
  int N = 22, i;  
  float a = 0.0, b = 2.0, h, fa, fb, tong = 0, tichphan;
  h = (b-a)/N;
  fa = fx(a);
  fb = fx(b);

#pragma omp parallel for reduction (+:tong)
  for (i=1;i<=N-1;i++)
      tong = tong + fx(a+i*h);

      
  tichphan = (fa + fb + 2*tong)*h/2;
  printf("Tich phan: %f\n",tichphan);     
  return 0;
  }
// Tich phan: 18.438564

/* OUTPUT: 
Tich phan: 18.438566
*/

