#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"

#define True 1
#define False 0

void build_graph(struct GRAPH_NODE_**head, int num_of_node);
void add_edge(struct GRAPH_NODE_ **head, int src, int dest, int weight);
void add_node(struct GRAPH_NODE_ **head, int id);
void delete_node(struct GRAPH_NODE_ **head, int id);
void shortsPath(struct GRAPH_NODE_ **head, int start, int end);
void TSP(struct GRAPH_NODE_ **head, int *list_nodes, int k);
void deleteGraph(pnode* head);
void daiktra(pnode *head, int start, int *previous);
int get_min(pnode *queue);
int tag(struct GRAPH_NODE_ **head_list, int now_tag, int k);
void printGraph(pnode head);



void build_graph(pnode *head, int num_of_node)
{
    //struct GRAPH_NODE_ *pnode = *head;
    //printf("\n%d = num\n", num_of_node);
   
    // if exist graph
    if (*head != NULL){
        deleteGraph(head);
    }
    // build a new graph
    for (int i = 0; i < num_of_node; ++i)
    {
        add_node(head, i);
    }
}


void add_node(pnode *head, int id)
{ 
    struct GRAPH_NODE_ *pnode = *head;        /*(struct GRAPH_NODE_*)malloc(1*sizeof(struct GRAPH_NODE_));
    if (pnode == NULL)
    {
        printf("There is not enough memory. Exiting.\n");
    } pnode = *head;*/

    
   // ckeck if this node exist
   while (pnode != NULL){
        if (pnode->node_id != id)
            pnode = pnode->next;
        else break;
   }
   // if this node no exist
    if (pnode == NULL){
        struct GRAPH_NODE_ *new_node = (struct GRAPH_NODE_*)malloc(1*sizeof(struct GRAPH_NODE_));
        if (new_node == NULL)
        {
            printf("There is not enough memory. Exiting.\n");
        }
        new_node->node_id = id;
        new_node->tag = 0;
        new_node->weight = 0;
        new_node->edges = NULL;
        new_node->next = *head;
        *head = new_node;
    }
    else // the node exist
    {
      if(pnode->edges != NULL){

            // delete all the edge that start in this node
            struct edge_ **prev_edge = &(pnode->edges);
            struct edge_ *pedge = pnode->edges->next;
            while (pedge != NULL)
            {
                *prev_edge = pedge->next;
                free(pedge);
                pedge = *prev_edge;
            }
        }
    }

   // printGraph(*head);
   //}
   /*
   else{
    pnode->node_id = id;
    pnode->tag = 0;
    pnode->weight = 0;
    pnode->next = *head;
    *head = pnode;
   }    
   */
    //free(pnode);
}


void delete_node(pnode *head, int id)
{ /*
    struct GRAPH_NODE_ *pnode = (struct GRAPH_NODE_*)malloc(1*sizeof(struct GRAPH_NODE_));
    if (pnode == NULL)
    {
        printf("There is not enough memory. Exiting.\n");
    }
    struct GRAPH_NODE_ *next = (struct GRAPH_NODE_*)malloc(1*sizeof(struct GRAPH_NODE_));
    if (next == NULL)
    {
        printf("There is not enough memory. Exiting.\n");
    }
    pnode = *head;
*/

    struct GRAPH_NODE_ *pnode = *head;
    struct GRAPH_NODE_ **prev = head;


    while (pnode != NULL)
    {
        if(pnode->edges != NULL){

            // delete the edge that end in this node
            struct edge_ **prev_edge = &(pnode->edges);
            struct edge_ *pedge = pnode->edges;

            while (pedge != NULL)
            {
                if (pedge->endpoint->node_id == id){
                    *prev_edge = pedge->next;
                    free(pedge);
                    pedge = *prev_edge;
                    break;
                }
                else{
                    prev_edge = &(pedge->next);
                    pedge = pedge->next;
                }
            }
        } 
        pnode = pnode->next;  
    }

    pnode = *head;
    while (pnode != NULL){

        if (pnode->node_id == id){

            if(pnode->edges != NULL){

                // delete all the edge that start in this node
                struct edge_ **prev_edge = &(pnode->edges);
                struct edge_ *pedge = pnode->edges->next;
                while (pedge != NULL)
                {
                    *prev_edge = pedge->next;
                    free(pedge);
                    pedge = *prev_edge;
                }
            }

            // delete the node
            *prev = pnode->next;
            free(pnode);
            pnode = *prev;
            break;          
        }
        else{
             prev = &(pnode->next);
             pnode = pnode->next;
        }
    }


    
    
   // free (pnode);
    //free (pedge);
    //free(next);
}


void add_edge(pnode *head, int src, int dest, int weight)
{
    struct GRAPH_NODE_ *pnode = (*head);     /*(struct GRAPH_NODE_*)malloc(1*sizeof(struct GRAPH_NODE_));
    if (pnode == NULL)
    {
        printf("There is not enough memory. Exiting.\n");
    } */

    struct edge_ *new_edge = (struct edge_*)malloc(1*sizeof(struct edge_));
    if (new_edge == NULL)
    {
        printf("There is not enough memory. Exiting.\n");
    }
  // pnode->edges = (*head)->edges;
  // pnode->next = (*head)->next;
  // pnode->tag = (*head)->tag;
   //pnode->weight = (*head)->weight;

   // find the dest node   
   while (pnode != NULL)
   {
       if (pnode->node_id == dest)
            break;
        else  pnode = pnode->next;           
   }
   
   
    new_edge->weight = weight;
    new_edge->endpoint = pnode;
    

    pnode = *head;
   
   // find the src node
   while (pnode->node_id != src)
   {
      pnode = pnode->next;
   }

    new_edge->next = pnode->edges;
    pnode->edges = new_edge;

   /*
   pedge->next = pnode->edges;
   pnode->edges = pedge;
   */

   //free(pnode);
   //free(new_edge);
}


void deleteGraph(pnode* head)
{
    struct GRAPH_NODE_ *pnode = *head; /*(struct GRAPH_NODE_*)malloc(1*sizeof(struct GRAPH_NODE_));
    if (pnode == NULL)
    {
        printf("There is not enough memory. Exiting.\n");
    } pnode = *head; */

    while (pnode != NULL)
    {
        delete_node(head, pnode->node_id);
        pnode = pnode->next;
    }
}


void shortsPath(pnode *head, int start, int end)
{
    daiktra(head, start, NULL);
    struct GRAPH_NODE_ *pnode = *head;    /*(struct GRAPH_NODE_*)malloc(1*sizeof(struct GRAPH_NODE_));
    if (pnode == NULL)
    {
        printf("There is not enough memory. Exiting.\n");
    } pnode = *head; */

    // fint the pointer on end node
    while (pnode->node_id != end){
        pnode = pnode->next;
    }
    int weight = pnode->weight;
    
    // if not exist route from start node to end node
    if (weight == 1000000)
        printf("Dijsktra shortest path: %d\n", -1);
    else printf("Dijsktra shortest path: %d\n", weight);

    //free(pnode);
}



void daiktra(pnode *head, int start, int *previous)
{
    struct GRAPH_NODE_ *pnode = *head;   /*(struct GRAPH_NODE_*)malloc(1*sizeof(struct GRAPH_NODE_));
    if (pnode == NULL)
    {
        printf("There is not enough memory. Exiting.\n");
    } pnode = *head;*/

    struct GRAPH_NODE_ *current;      /* = (struct GRAPH_NODE_*)malloc(1*sizeof(struct GRAPH_NODE_));
    if (current == NULL)
    {
        printf("There is not enough memory. Exiting.\n");
    }*/
    
    struct edge_ *pedge;      /* = (struct edge_*)malloc(1*sizeof(struct edge_));
    if (pnode == NULL)
    {
        printf("There is not enough memory. Exiting.\n");
    }*/

    int pvs = False;
    if (previous == NULL)
    {
        pvs = True;
    }
       
    pnode = *head;

    // start when the weight of the node is very high, and they don't view
    while (pnode != NULL)
    {
        if (pnode->node_id != start){
            if (pvs == False){
                if ((pnode->tag == 1) || (pnode->tag == 2)){
                    pnode->tag = 0;
                    pnode->weight = 1000000;
                }
            }
            else (pnode->tag = 0);
            pnode->weight = 1000000;
        }
        else{
            pnode->weight = 0;
            // update the tag to be "view"
            pnode->tag = 1;
            if (pvs == False) previous[start] = -1000000;
        }
        pnode = pnode->next;
    }
    pnode = *head;

    // this loop update all the routes from start node to all the node in the graph.
    while (get_min(head) != -1)
    {
        int min_node = get_min(head);
        if (min_node == -1) break;
        current = *head;

        // fint the pointer on min_node
        while (current->node_id != min_node){
            current = current->next;
        }
        // update the tag to be "used"
        current->tag = 2;
        pedge = current->edges;
        
        while (pedge != NULL)
        {
            int new_weight = current->weight + pedge->weight;
            if (new_weight < pedge->endpoint->weight){
                pedge->endpoint->weight = new_weight;
                if (pvs == False) previous[pedge->endpoint->node_id] = current->node_id;
            }
            if (pedge->endpoint->tag == 0){
                pedge->endpoint->tag = 1;
            }
            pedge = pedge->next;
        }
    }
    //free(pnode);
    //free(current);
    //free(pedge);
    //if (pvs == True)
      //  free(previous);
    //return head;
}



// return the node with min weight
int get_min(pnode *queue)
{
    struct GRAPH_NODE_ *pnode = *queue;    /*(struct GRAPH_NODE_*)malloc(1*sizeof(struct GRAPH_NODE_));
    if (pnode == NULL)
    {
        printf("There is not enough memory. Exiting.\n");
    } pnode = *queue;*/

    int min_id = -1;
    int min_weight = 1000000;

    while (pnode != NULL)
    {
        if (pnode->tag == 1){            
            if (min_weight > pnode->weight){
                min_weight = pnode->weight;
                min_id = pnode->node_id;
            }
        }
        pnode = pnode->next;
    }
    //free(pnode);
    return min_id;
    // if return -1 : no exist node with tag 1 - node that view but no used
}


void TSP(pnode *head, int *list_nodes, int k)
{
    struct GRAPH_NODE_ **head_list = (struct GRAPH_NODE_**)malloc(k*sizeof(struct GRAPH_NODE_*));
    if (head_list == NULL){
        printf("There is not enough memory. Exiting.\n");
    }
    struct GRAPH_NODE_ *pnode = *head; /*(struct GRAPH_NODE_*)malloc(1*sizeof(struct GRAPH_NODE_));
    if (pnode == NULL){
        printf("There is not enough memory. Exiting.\n");
    }*/

    int *list_weight = (int*)malloc(k*sizeof(int));
    if (list_weight == NULL){
        printf("There is not enough memory. Exiting.\n");
    }

    pnode = *head;
    // find the max id node in order to build an array when in the index of the array will be the node with the same id.
    int max_id = 0;
    while (pnode != NULL){
        if (pnode->node_id > max_id)
            max_id = pnode->node_id;
        pnode = pnode->next;
    }
    max_id++;
    
    // array for the previous node that "pointed me"
    int *previous = (int*)malloc(max_id*sizeof(int));
    if (previous == NULL)
    {
        printf("There is not enough memory. Exiting.\n");
    }
    // to start previous with value -1
    for (int i = 0; i < max_id; ++i)
    {
        previous[i] = -1;
    }
    

    pnode = *head;

    // this loop build an array of pointers that point on the nodes in list_nodes.
    for (int i = 0; i < k; ++i)
    {
        struct GRAPH_NODE_ *pnode2 = *head;
        while (pnode2->node_id != list_nodes[i]){
            pnode2 = pnode2->next;
        }
        head_list[i] = pnode2;        
    }
    
    for (int i = 0; i < k; ++i)
    {
        int now_tag = 3;
        int id_node = list_nodes[i];
        int all_weight = 0;
        int Flag = True;

        for (int j = 0; j<k; ++j){
            head_list[j]->tag = 0;
        }
        
        // there are more node in list_nodes that still no view
        while ((tag(head_list, now_tag, k) == True) && (Flag==True))
        {
            daiktra(head, id_node, previous);
            head_list[i]->tag = now_tag;
            for (int j = 0; j<k; ++j){
                if (head_list[j]->node_id == id_node)
                    head_list[j]->tag = now_tag;
            }
            int min_node = -1;
            int weight = 10000000;

            //pnode = *head_list;
            // find the lowest weight id_node
            //while (pnode != NULL)
            
            for (int j=0; j<k; ++j)
            {
                if ((head_list[j]->tag != now_tag) && (head_list[j]->weight < weight)){
                    weight = head_list[j]->weight;
                    min_node = head_list[j]->node_id;
                }
                //pnode = pnode->next;
            }
            
            // if there isn't route that pass at all the node in the list, that start in this node
            if (weight == 1000000){
                //return;
                Flag = False;
            }
            all_weight = all_weight + weight;
            pnode = *head_list;

            // find the pointer of min_node
            for (int j=0; j<k; ++j){
                if (head_list[j]->node_id == min_node)
                    pnode = head_list[j];
            }
            pnode->tag = now_tag;
            id_node = pnode->node_id;

            // check the nodes between src to thhs node. if there is node between them that exist in the kust, uptade it to be "view"
            int prev = previous[id_node];
         
            while ((prev != -1000000) && (Flag == True))
            {
                pnode = *head_list;
                for (int p = 0; p < k; p++){
                    if (prev == head_list[p]->node_id){
                        head_list[p]->tag = now_tag;
                        p = k;
                    }
                    //else pnode = pnode->next; 
                }
                prev = previous[prev];
            } 
        }
        list_weight[i] = all_weight;              
    }
    int route = 1000000;
    for (int i = 0; i < k; ++i){
        if (list_weight[i] < route)
            route = list_weight[i];
    }
    if (route == 1000000) route = -1;
    free(list_weight);
    //free(pnode);
    free(head_list);
    free(previous);
   // printf("\n");
    printf("TSP shortest path: %d\n", route);   
}


int tag(struct GRAPH_NODE_ **head_list, int now_tag, int k){
    /*struct GRAPH_NODE_ *pnode = *head_list;(struct GRAPH_NODE_*)malloc(1*sizeof(struct GRAPH_NODE_));
    if (pnode == NULL){
        printf("There is not enough memory. Exiting.\n");
    }
    pnode = *head_list;*/

    int ans = False;

    for (int i = 0; i < k; ++i)
    {
        if (head_list[i]->tag != now_tag)
            ans = True;
    }
    //free(pnode);
    return ans;
}


void printGraph(pnode head){ //for minself debug
    while (head != NULL)
    {
        printf("\nthe dest of edge that start in node number %d:", head->node_id);
        struct edge_ *pedge = head->edges;
        while (pedge != NULL)
        {
            printf(" %d", pedge->endpoint->node_id);
            pedge = pedge->next;
        }

        head = head->next;        
    }
    printf("\n");
}