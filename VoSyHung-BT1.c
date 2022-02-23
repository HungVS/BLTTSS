#include <omp.h>
#include <stdio.h>

int main() {

    int threadID;
    int numThreads=5;
  
   omp_set_num_threads(numThreads); 
    #pragma omp parallel private(threadID)
    { 
    threadID = omp_get_thread_num();
    printf("ID%d: Vo Sy Hung, 22 tuoi, que quan Ha Noi\n", threadID);
    }
    return 0;
}

/* OUTPUT: 
ID4: Vo Sy Hung, 22 tuoi, que quan Ha Noi
ID0: Vo Sy Hung, 22 tuoi, que quan Ha Noi
ID1: Vo Sy Hung, 22 tuoi, que quan Ha Noi
ID3: Vo Sy Hung, 22 tuoi, que quan Ha Noi
ID2: Vo Sy Hung, 22 tuoi, que quan Ha Noi
*/