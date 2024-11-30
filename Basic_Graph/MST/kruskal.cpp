#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[100];
void make_set(int n){
    parent[n] = n;
}
int find_set(int n){
    if(parent[n] == n)
        return n;
    return parent[n] = find_set(parent[n]);
}
void union_set(int u, int v){
    int up = find_set(u);
    int vp = find_set(v);
    if(up == vp)
        return;
    parent[vp] = parent[up];  
}

struct edge{
    int src,des,w;
};

void printEdges(vector<edge> &v){
    for(auto x: v){
        cout<<x.src<<" -> "<<x.des<<" Cost: "<<x.w<<endl;
    }
}

bool comp(edge a, edge b){
    return a.w<b.w;
}


int main(){

    int n;
    cin>>n;
    vector<edge>edges(n);

    for(int i=0; i<n; i++){
        int s,d,we;
        cin>>s>>d>>we;
        edges[i].src = s;
        edges[i].des = d;
        edges[i].w = we;  
        make_set(s);
        make_set(d);  
    }
    cout<<"Before Sort: "<<endl;
    printEdges(edges);
    cout<<"-----------------------------------------------------------"<<endl;
    sort(edges.begin(),edges.end(),comp);
    cout<<"After Sort: "<<endl;
    printEdges(edges);

    vector<edge>mst;
    for(int i=0; i<n; i++){
        int pu = find_set(edges[i].src);
        int pv = find_set(edges[i].des);
        if(pu == pv)
            continue;
        mst.push_back(edges[i]); 
        union_set(edges[i].src,edges[i].des);
    }
    cout<<"------------------------------------------------------------"<<endl;
    printEdges(mst);

 }