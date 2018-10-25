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

[Depth First Search O(V+E)](https://github.com/novaknole/Algorithms/blob/master/Graphs/Depth_First_Search.cpp)

[Graph BFS vs DFS](https://github.com/novaknole/Algorithms/blob/master/Graphs/Images/Bfs_Dfs.jpg)

[Pick's Theorem(Polygon Area)](https://github.com/novaknole/Algorithms/blob/master/Graphs/Picks_Thereom.cpp)

[Shoolace's Theorem(Polygon Area)](https://github.com/novaknole/Algorithms/blob/master/Graphs/Shoolace_Area.cpp)

[Bellman-Ford Theorem O(VE)](https://github.com/novaknole/Algorithms/blob/master/Graphs/Bellman_Ford.cpp)
--------------
Dijksra’s algorithm is a Greedy algorithm and time complexity is O(VLogV) (with the use of Fibonacci heap). Dijkstra doesn’t work for Graphs with negative weight edges, Bellman-Ford works for such graphs. Bellman-Ford is also simpler than Dijkstra and suites well for distributed systems. But time complexity of Bellman-Ford is O(VE), which is more than Dijkstra.(https://www.youtube.com/watch?v=iTW2yFYd1Nc&t=563s&fbclid=IwAR1-MhQbpeFOH32QA5kp5sltfSrq1FMFrEPAEKXoiH5cGmY827oXCrTHY8c)