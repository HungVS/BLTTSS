// Program 3
#include <stdio.h>
#include <mpi.h>
#include <malloc.h>


#define M 20
int main(int argc, char *argv[])
{
  int i, rank, size, m;
  MPI_Status status;
//Khai báo, cấp phát bộ nhớ
  int *A, *Ac;
  A = (int *) malloc (M*sizeof(int));
// Khởi tạo MPI
  MPI_Init(&argc,&argv);
// Tính số Core: size, gán ID cho từng Core:rank  
  MPI_Comm_size(MPI_COMM_WORLD,&size);    
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
// Tính kích thước các ma trận con
  m = M/size;
// cấp phát bộ nhớ cho các ma trận con

Ac = (int *) malloc (m*sizeof(int));
// Khởi tạo dữ liệu cho ma trận A tại Core 0
  if (rank==0) 
   for (i = 0 ; i < M ; i++ )
       *(A+i) = i;
// Chia đều A từ Core 0 cho tất cả các Core
  /* Sinh viên bổ sung code ở đây
     --------------------------
     --------------------------
   */
   MPI_Scatter(A,m,MPI_INT,Ac,m,MPI_INT,0,MPI_COMM_WORLD);
// Hiển thị giá trị ma trận con Ac tại core 0;
  /* Sinh viên bổ sung code ở đây
     --------------------------
     --------------------------
   */
   if(!rank) {
       for(i=0;i<m;i++){
           printf("%d ", Ac[i]);
       }
   }
//
  MPI_Finalize();
  return 0;
}

