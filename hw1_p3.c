#include <stdio.h>
#include <stdbool.h>

#define MAX 100 

int queue[MAX];
int front = 0, rear = 0;

void enqueue(int vertex) {
    queue[rear++] = vertex;
}

int dequeue() {
    return queue[front++];
}

bool isEmpty() {
    return front == rear;
}

void bfs(int m, int adjMatrix[m][m]) {
    bool visited[m];
    for (int i = 0; i < m; i++) {
        visited[i] = false;  
    }

    enqueue(0);  
    visited[0] = true;

    while (!isEmpty()) {
        int vertex = dequeue();
        printf("%d ", vertex + 1);  
        
        for (int neighbor = 0; neighbor < m; neighbor++) {
            if (adjMatrix[vertex][neighbor] == 1 && !visited[neighbor]) {
                enqueue(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    printf("\n");
}

int main() {
    int m;
    
    scanf("%d", &m);

    int adjMatrix[m][m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    bfs(m, adjMatrix);

    return 0;
}
