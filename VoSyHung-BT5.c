/*
CHÚ Ý:
- Mã nguồn GỐC khi CHẠY TRÊN MÁY CỦA SINH VIÊN cho kết quả 'GẦN BẰNG' YÊU CẦU ĐỀ RA.
- OUTPUT tại MÁY SINH VIÊN: 55.641174 56.360626 57.087326 57.818985 58.557129 59.301376 60.051346 60.808563 61.569977 62.339783 63.114166 63.895416 64.683533 65.476990 66.276550 67.082977 67.895508 68.715286 69.540787 70.372009
*/


// Program 4
#include <stdio.h>
#include <mpi.h>

#define N 20
float fx(float x){
  return x*x*x*x+2*x*x*x+2;  
}
int main(int argc, char *argv[]){

    MPI_Init(&argc,&argv);


  int i;
  float h = 0.01, a = 2.0;
  float daoham[N];

  	int Ncpu, IDcpu;
	MPI_Comm_size(MPI_COMM_WORLD,&Ncpu);
	MPI_Comm_rank(MPI_COMM_WORLD,&IDcpu);

     int ms = N/Ncpu; 
    float daohams[ms];
    int is;


  for (i=0; i<ms; i++) {
       is=i+ms*IDcpu;
      daohams[i] = (fx(a+is*h)- fx(a+is*h-h))/h;

  }

MPI_Gather(daohams, ms,MPI_FLOAT,daoham,ms,MPI_FLOAT,0,MPI_COMM_WORLD);


if(IDcpu==0) {
  printf("Ket qua dao ham:\n");
  for (i=0; i<N; i++)
      printf("%f ",daoham[i]);
  printf("\n");    
}
    MPI_Finalize();

  return 0;
}


/*
CHÚ Ý:
- Mã nguồn GỐC khi CHẠY TRÊN MÁY CỦA SINH VIÊN cho kết quả 'GẦN BẰNG' YÊU CẦU ĐỀ RA.
- OUTPUT tại MÁY SINH VIÊN: 55.641174 56.360626 57.087326 57.818985 58.557129 59.301376 60.051346 60.808563 61.569977 62.339783 63.114166 63.895416 64.683533 65.476990 66.276550 67.082977 67.895508 68.715286 69.540787 70.372009
*/

//Ket qua dao ham:
// 55.640949 56.361008 57.087006 57.819031 58.557152 59.301414 60.051449 60.808022 61.570717 62.339489 63.114258 63.895683 64.682877 65.478371 66.276978 67.083153 67.895889 68.714943 69.540421 70.372421