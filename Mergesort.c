#include <omp.h>
#include<stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define dim 1000000 
struct timeval t1, t2;

int min(int x, int y) {
     return (x<y)? x :y; 
}

void merge(int* arr, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int* L=(int*)malloc(sizeof(int) * n1);
    int* R=(int*)malloc(sizeof(int) * n2);
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr, int n){
   int curr_size; 
   int left_start; 
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size){
       for (left_start=0; left_start<n-1; left_start += 2*curr_size){
           int mid = min(left_start + curr_size - 1, n-1);
           int right_end = min(left_start + 2*curr_size - 1, n-1);
           merge(arr, left_start, mid, right_end);
       }
   }
}

//Funcion para imprimir el arreglo
void printArray(int* A, int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
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
    mergeSort(arr, dim);
    gettimeofday(&t2, 0);
    check(arr, dim);
    double t = (1000000.0*(t2.tv_sec-t1.tv_sec) + t2.tv_usec-t1.tv_usec)/1000.0;
    
    printf("MERGESORT ---- Tiempo de ejecucion: %3.3f ms \n", t/1000.0);
    return 0;
}