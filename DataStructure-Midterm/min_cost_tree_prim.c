#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define V 5

// Find the vertex with minimum key value not yet included in MST
int minKey(int key[], int inMST[]) {
    int min = INF, minIndex;
    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Print the MST edges in descending order of weights
void printMST(int parent[], int graph[V][V]) {
    int edges[V - 1][3];
    int edgeCount = 0;

    for (int i = 1; i < V; i++) {
        edges[edgeCount][0] = parent[i];
        edges[edgeCount][1] = i;
        edges[edgeCount][2] = graph[i][parent[i]];
        edgeCount++;
    }

    // Sort edges by weight in descending order
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j][2] < edges[j + 1][2]) {
                int temp[3];
                temp[0] = edges[j][0];
                temp[1] = edges[j][1];
                temp[2] = edges[j][2];
                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][0] = temp[0];
                edges[j + 1][1] = temp[1];
                edges[j + 1][2] = temp[2];
            }
        }
    }

    printf("Edges in the Minimum Spanning Tree (from highest to lowest weight):\n");
    for (int i = 0; i < edgeCount; i++) {
        printf("(%d -- %d) weight: %d\n", edges[i][0], edges[i][1], edges[i][2]);
    }
}

// Prim's algorithm for Minimum Spanning Tree
void primMST(int graph[V][V]) {
    int parent[V], key[V], inMST[V];

    // Initialize all keys as INFINITE and inMST as false
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        inMST[i] = 0;
    }

    // Start with the first vertex
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, inMST);
        inMST[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);
    return 0;
}
