#include <iostream>
#include <vector>
using namespace std;
vector<int> bubbleSort(vector<int> arr,int n){

 //bubble sort using recursion
 //base condition
 if(n==0||n==1){
     return arr;
 }
 for(int i=0;i<n-1;i++){
     if(arr[i+1]<arr[i]){
         cout<<"stuck"<<endl;
         swap(arr[i],arr[i+1]);
     }
     
 }
  
 return bubbleSort(arr,n-1);
 
   
}

int main(){ 
vector<int> array {30,20,50,60,10,100,20};

int n = array.size();
//cout<<array.size();
vector<int> newarr = bubbleSort(array,n);
for(int i=0;i<n;i++){
    cout<<newarr[i]<<" ";
}
}
