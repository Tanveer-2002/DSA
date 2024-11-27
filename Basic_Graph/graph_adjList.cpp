#include<iostream>
#include<vector>
using namespace std;

struct node{
    vector<int>adjList;                              //This vector will list the adjacent nodes of a particular node
};

void addNode(vector<node*> &G){                 
    G.push_back(new node());                         //It just adds a node on the graph
}
void addEdge(vector<node*> &G,int src ,int des){
    G[src]->adjList.push_back(des);                 //Adds the adjacent node index on the src nodes adjList 
    G[des]->adjList.push_back(src);                 //This is for undirected graph
}

int main(){

    vector<node*> graph;                            //Declaring a vector of node(struct) to contain all the vertices of the graph

    for(int i=0; i<5; i++)                      
        addNode(graph);
    
    addEdge(graph,0,3);                       
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,4);
    addEdge(graph,2,4);
    
    //Follow the diagram on g_diagram_1.pdf for better visualization
    for(int i=0; i<graph.size(); i++){
        cout<<i<<": ";
        for(int y: graph[i]->adjList){
            cout<<y<<",";
        }
        cout<<endl;
    }
    

}