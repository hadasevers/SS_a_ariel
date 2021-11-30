#include <stdio.h>
#include "my_mat.h"

int main(){
    
    char fun='A';
    int i=0,j=0;

    scanf("%c" , &fun);

    while (fun!='D'){
        if (fun=='A')
            mat_value();
        else if (fun=='B'){
                 scanf("%d%d" , &i, &j);
                 exists_route (i,j);
               }
            else if (fun=='C') {
                scanf("%d%d" , &i, &j);
                short_Route (i,j);
            }       
        scanf("%c" , &fun);
    }
    return 0;
}


