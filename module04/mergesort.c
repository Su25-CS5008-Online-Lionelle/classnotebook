#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void merge(int *arr, int left, int mid, int right, int *swapMemory) {
    
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = swapMemory;
    int *R = swapMemory + n1;

    memcpy(L, arr+left, sizeof(int) * n1);
    memcpy(R, arr+mid+1, sizeof(int) * n2);

    int i = 0; // L index
    int j = 0; // R index
    int k = left; // arr index

    while(i < n1 && j < n2){
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k++] = L[i++];
        // k++;
        // i++;
    }
    while(j < n2) {
        arr[k++] = R[j++];
        // k++;
        // j++;
    }

}

void mergeSort(int *arr, int left, int right, int *swapMemory) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, swapMemory);
        mergeSort(arr, mid+1, right, swapMemory);
        merge(arr, left, mid, right, swapMemory);
    }
}





void run_merge(int* arr, int size) {
    int swapMemory[size];
    mergeSort(arr, 0, size-1, swapMemory);
}

void print_array(int * arr, int n) {
    printf("[");
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n-1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main(int argc, char* argv[]) {
    srand(time(NULL)); 
    int size = atoi(argv[1]);

    int arr[size];

    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 10; // MOD - 0, n-1
    }
    print_array(arr, size);

    run_merge(arr, size);

    print_array(arr, size);
}