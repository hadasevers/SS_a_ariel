#include <stdio.h>
#include <math.h>
#include "NumClass.h"

#define FALSE 0
#define TRUE 1

int isPrime(int number){
    if (number<=0) return FALSE;
    if (number==1) return TRUE;
    int num= (int)sqrt(number);
    int i=2, ans=FALSE;
    while (i<=num)
    { if (number%i==0) ans=TRUE;
      i++;
    }
    if (ans==TRUE) return FALSE;
    else return TRUE;
}


int isStrong(int number){
    if (number<1) return FALSE;
    int num=number, sum_number=0;
    while (num>0)
    {  int n=num%10;
       int sum_n=1;
       while (n>1)
       {  sum_n*=n;
          n--;
       }
       sum_number+=sum_n;
       num=(int)num/10;
    }
    if (sum_number==number) return TRUE; 
    else return FALSE;
}