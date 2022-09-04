#include<array>
#include<iostream>
#include <stdio.h>
using namespace std;

void insertSort(int *arr,int n){
    if(n<=1){
        return;
    }
  
  insertSort(arr,n-1);
  
  
  int last = n-1;
  int j = n-2;
  while(j>=0 && arr[last]<arr[j]){
      swap(arr[j],arr[last]);
      last--;
      j--;
  }

}
int main()
{
  int arr[] = {2,30,20,10,40,15,100};
  int n = end(arr)-begin(arr);
  insertSort(arr,n);
  for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
  }
}
