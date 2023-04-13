#include <stdio.h>
#include <stdbool.h>
#include <string.h> 

#define MAX_NODES 1000

int numNodesA, numNodesB, numEdges;
int graph[MAX_NODES][MAX_NODES];
int match[MAX_NODES];
bool visited[MAX_NODES];

bool bpm(int u) {
    for (int v = 0; v < numNodesB; v++) {
        if (graph[u][v] && !visited[v]) {
            visited[v] = true;
            if (match[v] < 0 || bpm(match[v])) {
                match[v] = u;

                return true;
            }
        }
    }

    return false;
}

int max_matching() {
    int count = 0;

    for (int i = 0; i < numNodesB; i++) {
        match[i] = -1;
    }

    for (int u = 0; u < numNodesA; u++) {
        for (int j = 0; j < numNodesB; j++) {
            visited[j] = false;
        }
        
        if (bpm(u)) {
            count++;
        }
    }

    return count;
}

bool is_perfect_matching() {
    return max_matching() == numNodesB;
}

int main() {
    int numInstances;
    scanf("%d", &numInstances);

    int maxMatchSize[numInstances];
    int perfect[numInstances];
    int count = 0;

    while (numInstances--) {
        scanf("%d %d %d", &numNodesA, &numNodesB, &numEdges);

        for (int i = 0; i < numNodesA; i++) {
            for (int j = 0; j < numNodesB; j++) {
                graph[i][j] = 0;
            }
        }

        while (numEdges--) {
            int i, j;

            scanf("%d %d", &i, &j);
            i--;
            j--;

            graph[i][j] = 1;
        }

        int max_match = max_matching();

        /* // Individual instance outputs
        printf("%d ", max_match);
        if (is_perfect_matching()) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
        */
        
        maxMatchSize[count] = max_match;
        perfect[count] = is_perfect_matching();
        count++;
    }

    for (int i = 0; i < count; i++) {
        printf("%d ", maxMatchSize[i]);
        if (perfect[i]) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}
