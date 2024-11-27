#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node{
    vector<int>adjList;
    bool visited = false;
};

void addNode(vector<node*> &G){                 
    G.push_back(new node());
}

void addEdge(vector<node*> &G,int src ,int des){
    G[src]->adjList.push_back(des);
    G[des]->adjList.push_back(src);
}

void makeAllFalse(vector<node*> &G){
    for(node *x: G){
        x->visited = false;
    }
}

void BFS(vector<node*> &G, int root){
    queue<int> Q;
    Q.push(root);
    G[root]->visited = true;

    while(!Q.empty()){
        for(int x: G[Q.front()]->adjList){
            if(!G[x]->visited){
                Q.push(x);
                G[x]->visited = true;
            }
        }

        cout<<Q.front()<<" -> ";
        Q.pop();
    }
    cout<<"End"<<endl;

    makeAllFalse(G);            //For multiple search

}

int main(){

    vector<node*> graph;

    for(int i=0; i<=5; i++)                      
        addNode(graph);
    
    addEdge(graph,0,3);                       
    addEdge(graph,0,4);
    addEdge(graph,1,3);
    addEdge(graph,2,3);
    addEdge(graph,2,5);
    addEdge(graph,4,5);
    
    //Follow the diagram:2 & diagram:3 of g_diagram_2.pdf file for better visualization.
    cout<<"BFS from 0:  ";
    BFS(graph,0);

    cout<<"BFS from 3:  ";
    BFS(graph,3);

    cout<<"BFS from 4:  ";
    BFS(graph,4);

}