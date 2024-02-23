/* program: mergesort.c */

#include <stdio.h>

// m   
// 9, 8, 6, 5, 7, 4, 0, 1, 2, 3
// [8,9] - [5,6] - [4,7] - [0, 1] - [2,3]
// [5,6, 9, 9]

void merge(int* array, int l, int m, int r){

    int leftlength = m -  l + 1;
    int rightlength = r - m;
    int leftArray[leftlength];
    int rightArray[rightlength];

    int i = 0;
    int j = 0;
    int k = 0;
    for (i = 0; i < leftlength; i++){
        leftArray[i] = array[l + i];
    }
    for (j = 0; j < rightlength; j++){
        rightArray[j] = array[m + 1 + j];
    }
    //              i 
    // left[] =   { 0 5 3 8 2}
    //              j
    // right[] =  { 0 5 8 6 7}
    //             k 
    // array       {                    }
    i = 0;
    j = 0;
    k = 0;
    for (k = l; k <= r; k++){
        if ( i < leftlength &&
          j >= rightlength || leftArray[i] < rightArray[j] ){
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
    }      

}


void mergeSortRecursive(int* array, int l, int r){
    if( l < r){
        int m = l + ((r - l) / 2);
        mergeSortRecursive(array, l, m);
        mergeSortRecursive(array, m + 1, r);
        merge(array, l, m, r);
    } else {
        return;
    }

}


void mergeSort(int* array, int length){
    mergeSortRecursive(array, 0, length - 1);
}

int main(int argc, char* argv[]){
    int array[] = {9,8,6,5,7,4,0,1,2,3};
    int length = sizeof(array)/ sizeof(array[0]);

    mergeSort(array, length);

    for (int i = 0 ; i < length; i++){
        printf("array[%d]= %d\n", i, array[i]);
    }
    return 0;
}