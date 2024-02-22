#include <stdio.h>

int calculatePow(int base, int pow){
    if (pow == 0){
        return 1;
    }else{
        return base * calculatePow(base, pow-1);
    }
}

int main(int argc, char* argv[]){
    int original = 10001000;
    printf(" the original number is %d \n", original);
    int newNumber = 0;
    int i = 0;
    while(original  != 0){
        if (original % 10 == 0){
            newNumber = newNumber + 1 * calculatePow(10, i);
        }
        original /=10;
        i++;
    }
    printf(" the output number    is %d \n", newNumber);
}