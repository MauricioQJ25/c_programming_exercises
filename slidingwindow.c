#include <stdio.h>

// [0 1  2]
// 12,9,23,17,25
//

// This function is going  to return and index where 
// the 5 expensive continuos book are stored
// using the slide window technique
int slideWindow(int* array, int size, int window,int* sum){
    int j = 0;
    int oldsum = 0;
    int position = 0;
    int newsum = 0;
    int previoussum = 0;
    while(j < window){
            previoussum = array[j] + previoussum;
            j++;
    }
    for(int i = 0; i < size - window; i++){
        newsum = previoussum + array[i + window] - array[i];
        if(newsum > oldsum){
            oldsum = newsum;
            position = i + 1;
        }
    }
    *sum = oldsum;

    return position;
}

int main(int argc, char* argv[]){
    int array[] = {12,9,23,17,25,19,4,8,21,343,26,17,19,14,27,22,1500,7,2,14,5,18,24};
    int w_size = 5;
    int a_size = sizeof(array)/ sizeof(array[0]);
    int sum = 0;
    int index = slideWindow(array, a_size, w_size, &sum);
    printf("The most expensive continues books start at position %d,\n and the cost is %d\n", index, sum);
    return 0; 
}