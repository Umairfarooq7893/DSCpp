#include<iostream>
using namespace std;
int main(){
    int arr[]= {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    // getting target
    int target;
    cout<<"Enter the traget: ";
    cin>> target;

    //Repeatedly dividing the array
    //logic for binary Search
    int low = 0,high = n-1;

    while(low < high){
        int mid = (high + low)/2;
        if(arr[mid] == target){
            cout<<"Element found at index: "<< mid;
            return 0;
        }else if(arr[mid]>target){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
        cout<<"target not found";
}