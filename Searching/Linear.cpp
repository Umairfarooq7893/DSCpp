#include<iostream>
using namespace std;
int main(){
    // declaring an Array
    int arr[10];
    //Getting input from user
    cout<<"Enter the 10 elements: "<<endl;
    for(int i = 0;i<10;i++){
        cin>>arr[i];
    }
    //Getting the target element
    int target;
    cout<<"Enter the Element to found";
    cin>>target;

    // logic for linear Search
    for(int i=0; i<10;i++){
        if (arr[i] == target){
            cout<<"Element "<<target<<"found at index "<<i;
            return 0;
        }
    }
        cout<<"element not found: ";
    return 0;
}