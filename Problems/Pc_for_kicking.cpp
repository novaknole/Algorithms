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
#include <string.h>
using namespace std;


class Graph{
    public:
        int Verticies;
        vector<int> *adj;
        Graph(int Verticies);
        void addEdge(int u, int v);
        void Traverse(int startPoint,int match[]);
};

Graph::Graph(int Verticies){
    this->Verticies = Verticies;
    this->adj = new vector<int>[Verticies];
}

void Graph::addEdge(int u,int v){
    this->adj[u].push_back(v);
    this->adj[v].push_back(u);
}

void Graph::Traverse(int start, int match[]){
    bool *visited = new bool[this->Verticies];
    for(int i=0;i<this->Verticies;i++)
        visited[i] = false;


    visited[start] = true;
    queue<int> queue;
    queue.push(start);

    while(!queue.empty()){
        int vertex = queue.front();
       // cout<<vertex<<"  ";
        queue.pop();

        vector<int> nodeNeighbors = this->adj[vertex];
        for(int i=0;i<nodeNeighbors.size();i++){
            int neighbor = nodeNeighbors.at(i);
          
            if(!visited[neighbor]){
               
                if(match[neighbor] == -1) match[neighbor] = 1;

                else match[neighbor]=match[vertex]+1;
                
                visited[neighbor]=true;
                queue.push(neighbor);
            }
        }
    }
}

int main(){
    int N;
    int a; //otvios pc;
    cin>>N; cin>>a;
    Graph gr(N);
    for(int i=0;i<N-1;i++){
        int u; int v;
        cin>>u; cin>>v;
        u--; v--;
        gr.addEdge(u,v);
    }
    a--;
    int match[N];
    memset(match, 0, sizeof(match));
    gr.Traverse(a, match);
    int max = match[0];
    for(int i=1;i<N;i++){
        if(match[i]>max) max = match[i];
    }
    cout<<max+1<<endl;
    //cout<<maximum<<endl;
    //cout<<gr.traverse(a-1)<<endl;
}

// 5 2
// 1 2
// 1 3
// 2 5
// 3 4