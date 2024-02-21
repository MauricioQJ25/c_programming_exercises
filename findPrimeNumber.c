// program: findPrimeNumber.c

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
    printf("This program find a prime number provided by the user \n ");
    printf("$./findPRimeNumber.c <Int>");

    int number = atoi(argv[1]);
    int flag = 0;
    for (int i = 2; i <= number / 2; i++ ){
        if((number % i) == 0){
            flag = 1;
            break;
        }
    }

    if(flag == 1){
        printf(" This number is not prime \n");
    }
    else{
        printf(" This number is prime \n");

    }
    return 0;
}

