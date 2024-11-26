#include<iostream>
#include<vector>
using namespace std;

void printAdjMat(int v[][5]){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
void addEdge(int v[][5],int src,int des){
    v[src][des]=1;
    v[des][src]=1;
}

void printEdges(int v[][5]){
    int nNum = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(v[i][j] == 1 && i<j){
                nNum++;
                cout<<"Edge "<<nNum<<": "<<i<<" <--> "<<j<<endl; 
            }
        }
    }
}

int main(){

    //Declaring 2d arry for adj matrix
    int adjMat[5][5] ={0};

    addEdge(adjMat,0,3);
    addEdge(adjMat,0,4);
    addEdge(adjMat,1,2);
    addEdge(adjMat,1,4);
    addEdge(adjMat,2,4);
    cout<<"Adjacency Matrix:"<<endl;
    printAdjMat(adjMat);
    printEdges(adjMat);
    

}