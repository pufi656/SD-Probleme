#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct undirected_graph {
    int n;
    node_t **list;
} undirected_graph_t;

undirected_graph_t *init_graph(int n) {
    undirected_graph_t *graph = (undirected_graph_t *) malloc(sizeof(undirected_graph_t));
    graph->n = n;
    graph->list = (node_t **) malloc(n * sizeof(node_t *));
    for (int i = 0; i < n; i++) {
        graph->list[i] = (node_t *) malloc(sizeof(node_t));
        graph->list[i]->n = i;
        graph->list[i]->next = NULL;
    }
    return graph;
}

void add_undirected_edge(undirected_graph_t *graph, int a, int b) {
    node_t *first_new_node = (node_t *) malloc(sizeof(node_t));
    first_new_node->n = b;
    node_t *second_new_node = (node_t *) malloc(sizeof(node_t));
    second_new_node->n = a;
    node_t *looper = graph->list[a];
    while (looper->next != NULL) looper = looper->next;
    looper->next = first_new_node;
    looper = graph->list[b];
    while (looper->next != NULL) looper = looper->next;
    looper->next = second_new_node;
}