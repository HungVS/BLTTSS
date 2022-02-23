
// Program 4
#include <stdio.h>
#define N 20
float fx(float x){
  return x*x*x*x+2*x*x*x+2;  
}
int main(){
  int i;
  float h = 0.01, a = 2.0;
  float daoham[N];
  for (i=0; i<N; i++)
      daoham[i] = (fx(a+i*h)- fx(a+i*h-h))/h;
  printf("Ket qua dao ham:\n");
  for (i=0; i<N; i++)
      printf("%f ",daoham[i]);
  printf("\n");    
  return 0;
}



/*
// Program 4
#include <stdio.h>
#include <mpi.h>

//#include <conio.h>
#define N 20
float fx(float x){
  return x*x*x*x+2*x*x*x+1;  

  }

int main(int argc, char*argv[]) {



    MPI_Init(&argc,&argv); // Khởi tạo môi trường MPI.
  int i;
  float h = 0.01, a = 1.0;
  float daoham[N];


  	int Ncpu, IDcpu;
	MPI_Comm_size(MPI_COMM_WORLD,&Ncpu);
	MPI_Comm_rank(MPI_COMM_WORLD,&IDcpu);
    int ms = N/Ncpu; // Xác định kích thước miền tính toán (domain).
    float daohams[ms];
    int is;


  for (i=0; i<ms; i++) {
      is=i+ms*IDcpu;
      daohams[i] = (fx(a+is*h+h)- fx(a+is*h))/h;
}


MPI_Gather(daohams, ms,MPI_FLOAT,daoham,ms,MPI_FLOAT,0,MPI_COMM_WORLD);


if(!IDcpu) {
  printf("Ket qua dao ham:\n");
  for (i=0; i<N; i++)
      printf("%f \t",daoham[i]);
  printf("\n");
 // getch();  
}


    MPI_Finalize(); // Đóng môi trường MPI.
  return 0;
}
*/

