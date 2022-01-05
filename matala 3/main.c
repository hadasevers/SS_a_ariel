#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


#define TXT 1024
#define WORD 30

int main(){

char *text, *word;

word = (char*)malloc(WORD*sizeof(char));
if (word==NULL){
     printf("There is not enough memory. Exiting.\n");
     return 0;
    }
scanf(" "); /*clear input buffer*/
fgets(word, WORD, stdin);

text = (char*)malloc(TXT*sizeof(char));
if (text==NULL){
     printf("There is not enough memory. Exiting.\n");
     return 0;
    }
scanf(" "); /*clear input buffer*/
//scanf("%1024[^~]", text);
int i =0;
char c=' ';
while ((i < TXT) && (c!='~'))
{
   scanf("%c", &c);
   text[i]=c;
   i++;
}

gimatric(word, text);
printf("\n");
atbash(word, text);
printf("\n");
anagram(word, text);

/*Free Memory*/
free(word);
free(text);

    return 0;
}
