// Program 3
#include <stdio.h>
#include <malloc.h>
#include <mpi.h>
#define m 5
int main(int argc, char *argv[])
{
  int i, rank, size, M;
  MPI_Status status;
//Khai báo, cấp phát bộ nhớ
  int *A, *Ac;
  Ac = (int *) malloc (m*sizeof(int));
// Khoi tao MPI
  MPI_Init(&argc,&argv);
// Tinh so process: size, gan ID cho tung process:rank  
  MPI_Comm_size(MPI_COMM_WORLD,&size);    
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
// Tinh kich thuoc cua cac ma tran lớn
  M = m*size;
// Cap phat bo nho cho cac ma tran con
  A = (int *) malloc (M*sizeof(int));
// Khoi Tao Du Lieu (Ma tran Ac) tai tat ca cac process
  for (  i = 0 ; i < m ; i++ )
       *(Ac+i) = i;
// Gui gia tri ma tran Ac tu tat ca cac process ve process 1
  /* Sinh viên bổ sung code ở đây
     --------------------------
     --------------------------
   */
MPI_Gather(Ac, m,MPI_INT,A,m,MPI_INT,1,MPI_COMM_WORLD);
// Hien thi Ma tran A tai process 1;
  /* Sinh viên bổ sung code ở đây
     --------------------------
     --------------------------
   */
   if (rank==1)
		for (i=0;i<M;i++) printf("%d  ",*(A+i)); printf("\n");
//
  MPI_Finalize();
  return 0;
}

/* OUTPUT của SINH VIÊN: 
0  1  2  3  4  0  1  2  3  4  0  1  2  3  4  0  1  2  3  4
*/
