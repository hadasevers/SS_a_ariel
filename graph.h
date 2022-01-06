#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_id;
    int tag;
    int weight;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

void build_graph(pnode *head, int num_of_node);
void add_node(pnode *head, int id);
void add_edge(pnode *head,   int src, int dest, int weight);
void delete_node(pnode *head, int id);
void printGraph(pnode head); //for self debug
void deleteGraph(pnode* head);
void shortsPath(pnode *head, int start, int end);
void TSP(pnode *head, int *list_nodes, int k);

#endif
