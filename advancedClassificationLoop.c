#include <stdio.h>
#include <math.h>
#include "NumClass.h"

#define FALSE 0
#define TRUE 1


int isArmstrong(int number){
   if (number<0) return FALSE;
   int num=number;
   int count=0, sum=0, pow_n=0;
   while (num!=0)
   {   count++;
       num=(int)num/10;
   }
   num=number;
   while (num!=0)
   {   int n=num%10;
       pow_n= (int)pow(n,count);
       sum+=pow_n;
       num=(int)num/10;
   }
   if (sum==number) return TRUE;
   else return FALSE;
}



int isPalindrome(int number){
    if (number<0) return FALSE;
    int ans=TRUE;
    int f_num=number, l_num=0, num2=number;
    int count=0;
    while (f_num!=0)
    {   count++;
        f_num=(int)f_num/10;
    }
    for (int i = 1; i < count && ans==TRUE; i++)
    {  int divide=(int)pow(10,count-1);
       f_num=(int)number/divide;
       f_num=f_num%10;
       l_num=num2%10;
       if(f_num!=l_num) ans=FALSE;
       num2=(int)num2/10;
       count--;
    }
    if (ans==TRUE) return TRUE;
    else return FALSE;
}