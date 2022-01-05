#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

#define True 0
#define False 1

#define TXT 1024
#define WORD 30

int print = False;

void atbash(char *word, char *text){

    char at_value(char c);
    void print_atbash(char *text, int i, int k);

    int i = 0;
    char t = text[0];
    int same = True;
    printf("Atbash Sequences: ");

    while ((text[i] != '~') && (i<TXT))
    {
        int j=0, k=0;
        same=True;
        if (i<TXT) t=text[i];
        
        // loop of "strait" atbash
        while ((word[j] != '\n') && (word[j] != '\t') && (word[j] != ' ') && (same==True) && (t != '~') && (i+k<TXT) && (j<WORD))
        {
            if (at_value(t)==',') j--;
            else if (at_value(word[j]) != t) same=False;
            
            j++;   
            k++;
            t = text[i+k];  
        }
        if (same==True)
            if ((word[j]=='\n')||(word[j]=='\t')||(word[j]==' '))
                print_atbash(text, i, k);   
            else break;    

        else{   // same==false
            int j=0, k=0;
            t = text[i];
            same=True;

            while((word[j] != '\n') && (word[j] != '\t') && (word[j] != ' ')){
                j++;
            }
            j--;

            // loop of "opsite" atbash
            while ((j>=0) && (same==True) && (t != '~'))
            {   
                if (at_value(t)==',') j++;
                else if (at_value(word[j]) != t) same=False;
                
                j--;
                k++;   
                t = text[i+k];  
            }
            if ((same==True) && (j==-1)) 
                print_atbash(text, i, k);
        }
        i++;
    }
}

void print_atbash(char *text, int i, int k){

    char at_value(char c);

    if (at_value(text[i]) != ','){

        if (print == True) printf("~");
        else print = True;

        int end = i+k;

        while (i < end)
            {
            if (at_value(text[i])==',') printf("%c", text[i]);
            else printf("%c", text[i]);
            i++;
            }
    }
}


char at_value(char c){

    if ( c >= 97 && c <= 122){  // if a <= char <= z
        char new = 219-c;
        return new;
    }
    else if ( c >= 65 && c <= 90){  // if A <= char <= Z
            char new = 155-c;
            return new;
        }
        else return ',';
}
