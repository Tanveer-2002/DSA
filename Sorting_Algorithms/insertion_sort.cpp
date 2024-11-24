#include<iostream>
using namespace std;

int main(){
    //Initializing array
    int arr[10] = {75,6,3,4,0,22,4,5,2,29};

    //Printing Unsorted 
    cout<<"Unsorted: ";
    for(int x: arr){
        cout<<x<<",";
    }
    cout<<endl;

    //Sorting array
    for(int i=1; i<10; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = key;
    }

    //Printing Unsorted 
    cout<<"Sorted: ";
    for(int x: arr){
        cout<<x<<",";
    }
    cout<<endl;
}