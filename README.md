# Maximum Matching in Bipartite Graph
Implements an algorithm in C to determine the maximum matching in a bipartite graph and if that matching is perfect (all nodes are matched). 

# Input
Read from standard input, the input will start with a positive integer, giving the number of instances that follow. For each instance, there will be 3 positive intergers m, n, q. Numbers m and n are the number of nodes in node set A and node set B. Numer q is the number of edges in the bipartite graph. For each edge, there will be 2 more positive integers i, and j representing an edge between node $1 \le i \le m$ in A and node $1 \le i \le n$ in B

# Output
For each instance, the program outputs the size of the maximum matching, followed by a spance, followed by an N if the matching is not perfect and a Y if the matching is perfect. Each output line is terminated by a newline. 

# Sample
**Input:**\
3\
2 2 4\
1 1\
1 2\
2 1\
2 2\
2 3 4\
2 3\
2 1\
1 2\
2 2\
5 5 10\
1 1\
1 3\
2 1\
2 2\
2 3\
2 4\
3 4\
4 4\
5 4\
5 5

**Output:**\
2 Y
2 N
4 N

The sample input has 3 instances.