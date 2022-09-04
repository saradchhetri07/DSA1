#include<array>
#include<iostream>
#include <stdio.h>
using namespace std;
void selectSort(int *arr,int length){
    if(length==1 || length == 0){
      return;
    }
    int min = *(arr);
    int minIndex=0;
    
    for(int i=0;i<length;i++){
      
        if(arr[i]<min){
            min = arr[i];
            minIndex = i;
          
            
        }
    }
    
    swap(*(arr),arr[minIndex]);
    return selectSort(arr+1,length-1);
    
    
}
int main()
{
  int arr[] = {30,20,10,40,5,100,2};
  int length = end(arr)-begin(arr);
  selectSort(arr,length);
  for(int i=0;i<length;i++){
      cout<<arr[i]<<" ";
  }
}
