#include <sys/time.h>
#include <omp.h>
#include<stdio.h>
#include <stdlib.h>
#define dim 1000000 
struct timeval t1, t2;
int partition(int * a, int ini, int fin){

    int* a1 = (int*)malloc(sizeof(int) * (fin-ini));
    int* a2 = (int*)malloc(sizeof(int) * (fin-ini));
    int pivot = a[fin]; 
    int a1_n = 0;
    int a2_n = 0;

    for(int i = ini; i < fin; i++){
        if(a[i] < a[fin]){
            a1[a1_n++] = a[i];
        }else{
            a2[a2_n++] = a[i];
        }   
    }   
    for(int i = 0; i < a1_n; i++){
        a[ini + i] = a1[i];
    }   
    a[ini + a1_n] = pivot;
    for(int j = 0; j < a2_n; j++){
        a[ini + a1_n + j + 1] = a2[j];
    }   
    return ini + a1_n;
}

void quicksort(int * a, int ini, int fin){
    int div;
    if(ini < fin){ 
        div = partition(a, ini, fin); 
      	#pragma omp task shared(a) 
        quicksort(a, ini, div - 1); 
       #pragma omp task shared(a) 
        quicksort(a, div + 1, fin); 
    }
}

//Funcion para chequear si el arreglo está ordenado
void check(int* A, int n){
    for (int i = 0; i < n - 1; i++){
        if (A[i] > A[i + 1]) {
            printf("Arreglo desordenado \n");
            return;
        }
    }
    printf("Arreglo ordenado \n");
}


int main(){
    int* arr = (int*)malloc(sizeof(int) * dim);
    srand(time(NULL));
    for(int j=0;j<dim;j++){
        arr[j]=rand() % dim +1;
    }
    check(arr, dim);
    gettimeofday(&t1, 0);
	omp_set_num_threads(4);
 	 #pragma omp parallel
        {
          #pragma omp single
             quicksort(arr,0, dim-1);
        }
    gettimeofday(&t2, 0);
    check(arr, dim);
    double time = (1000000.0*(t2.tv_sec-t1.tv_sec) + t2.tv_usec-t1.tv_usec)/1000.0;
    printf("QUICKSORT PARALELO ---- Tiempo de ejecucion: %3.3f ms \n", time/1000.0);
    return 0;
}