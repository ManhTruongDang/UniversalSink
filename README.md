# UniversalSink
Code to find the universal sink of a graph

"Show how to determine whether a directed graph G contains a universal link - 
a vertex with in-degree (V-1) (V is the number of vertices) and out-degree 0 in time O(V), given an adjacency matrix for G"

Here in this program a vertex i is an universal sink if a[i][j] == 0 for all j's and a[m][i] == 1 for all m's such that m != i. 
a[i][j] == 1 if there is an edge going from vertex i to vertex j. 

An example input file is provided along with the code.

Reference: 

[1] https://stackoverflow.com/questions/29259365/how-to-find-the-universal-sink-of-a-directed-graph-with-an-adjacency-matrix-repr

[2] Introduction to algorithm - Cormen et al.
