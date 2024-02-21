#include <stdio.h>

//char FF        
//int  FF FF FF FF

void swapp(char* a, char* b){
    char temp = *a;
    *a  = *b;
    *b = temp;
}

void reverseString(char* s, int size){
    int j = size;
    for(int i = 0; i < j; i++){
        swapp(&s[i], &s[j]);
        j--;
    }
}

int main(int argc, char* argv[]){
    char string[] = "hola mundo cruel";
    int size = sizeof(string) / sizeof(string[0]);
    reverseString(string, size - 2);
    printf("%s \n", string);

    int index_initial = 0;
    for(int i = 0; i < size; i++){
        if(string[i] == ' ' || string[i] == '\0'){
            // -1 at the end is used to not swapp the space <" "> only the word
            reverseString(&string[index_initial], i - index_initial - 1);
            // skip the space
            index_initial = i + 1;
        }
    }

    printf("%s \n", string);

    return 0;
}