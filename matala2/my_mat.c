#include <stdio.h>
#include "my_mat.h"

#define False 0
#define True 1

//int mat[10][10];

//A
void mat_value() { 

    for (int i=0; i<10; ++i){
        for (int j=0; j<10; ++j){
            scanf( "%d" , &mat[i][j]);
        }
    }
    void mat_calculate();
    mat_calculate();
}



void mat_calculate(){

    int i=0, j=0, k=0, num1=0, num2=0;

    for (i=0; i<10; ++i){
        for (j=0; j<10; ++j){
            if ((i!=j)&&(mat[i][j]==0))
               mat[i][j]=1000000;
        }
    }

    for (k=0; k<10; ++k){
        for (i=0; i<10; ++i){
            for (j=0; j<10; ++j){
                num1=mat[i][j];
                num2=mat[i][k]+mat[k][j];
                if (num1<num2)  mat[i][j]=num1;
                else  mat[i][j]=num2;
                //mat[i][j]= min(mat[i][j], mat[i][k]+mat[k][j]);
            }
        }
    }
}



//B
void exists_route (int i, int j){ 

    int num=mat[i][j];

    if ((num<1000000)&&(num>0))
        printf("True");
    else
        printf("False");
    printf("\n");
}


 
int is_exist (int i, int j){

    int num=mat[i][j];
    int ans=True;

    if ((num<1000000)&&(num>0))
        ans=True;
    else 
        ans=False;

    return ans;
}


//C
void short_Route (int i, int j){ 
    
    int ans=0;
    if (is_exist(i,j)==True)
       ans=mat[i][j];
    else ans=-1;
    printf( "%d", ans);
    printf("\n");
}
