#include<stdio.h>
#include<stdbool.h>

int pow_(int base, int pow){
    if(pow == 0){
        return 1;
    }
    return base * pow_(base, pow - 1);
}

int reversenumber(int number){
    int new = 0;
    int res = 0;
    int pow = 0;
    int i = 0;
    
    while (number != 0){
        res = number % 10;
        new = res +  10* new;
        number = number / 10;
        i++;
    }

    return new;


}

bool isPalindrome(int number){
    int reverse = reversenumber(number);
    // 78945654987
    int res1 = 0;
    int res2 = 0;
    while (reverse != 0){
        res1 = number % 10;
        res2 = reverse % 10;
        if(res1 != res2){
            return false;
        }
        number = number / 10;
        reverse = reverse / 10;
    }

    return true;
}

int replaceZeroWithOne(int number){
    int new = 0;
    int i = 0;
    while (number != 0){
        if(number % 10 == 1){
            new = 0  * pow_(10, i) + new;
        }
        else{
            new = 1 * pow_(10, i) + new;
        }
        number = number / 10;
        i++;
    }

    return new;
}

int main(int argc, char* argv[]){
    int number = 7436547;

    int reverse = reversenumber(number);
    printf("The number after operation is %d \n", reverse);
    bool palindrome = isPalindrome(number);
    if(palindrome == true){
        printf("The number is palindrome \n");
    }
    else{
        printf("The number is NOT palindrome \n");
    }

    int num = 1010001;

    int new = replaceZeroWithOne(num);

    printf("new num %d\n", new);
    
    return 0;
}