// Program 2

#include <stdio.h>
#include <omp.h>

float fx(float x){

return 2*x*x*x*x+x*x*x+1;

}

int main(){

int N = 20, i;

float a = 1.0, b = 2.0, h, fa, fb, tong = 0, tichphan;

h = (b-a)/N;

fa = fx(a);

fb = fx(b);

float tongs=0.0;
int threadID;
int numThreads = 5; // 5 luồng.
int ms = N/numThreads;
float tmp[numThreads]; // Mảng trung gian để lưu trữ TỔNG tính được của mỗi luồng.

   omp_set_num_threads(numThreads); 

#pragma omp parallel private(tongs,threadID,i) 
{
tongs=0;// BẮT BUỘC khởi tạo lại với biến "private" nếu không sẽ thu được các giá trị bất định.
threadID = omp_get_thread_num();



if(threadID==0) {
for (i=1;i<ms;i++) {

tongs=tongs+fx(a+i*h);
}
} else {
for (i=threadID*ms;i<(threadID+1)*ms;i++) {
    
tongs=tongs+ fx(a+i*h);
}
}


tmp[threadID]=tongs;
}


for(i=0;i<numThreads;i++) {
    tong+=tmp[i];
}

tichphan = (fa + fb + 2*tong)*h/2;

printf("Tich phan: %f\n",tichphan);

return 0;

}    