#include<stdio.h>
// key 2
//   i
// 2,3,3,4,8,56,69
// j

// insertion is at j + 1 after compare
void insertionSort(int* array, int n){
    int j = 0;
    int key;
    for (int i = 1; i < n;i++){
        j = i -1;
        key = array[i];
        while( j >= 0 && array[j] > key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }

}

int main(int argc, char* argv[]){

    int array[] = {56,3,4,8,1,2,69};
    int size =  sizeof(array) / sizeof(array[0]);

    insertionSort(array, size);

    for( int i = 0; i < size; i++){
        printf("array[%d] = %d \n", i, array[i]);
    }
    return 0;
    
}