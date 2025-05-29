
/** Bubble sort - step by step discussion 
 *
**/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void swap(int* a, int* b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
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

void bubble_sort(int*arr, int n) {
    for(int i = 0; i < n; i++) {
        bool swapped = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
                printf("\t(%d, %d)", i, j);
                print_array(arr, n);
            }
        }
        print_array(arr, n);
        if(!swapped) {
            break;
        }
    }
}


int main(int argc, char* argv[]) {
    srand(time(NULL)); 
    int size = atoi(argv[1]);

    int arr[size];

    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 10; // MOD - 0, n-1
    }
    print_array(arr, size);

    bubble_sort(arr, size);

    print_array(arr, size);
}

/*
4, 2, 3, 5, 1
         j, j+1
            J,  j+1 // error
for i = 0 to n-1:        // loop, i < n
   swapped = false       
   for j = 0 to n-i-2:           // loop,  j < n-i-1
      if A[j] > A[j+1]:          
         swap(A[j], A[j+1])          
         swapped = true    
   if not swapped:       
       break 

*/
// 8 -  we have O(n)
  ///           O(n)   = O(n) * O(n) = O(n^2)


// pseudo code for insertion sort and selection sort

/*
 [2, 4, 5, 6, 3], 3
 [2, 4, 5, 6, 6]
 [2, 4, 5, 5, 6]
 [2, 4, 4, 5, 6]
 [2, 3, 4, 5, 6]





*/


/*
Algorithm InsertionSort(A)
    Input: List A of 𝑛 elements
    Output: Mutates sorted array (A) in  		     ascending order

for i = 1 to n-1:                                       [5, 4, 6, 2, 3], 4   
    key = A[i]                                          [5, 5, 6, 2, 3] => [4, 5, 6, 2, 3]
    j = i                                               [4, 5, 6, 2, 3], 2, [ 4, 5, 6, 6, 3], [4, 5, 5, 6, 3], [4, 4, 5, 6, 3], [2, 4, 5, 6, 3]
    while j > 0 and A[j-1] > key:
        A[j] = A[j-1]
        j = j – 1
    A[j] = key
*/

/* selection pseudo code

for i = 0 to n-1:                   // loop through entire array             [5, 2, 3, 6, 1] 
    minIndex = i                    // assuming smallest starts our location [5 is smallest]
    for j = i+1 to n-1:             // start at i+1 until entire array  
       if A[j] < A[minIndex]:         // we check if one is smaller. keep updating every time
        minIndex = j
    if minIndex != i:                 // swap current with smallest   [1, 2, 3, 6, 5]
        swap(A[i], A[minIndex])

*/