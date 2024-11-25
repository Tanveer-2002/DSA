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
    for(int i=0; i<(10-1); i++){
        int minIndex = i;
        
        for(int j=i+1; j<10; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    //Printing Sorted 
    cout<<"Sorted: ";
    for(int x: arr){
        cout<<x<<",";
    }
    cout<<endl;
}