# Different Kinds of algorithms including their explanations and time complexities.

# Sorts

[Insertion Sort O(n*n)](https://github.com/novaknole/Algorithms/blob/master/Sorts/insertion_sort.cpp)

[Bubble Sort  O(n*n)](https://github.com/novaknole/Algorithms/blob/master/Sorts/Bubble_Sort.cpp)

[Merge Sort O(nLogn).](https://github.com/novaknole/Algorithms/blob/master/Sorts/Merge_Sort.cpp)

## Trees
[AVL Tree Code O(logn)=(Search,Insert,Delete)](https://github.com/novaknole/Algorithms/blob/master/Trees/avl_tree.cpp)

[AVL Tree Image](https://github.com/novaknole/Algorithms/blob/master/Trees/Images/avl_tree.jpg)


[Binary Tree Code O(logn) or O(n)](https://github.com/novaknole/Algorithms/blob/master/Trees/binary_tree.cpp)

[Fenwick Tree Code O(logn)](https://github.com/novaknole/Algorithms/blob/master/Trees/fenwick_tree.cpp)

[Fenwick Tree Image](https://github.com/novaknole/Algorithms/blob/master/Trees/Images/fenwick_tree.jpg)



## Graphs
[Graph Image 1](https://github.com/novaknole/Algorithms/blob/master/Graphs/Images/Graph_1.jpg)

[Graph Image 2](https://github.com/novaknole/Algorithms/blob/master/Graphs/Images/Graph_2.jpg)

[Graph Image 3](https://github.com/novaknole/Algorithms/blob/master/Graphs/Images/Graph_3.jpg)

[Adjacency_List](https://github.com/novaknole/Algorithms/blob/master/Graphs/Adjacenct_List.cpp)

[Breadth First Search O(V+E)](https://github.com/novaknole/Algorithms/blob/master/Graphs/Bread_First_Search.cpp)

Note that the above code traverses only the vertices reachable from a given source vertex. All the vertices may not be reachable from a given vertex (example Disconnected graph). To print all the vertices, we can modify the BFS function to do traversal starting from all nodes one by one (Like the DFS modified version) [Modified Version](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/)


[Depth First Search O(V+E)](https://github.com/novaknole/Algorithms/blob/master/Graphs/Depth_First_Search.cpp)

[Graph BFS vs DFS](https://github.com/novaknole/Algorithms/blob/master/Graphs/Images/Bfs_Dfs.jpg)

[Pick's Theorem(Polygon Area)](https://github.com/novaknole/Algorithms/blob/master/Graphs/Picks_Thereom.cpp)

[Shoolace's Theorem(Polygon Area)](https://github.com/novaknole/Algorithms/blob/master/Graphs/Shoolace_Area.cpp)

--------------

[Bellman-Ford Theorem O(VE)](https://github.com/novaknole/Algorithms/blob/master/Graphs/Bellman_Ford.cpp)

Bellman-Ford Algorith finds the shortert paths from the specified vertex to all other vertexes. Dijksra’s algorithm is a Greedy algorithm and time complexity is O(VLogV) (with the use of Fibonacci heap). Dijkstra doesn’t work for Graphs with negative weight edges, Bellman-Ford works for such graphs. Bellman-Ford is also simpler than Dijkstra and suites well for distributed systems. But time complexity of Bellman-Ford is O(VE), which is more than Dijkstra.
The standard Bellman-Ford algorithm reports shortest path only if there is no negative weight cycles,But we can modify it to make it work. 
- If we have a directed graph and we have negative edges, but not negative cycles, this algorithm will work
flawlessly. If we have negative cycles,it can idenfity cycles but can't work flawlessly.
- If we have an undirected graph and positive edges, this algorithm will work flawlessly. If we have negative edges, it won't work because any edge in undirected graph is also a loop and if it has a negative edge, we have a negative cycle.

(https://www.youtube.com/watch?v=iTW2yFYd1Nc&t=563s&fbclid=IwAR1-MhQbpeFOH32QA5kp5sltfSrq1FMFrEPAEKXoiH5cGmY827oXCrTHY8c)

---------------

[Djikstra O(V^2) or O(VLogV)](https://github.com/novaknole/Algorithms/blob/master/Graphs/Djikstra.cpp)

Djikstra Algorithm is the same idea as Bellman-Ford but doesn't work with negative weights. If we use
the implementation like the above link, Time complexity is O(V^2) but if we use binary heap and
adjacency list, then it could be reduced to O(VLogV);
- The code calculates shortest distance, but doesn’t calculate the path information. We can create a parent array, update the parent array when distance is updated (like prim’s implementation) and use it show the shortest path from source to different vertices.
- The code is for undirected graph, same dijkstra function can be used for directed graphs also.
- The code finds shortest distances from source to all vertices. If we are interested only in shortest distance from the source to a single target, we can break the for the loop when the picked minimum distance vertex is equal to target (Step 3.a of the algorithm).
- Time Complexity of the implementation is O(V^2). If the input graph is represented using adjacency list, it can be reduced to O(E log V) with the help of binary heap. Please see
Dijkstra’s Algorithm for Adjacency List Representation for more details.
- Dijkstra’s algorithm doesn’t work for graphs with negative weight edges. For graphs with negative weight edges, Bellman–Ford algorithm can be used, we will soon be discussing it as a separate post.

---------------

[Ford-Fulkerson O(max_flow * E)](https://github.com/novaknole/Algorithms/blob/master/Graphs/Ford_Fulkerson.cpp)

Imagine we have cities. cities are connected to each other by roads. Each road has some capacity which means that
from source city to destination city we can send as many trucks as the capacity for this road. We're given two cities.
We need to find the maximum possible trucks that can go from source city to destination city(from source to sink).
[Youtube Link](https://www.youtube.com/watch?v=GoVjOT30xwo&t=871s) [Words that we need to know while understanding this algorithm](https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/)


---------------

[Bipartite Graph](https://github.com/novaknole/Algorithms/blob/master/Graphs/Bipartite_Graph.cpp)
A matching in a Bipartite Graph is a set of the edges chosen in such a way that no two edges share an endpoint. A maximum matching is a matching of maximum size (maximum number of edges). In a maximum matching, if any edge is added to it, it is no longer a matching. There can be more than one maximum matchings for a given Bipartite Graph.
Why do we care?
There are many real world problems that can be formed as Bipartite Matching. For example, consider the following problem:
There are M job applicants and N jobs. Each applicant has a subset of jobs that he/she is interested in. Each job opening can only accept one applicant and a job applicant can be appointed for only one job. Find an assignment of jobs to applicants in such that as many applicants as possible get jobs.
The code above does find how many people can be assigned to jobs, if each people could be interested in many jobs,but
in final only one person go to one job. We need to find the maximum matching which is the same as maximum flow which is the same as maximum number of people that we can assign to jobs.

[Link 1](https://study.com/academy/lesson/bipartite-graph-definition-applications-examples.html)
[Link 2](https://www.geeksforgeeks.org/maximum-bipartite-matching/)
[Link 3](https://www.youtube.com/watch?v=8YUIdXOKNpM)

## Interesting Problems

[Uberwatch Problem I Solution(t) = max(oponents(t)+solution(t-m), solution(t-1))](https://github.com/novaknole/Algorithms/blob/master/20172018-acmicpc-german-collegiate-programming-contest-gcpc-2017-en.pdf)