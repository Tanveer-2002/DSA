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
        for(int j=0; j<(10-1); j++ ){
            
            if(arr[j]> arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    //Printing Unsorted 
    cout<<"Sorted: ";
    for(int x: arr){
        cout<<x<<",";
    }
    cout<<endl;

}