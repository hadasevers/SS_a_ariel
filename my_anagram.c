#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

#define True 0
#define False 1
#define WORD 30

#define TXT 1024
#define WORD 30

char *in_word = NULL;
int is_print = False;

void anagram(char *word, char *text){

    void to_in(char *in_word, char *word);
    int is_exsist(char c);
    void print_anagram(char *text, int i, int k);

    int i=0, j=0, exsist=True;
    char t=text[0];

    printf("Anagram Sequences: ");

    in_word = (char*)malloc(WORD*sizeof(char));
    if (in_word==NULL){
        printf("There is not enough memory. Exiting.\n");
    }

    while ((text[i] != '~') && (i<TXT))
    {   
        int k=0;
        j=0;
        exsist=True;
        t = text[i];
        to_in(in_word, word);
        if (i<TXT) t=text[i];

        while (((word[j]!='\n') && (word[j]!='\t') && (word[j]!=' ')) && (exsist==True) && (t != '~'))
        {   
            if (t != ' ') {        
                exsist=is_exsist(t);
                j++;
            }
            
            k++;
            t = text[i+k];
        }

        if ((exsist==True) && ((word[j]=='\n') || (word[j]=='\t') || (word[j]==' ')))
                print_anagram(text, i, i+k);
        else if (exsist==True) break;   

        i++;
    }
    free(in_word);
}


// build char array of the word char's
void to_in(char *in_word, char *word){
    
    int i=0;
    while ((word[i]!='\n') && (word[i]!='\t') && (word[i]!=' '))
    {
       in_word[i]= word[i];
       i++;
    }
    in_word[i]='\n';
}


// check if this char exsist in the word
int is_exsist(char c){

    int i=0, in=True;
    while (in_word[i]!='\n')  //we have more chars in the word
    {
      if (c==' ') return True;
      else if  (c==in_word[i]){
               in_word[i]=' '; // or NULL
               return True;
            } 
            else in=False;
      i++;
    }
    return in;
}


// print the anagram
void print_anagram(char *text, int i, int k){
    if (text[i] != ' '){
        if (is_print == True) printf("~");
        else is_print = True;        

        while (i < k)
            {
            printf("%c", text[i]);
            i++;
            }
    }
}