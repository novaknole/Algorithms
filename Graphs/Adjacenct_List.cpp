#include <iostream>
#include <vector>

using namespace std;

/* Adjacency List */
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[]){
    for(int i=0;i<5;i++){
        cout<<"Friends of node "<<i<<" are: ";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i].at(j)<<" ";
        }
        cout<<" "<<endl;
    }
}

int main(){
    vector<int> V[5];
    addEdge(V,0,1);
    addEdge(V,1,4);
    addEdge(V,1,3);
    addEdge(V,2,3);
    addEdge(V,3,4);
    addEdge(V,4,2);
    printGraph(V);
}