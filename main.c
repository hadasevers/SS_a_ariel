#include <stdio.h>
#include "NumClass.h"

#define FALSE 0
#define TRUE 1

int main(){

    int min=0, max=0;
    scanf("%d%d" , &min , &max);
    printf("\n");
    int num=min;
    if (min>max){
        num=max;
        max=min;
        min=num;
    }

    printf("The Armstrong numbers are:");
    while (num<=max)
    { if (isArmstrong(num)==TRUE)
           printf(" %d",num);
      num++;
    }

    num=min;
    printf("\n");

    printf("The Palindromes are:");
    while (num<=max)
    { if (isPalindrome(num)==TRUE)
           printf(" %d",num);
      num++;
    }

    num=min;
    printf("\n");

    printf("The Prime numbers are:");
    while (num<=max)
    { if (isPrime(num)==TRUE)
           printf(" %d",num);
      num++;
    }

    num=min;
    printf("\n");

    printf("The Strong numbers are:");
    while (num<=max)
    { if (isStrong(num)==TRUE)
           printf(" %d",num);
      num++;
    }
    printf("\n");
    printf("\n");
    return 0;
}
