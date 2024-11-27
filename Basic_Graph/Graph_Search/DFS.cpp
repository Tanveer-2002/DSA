#include<iostream>
#include<vector>
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

void DFS(vector<node*> &G,int root){
    G[root]->visited = true;
    cout<<root<<" -> ";

    for(int x: G[root]->adjList){
        if(!G[x]->visited){
            DFS(G,x);

        }
    }

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
    
    //Follow the diagram:4 & diagram:5 of g_diagram_2.pdf file for better visualization.
    cout<<"DFS from 0:  ";
    DFS(graph,0);
    cout<<"End"<<endl;
    makeAllFalse(graph);

    cout<<"DFS from 3:  ";
    DFS(graph,3);
    cout<<"End"<<endl;
    makeAllFalse(graph);

    cout<<"DFS from 4:  ";
    DFS(graph,4);
    cout<<"End"<<endl;
    makeAllFalse(graph);

}