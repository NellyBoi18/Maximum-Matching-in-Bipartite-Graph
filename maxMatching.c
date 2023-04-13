#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 

#define MAX_NODES 1000

int numNodesA, numNodesB, numEdges; // Number of nodes in set A and set B and number of edges
int graph[MAX_NODES][MAX_NODES]; // Matrix to represent bipartite graph
int match[MAX_NODES]; // Array to store matching
bool visited[MAX_NODES]; // Boolean array to keep track of which nodes have been visited during the search

// Bipartite matching algorithm using DFS
bool bpm(int u) {
    // Iterate over all nodes in set B
    for (int v = 0; v < numNodesB; v++) {
        // If there is an edge between node u in set A and node v in set B and node v in set B has not been visited yet
        if (graph[u][v] && !visited[v]) {
            // Mark node v as visited
            visited[v] = true;

            // If node v is not currently matched, or if current matching can be changed to another node using DFS, update matching
            if (match[v] < 0 || bpm(match[v])) {
                match[v] = u;

                // Return true to indicate that a new matching has been found
                return true;
            }
        }
    }

    // Return false to indicate that no new matching was found
    return false;
}

// Compute maximum matching in bipartite graph
int max_matching() {
    int count = 0;

    // Initialize all nodes in set B to be unmatched
    for (int i = 0; i < numNodesB; i++) {
        match[i] = -1;
    }

    // Iterate over all nodes in set A
    for (int u = 0; u < numNodesA; u++) {
        // Reset visited array for each new search
        for (int j = 0; j < numNodesB; j++) {
            visited[j] = false;
        }
        
        // If new matching was found, increment count of matched nodes
        if (bpm(u)) {
            count++;
        }
    }

    // Return total number of matched nodes
    return count;
}

// Check if the maximum matching is perfect (all nodes are matched)
bool is_perfect_matching() {
    return max_matching() == numNodesB;
}

int main() {
    // Read in number of instances
    int numInstances;
    scanf("%d", &numInstances);

    // Arrays to store maximum matching size and perfect matching status
    int *maxMatchSize = malloc(numInstances * sizeof(int));
    int *perfect = malloc(numInstances * sizeof(int));
    // int maxMatchSize[numInstances];
    // int perfect[numInstances];
    int count = 0;

    // Loop over each instance
    while (numInstances--) {
        // Read in number of nodes in set A, set B, and number of edges
        scanf("%d %d %d", &numNodesA, &numNodesB, &numEdges);

        // Initialize graph matrix to all zeros
        for (int i = 0; i < numNodesA; i++) {
            for (int j = 0; j < numNodesB; j++) {
                graph[i][j] = 0;
            }
        }

        // Read in each edge and update graph matrix accordingly
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
        
        // Storing max matching size and perfect matching to output at end
        maxMatchSize[count] = max_match;
        perfect[count] = is_perfect_matching();
        count++;
    }

    // Outputing maximum matching size and perfect matching status for all instances
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
