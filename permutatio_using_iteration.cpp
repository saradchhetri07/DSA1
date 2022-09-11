#include<iostream>
#include<string>
#include<vector>
using namespace std;
void calSubsets(vector<int> arr,vector<vector<int>> &outer){
    vector<int> internal;
    outer.push_back(internal);
   
    for(int i=0;i<arr.size();i++){
        int n = outer.size();
        for(int j=0;j<n;j++){
            vector<vector<int>> in;
            in = outer;
            in[j].push_back(arr[i]);
           
            outer.push_back(in[j]);
            
        }
    }
    for(int i=0;i<outer.size();i++){
        for(int j=0;j<outer[i].size();j++){
            cout<<outer[i][j]<<" ";
        }cout<<endl;
    }
 
   
  
}
int main(){
  vector<int> arr {1,2,3};
vector<vector<int>> outer;
calSubsets(arr,outer);
  
}
