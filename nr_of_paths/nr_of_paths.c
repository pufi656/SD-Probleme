#include "../utilities/graph.h"

void DFSM(undirected_graph_t *graph, int current_node, int destination, int *visited, int *count) {
    visited[current_node] = 1;
    node_t *looper = graph->list[current_node];
    while (looper != NULL) {
        if (looper->n == destination) (*count)++;
        else if (visited[looper->n] == 0) DFSM(graph, looper->n, destination, visited, count);
        looper = looper->next;
    }
    visited[current_node] = 0;
}

int nr_of_paths(undirected_graph_t *graph, int a, int b) {
    int *visited = (int *) calloc(graph->n, sizeof(int));
    int count = 0;
    DFSM(graph, a, b, visited, &count);
    free(visited);
    return count;
}

int main() {
    undirected_graph_t *graph = init_graph(8);
    add_undirected_edge(graph, 0, 1);
    add_undirected_edge(graph, 0, 3);
    add_undirected_edge(graph, 0, 4);
    add_undirected_edge(graph, 1, 2);
    add_undirected_edge(graph, 2, 3);
    add_undirected_edge(graph, 2, 7);
    add_undirected_edge(graph, 2, 6);
    add_undirected_edge(graph, 3, 4);
    add_undirected_edge(graph, 4, 5);
    add_undirected_edge(graph, 5, 6);
    add_undirected_edge(graph, 6, 7);
    printf("%d\n", nr_of_paths(graph, 7, 3));
    return 0;
}