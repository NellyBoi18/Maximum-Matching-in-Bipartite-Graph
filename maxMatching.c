#include <stdio.h>
#include <stdbool.h>
#include <string.h> 

#define MAX_NODES 1000

int n, m, q;
int graph[MAX_NODES][MAX_NODES];
int match[MAX_NODES];
bool visited[MAX_NODES];

bool bpm(int u) {
    for (int v = 0; v < n; v++) {
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
    for (int i = 0; i < n; i++) {
        match[i] = -1;
    }
    for (int u = 0; u < m; u++) {
        for (int j = 0; j < n; j++) {
            visited[j] = false;
        }
        if (bpm(u)) {
            count++;
        }
    }
    return count;
}

bool is_perfect_matching() {
    return max_matching() == n;
}

int main() {
    int t;
    scanf("%d", &t);

    int maxMatchSize[t];
    int perfect[t];
    char match[3][3] = {"N", "Y"};
    int count = 0;
    char output[t * 5];

    while (t--) {
        scanf("%d %d %d", &m, &n, &q);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = 0;
            }
        }

        while (q--) {
            int i, j;
            scanf("%d %d", &i, &j);
            i--;
            j--;
            graph[i][j] = 1;
        }

        int max_match = max_matching();
        int is_perfect = (max_match == m);

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
        //printf("%d %s\n", maxMatchSize[i][0], match[results[i][1]]);
        printf("%d ", maxMatchSize[i]);
        if (perfect[i]) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}
