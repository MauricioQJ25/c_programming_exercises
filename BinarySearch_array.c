#include <stdio.h>

// 1001
//  0        3              6
// {12,13,15,56,487,1000, 4567};
//
// 4  5      6
//487,1000, 4567
// return -1 not success
// return a position if we find the number

int binarySearch(int array[],int low,  int  high, int x){
    if(high >= low){
        int mid = (high - low ) / 2 + low;
        printf("mid= %d array[mid]= %d \n", mid, array[mid] );
        if (array[mid] == x){
         return mid;
        } else if( array[mid] > x){
            binarySearch(array, low, mid - 1, x);
        } else if (array[mid] < x){
            binarySearch(array, mid + 1, high, x);
        } 
    } else {
        return -1;
    }
}

int main(int argc, char* arg[]){
    int array[] = {12, 13, 15, 56, 487, 1000, 4567};
    int size = sizeof(array)/sizeof(array[0]);

    // x is the number we need to search 
    int x = 1001;
    int position =  binarySearch(array, 0, size - 1, x);
    printf("Size of array: %d\n", size);

    if (position == -1){
        printf("The number %d is not in the array \n", x);
    } else {
        printf("Then number %d is in the position %d \n", x, position);
    }
    return 0;
}