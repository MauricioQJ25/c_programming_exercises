#include <stdio.h>

//          FF
// FF FF FF FF
//--------------
//
//
//
//
// 100
// 1002
// 1000
//------------
void swapp(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseString(char *s, int length){
    // 123456 7  L
    // 012345 6  P
    // ABCDEF \0 S
    int j = length - 2;
    for (int i = 0; i < (length - 1)/2; i++){
        swapp(&s[i], &s[j]);
        j--;
    }
}


// FF FF FF FF  FF FF FF FF
int main(int argc, char* argv[]){
    char h[14] = "the black cat";
    int length = sizeof(h);

    printf("before reverse \n %s \n", h);
    reverseString(h, 14);
    printf(" after reverse \n %s\n", h);
    
    int initial = 0;
    int ending = 0;
    for(int i = 0; i < 14; i++){
        if (h[i] == ' ' || h[i] == '\0'){
            ending = i;
            reverseString(&h[initial], ending - initial + 1);
            initial = ending + 1;
        }
    }
    printf(" after another reverse (word by word) \n %s\n", h);

    printf("size of int: %ld bytes, size of char: %ld bytes\n", sizeof(int), sizeof(char));

    return 0;
}