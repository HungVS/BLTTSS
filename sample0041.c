#include <stdio.h>
// #include <malloc.h>
#include <stdlib.h>
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
    // ? : Nhan hay chia
    M = m*size;
    //printf("%d %d %d", M, size, rank);

    // Cap phat bo nho cho cac ma tran con
    A = (int *) malloc (M*sizeof(int));

    // Khoi Tao Du Lieu (Ma tran Ac) tai tat ca cac process
    for (i = 0 ; i < m ; i++ )
        *(Ac+i) = i;

    // Gui gia tri ma tran Ac tu tat ca cac process ve process 1
    // MPI_Scatter(A, M, MPI_INT, Ac, M, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Gather(Ac , m, MPI_INT, A, m, MPI_INT, 0, MPI_COMM_WORLD);

    // Hien thi Ma tran Ac tai process 1;
    if(rank==0){
        for (i = 0; i < M; i++) printf("%d ", *(A+i));
    }

    // MPI_Gather(Cs, ms, MPI_INT, C, ms, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Finalize();
    return 0;
}
