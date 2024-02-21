// bubble sort
#include <stdio.h>

// Sort using pointers
void sort(int* p, int n){
    for( int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(*(p + j) < *(p + i)){
                int temp = *(p + j);
                *(p + j) = *(p + i);
                *(p + i) = temp;
            }
        }
    }
}

// sort using square brackets 
void sortSB(int* p, int n){
    // notice that n - 1 is required because the last comparision when i is n-1  and j is n
    // so when i is n -1 is not longer required
    for( int i = 0; i < n - 1 ; i++){
        for(int j = i + 1; j < n; j++){
            if(p[j] < p[i]){
                int temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }
}

// 0 1 2 3  4  5
//           i
// 3 6 9 13  19
//              j    
// (j < i) ? swapp : ;    
int main(int argc, char* argv[]){
    int n = 5;
    int array[] = { 13, 6, 9, 19, 3};
    sortSB(array, n);
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}