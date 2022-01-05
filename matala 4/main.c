#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"

# define TXT 400


int main()
{
    // function statement
    int num_of_str(char *text);
    char** in_str(char **input, char *text);
    //
    
    struct GRAPH_NODE_ *pnode = NULL;
    struct GRAPH_NODE_ **head = NULL;
    head = (struct GRAPH_NODE_**)malloc(1*sizeof(struct GRAPH_NODE_*));
    if (head == NULL){
        printf("There is not enough memory. Exiting.\n");
        return 0;
    }
    *head = pnode;
    int num = 0;

    char **input = NULL;
    /*
    char *text = (char*)malloc(TXT*sizeof(char));
    if (text == NULL){
        printf("There is not enough memory. Exiting.\n");
        return 0;
    }
    
    */

    char text[TXT];
   
    fgets(text, TXT, stdin);
    
    int len = num_of_str(text);
    input = (char**)malloc(len*sizeof(char*));
    if (input == NULL){
        printf("There is not enough memory. Exiting.\n");
        return 0;
    }

    // now the input array update with the string from the input
    input = in_str(input, text);


    for (int i = 0; i < len; ++i){
    //while (i < len){
        if ((strcmp(input[i], "A") == 0) && (i < len))
        {  
            if (i+1 >= len) break;
            num = atoi(input[i+1]);
            
            //if (*head == NULL)
            build_graph(head, num);  // לטפל בגישה הישירה למצביע לראש הגרף
            if (i+2 < len){
                if (strcmp(input[i+2], "A") == 0)
                    i++;
                else i += 2;
            }

            // build edges
            while ((strcmp(input[i], "n") == 0) && (i < len)){
                if (i+1 >= len) break;
                int src = atoi(input[i+1]);
                i++;
                if (i+1 < len)
                    i += 1;
                else break;
                // while this number
                while ((strcmp(input[i], "n") != 0) && (strcmp(input[i], "A") != 0) && (strcmp(input[i], "B") != 0) && (strcmp(input[i], "D") != 0) && (strcmp(input[i], "S") != 0) && (strcmp(input[i], "T") != 0) && (strcmp(input[i], "\n")) && (i < len))
                {
                    if (i+1 >= len) break;
                    int dest = atoi(input[i]);
                    int weight = atoi(input[i+1]);
                    i++;

                    add_edge(head, src, dest, weight);

                    if(i+1 < len)
                        i ++;
                    else break;
                }              
            }
            //printGraph(*head);

            if (i+1 < len){ 
                if (strcmp(input[i+1], "A") == 0)
                    continue;
            }
        }

        if ((strcmp(input[i], "B") == 0) && (i < len))
        {
            if (i+1 >= len) break;
            int id = atoi(input[i+1]);
            i++;
 
            add_node(head, id);
            //printGraph(*head);

            if (i+1 >= len) break;
            i++;

            while ((strcmp(input[i], "n") != 0) && (strcmp(input[i], "A") != 0) && (strcmp(input[i], "B") != 0) && (strcmp(input[i], "D") != 0) && (strcmp(input[i], "S") != 0) && (strcmp(input[i], "T") != 0) && (strcmp(input[i], "\n")) && (i < len))
                {
                    if (i+1 >= len) break;
                    int dest = atoi(input[i]);
                    int weight = atoi(input[i+1]);

                    add_edge(head, id, dest, weight);
                    if (i+2 < len)
                        i += 2;
                    else break;
                }
                //printGraph(*head); 

                if (strcmp(input[i], "B") == 0)  i--;          
        }

        if ((strcmp(input[i], "D") == 0) && (i < len))
        {
            if (i+1 >= len) break;
            int id = atoi(input[i+1]);
            i++;

            delete_node(head, id);
            //printGraph (*head);
        }

        if ((strcmp(input[i], "S") == 0) && (i < len))
        {
            if ((i+1 >= len) || (i+2 >= len)) break;
            int start = atoi(input[i+1]);
            int end = atoi(input[i+2]);
            i += 2;

            shortsPath(head, start, end);

            if (i+1 >= len) break;
            i++;
        }

        if ((strcmp(input[i], "T") == 0) && (i < len))
        {
            if (i+1 >= len) break;
            int k = atoi(input[i+1]);
            i++;
            // נבנה מערך באורך קיי עבור כל מספרי הקודקודים שינתנו לנו
            int *list_nodes = (int*)malloc(k*sizeof(int));
            if (list_nodes == NULL){
                printf("There is not enough memory. Exiting.\n");
                return 0;
            }
            if (i+1 >= len) break;
            i++;
            for (int j = 0; j < k; ++j)
            {
                list_nodes[j] = atoi(input[i+j]);
            }
            i = i+k-1;
            
            TSP(head, list_nodes, k);

            free (list_nodes);
            //if (i+1 > len) break;
            //i ++;
        }
       
    }
    // in order to free all the nodes and edges
    deleteGraph(head);
     
    free(input);
    free(head);
   // free(text);

    return 0;
}



int num_of_str(char *text){

    int i =0;
    int count = 0;
    // this loop scans the all input
    while ((text[i] != '\0') && (text[i] != '\n'))
    {   
        int j = 0;

        // count the number of character for each string as input
        while ((text[i+j] != ' ') && (text[i+j] != '\0') && (text[i+j] != '\n'))
        {
          j++;
        }

        // count the number of string in the input
        if (j > 0 ){
             count++;
             i = i+ j+1;
        }
        else i++;
    }
    return count;
}



// this func put in the input array all the string in the text
char** in_str(char **input, char *text){
    
    int i = 0, len = 0;

    while ((text[i] != '\0') && (text[i] != '\n'))
    {   
        int j = 0;
        while ((text[i+j] != ' ') && (text[i+j] != '\0') && (text[i+j] != '\n'))
        {
          j++;
        }

        if (j == 0)
            ++i;

        else{
            input[len] = (char*)malloc((j+1)*sizeof(char));
            if (input[len] == NULL)
            {
                printf("There is not enough memory. Exiting.\n");
                return 0;
            }
            for (int k=0; k < j; ++k)
            {
                input[len][k] = text[i+k];
            }
            input[len][j] = '\0'; 
            len++;
            i = i+j;
            j = 0;
            free(input[len]);
        }
    }
    return input;
}
