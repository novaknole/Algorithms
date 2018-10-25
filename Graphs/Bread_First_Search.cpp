/* Bread First Search
The idea is to traverse(travel the whole graph and print the indexes or values of the graph).
but the bad thing could happen, because if we move from node 2 to 1, node1 might have the way back to node 2.
which is bad, because it will be inifinite traversal. What we do is use the queue and boolean array which stores 
the visited nodes*/

/* Time Complexity =  O(V+E);


/* directed graph */


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Graph{
    public:
        int Verticies;
        vector<int> *adj;
        Graph(int Verticies);
        void addEdge(int u, int v);
        void Traverse(int startPoint);
};

Graph::Graph(int Verticies){
    this->Verticies = Verticies;
    this->adj = new vector<int>[Verticies];
}

void Graph::addEdge(int u,int v){
    this->adj[u].push_back(v);
}

void Graph::Traverse(int start){
    bool *visited = new bool[this->Verticies];
    for(int i=0;i<this->Verticies;i++)
        visited[i] = false;


    visited[start] = true;
    queue<int> queue;
    queue.push(start);

    while(!queue.empty()){
        int vertex = queue.front();
        cout<<vertex<<"  ";
        queue.pop();

        vector<int> nodeNeighbors = this->adj[vertex];
        for(int i=0;i<nodeNeighbors.size();i++){
            int neighbor = nodeNeighbors.at(i);
            if(!visited[neighbor]){
                visited[neighbor]=true;
                queue.push(neighbor);
            }
        }
    }
}
int main(){
    Graph graph(4);
    graph.addEdge(0, 1); 
    graph.addEdge(0, 2); 
    graph.addEdge(1, 2); 
    graph.addEdge(2, 0); 
    graph.addEdge(2, 3); 
    graph.addEdge(3, 3);
    graph.Traverse(0);
}