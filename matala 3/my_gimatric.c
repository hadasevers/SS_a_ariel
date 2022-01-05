#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

#define True 0
#define False 1

#define TXT 1024
#define WORD 30


void gimatric(char *word, char *text){

    int gim_word(char *word);
    int value(char c);
    int print = False;
    int sum = gim_word(word), sub_sum=0, i=0;
    char t = text[0];
    printf("Gematria Sequences: ");

    while ((text[i] != '~') && (i<TXT))
    {
        sub_sum=0;
        int k=0;
        if (i<TXT) t=text[i];

        while ((sub_sum < sum) && (t != '~') && (i+k < TXT))
        {   
            if ((sub_sum == 0 )&&(value(t)==0)) break;
            sub_sum = sub_sum+value(t);
            k++;
            t = text[i+k];
        }

        if ((sub_sum == sum)) {
            int j=0;
            if (print == True) printf("~");
            else print = True;
            
            while (j < k)
            {
               printf("%c" ,text[i+j]);
               j++;
            }
        }
        if (t == '~') break;
        i++;
    }
}


int gim_word(char *word){

    int value(char c);
    int sum = 0, i=0;

    while ((word[i] != '\n') && (word[i] != '\t') && (word[i] != ' ') && (i < WORD))
    {
        sum = sum+value(word[i]);
        i++;
    }
    return sum;
}


int value(char c){
    
    if ( c >= 97 && c <= 122)  // if a <= char <= z
        return c-'a'+1;
    else if ( c >= 65 && c <= 90)  // if A <= char <= Z
            return c-'A'+1;
        else return 0;   
}

