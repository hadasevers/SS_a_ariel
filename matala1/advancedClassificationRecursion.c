#include <stdio.h>
#include <math.h>
#include "NumClass.h"

#define FALSE 0
#define TRUE 1


int isArmstrong(int number){
    if (number<0) return FALSE;
    int num=number;
    int sumArmstrong(int number);
    int num_Amstrong=sumArmstrong(num);
    if (num==num_Amstrong) return TRUE;
    else return FALSE;
}


int sumArmstrong(int number){
     int sum=0, num=number;
    if (num==0) return sum;
    else{
        int count=0, i=0;
        while (num!=0)
        {   count++;
            num=(int)num/10;
        }
        num=number;
        int n=num%10;
        while (n==0)
        {  i++;
           num=(int)num/10;
           n=num%10;
        }
        num=(int)num/10;
        num=num*(int)pow(10,i+1);
        int pow_n=(int)pow(n,count);
        sum=pow_n+sumArmstrong(num);
        return sum;        
    }
}




int isPalindrome(int number){
    if (number<0) return FALSE;
    int ans=TRUE;
    if (number==0 || (int)number/10==0)
        return TRUE;
    else{
       int f_num=number, l_num=number;
       int count=0;
       while (f_num!=0)
       {   count++;
           f_num=(int)f_num/10;
       }
       int divide=(int)pow(10,count-1);
       f_num=(int)number/divide;
       l_num=l_num%10;
       if(f_num!=l_num) ans=FALSE;
       else ans=TRUE;
       number=number-(f_num*divide);
       number=(int)number/10;
       int c2=0;
       int num=number;
       while (num>0)
       {   c2++;
           num=(int)num/10;
       }
       if (count-2-c2==0)
           return(ans && isPalindrome(number));
       else { int zero=TRUE;
              for (int i= 0; i < (count-2-c2) && (zero==TRUE) && (number>0); i++)
                { if(number%10!=0) zero=FALSE;
                  number=(int)number/10;
                }
              if (zero==TRUE) return(ans && isPalindrome(number));
              else return FALSE;
        }
       
    }

}
