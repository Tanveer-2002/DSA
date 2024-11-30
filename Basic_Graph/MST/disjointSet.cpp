#include<iostream>
using namespace std;
 
 int parent[100];
 void make_set(int v){
    parent[v] = v;
 }
 int find_set(int n){
    if(parent[n] == n)
        return n;
    return parent[n] = find_set(parent[n]);
    
 }
 void union_set(int u, int v){
    int pu = find_set(u);
    int pv = find_set(v);
    if(pu == pv)
        return;

    parent[pv] = parent[pu];

 }
 int main(){

 }