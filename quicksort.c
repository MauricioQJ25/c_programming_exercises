#include <stdio.h>

//          P
//       i
//   5 3 2 [9] 10
//         j
// (j < P): i++, swap A[j], A[i]
// swapp <A[P]>, A[i+1]

void swapp(int* a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int* p,int n){
    for(int i = 0; i < n; i++){
        printf("%d ", *p++);
    }
        printf("\n ");
}

int getPivotA(int* array, int low, int high){
    int pivote = array[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if( array[j] <= pivote){
            i++;
            swapp(&array[j], &array[i]);
        }
    }
    swapp(&array[i + 1], &array[high]);
    return i + 1; 
}

int getPivotB(int* array, int low, int high){
    int pivote = array[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if( array[j] >= pivote){
            i++;
            swapp(&array[j], &array[i]);
        }
    }
    swapp(&array[i + 1], &array[high]);
    return i + 1; 
}

void quicksort(int* array, int low, int high, int (*getPivot)(int* array, int low, int high)){
    if (low < high){
        int pi = getPivot(array, low, high);
        quicksort(array, low, pi - 1, getPivot);
        quicksort(array, pi + 1, high, getPivot);
    }
}


int main(int argc, char* argv[]){
    int array[] = {234,23,53,45,276,4,2,237};
    int size = sizeof(array) / sizeof(array[0]);
    printf("Size: %d\n", size);
    printArray(array, size);

    quicksort(array, 0, size - 1, getPivotA);
    printArray(array, size);

    quicksort(array, 0, size - 1, getPivotB);
    printArray(array, size);
    return 0;
}