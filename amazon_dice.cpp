#include<iostream>
#include<string>
#include<vector>
using namespace std;
void calculate(string &output,int target){
    //base condition
   // cout<<target<<endl;
    if(target==0){
        cout<<output<<endl;
        return;
    }
    for(int i=1;i<=6 && i<=target;i++){
        string ch = to_string(i);
     output = output + ch;
    //  cout<<output<<endl;
    //  cout<<target<<endl;
     calculate(output,target-i);
    output.pop_back();
    }
    
    
}
int main(){
  
  string output="";
  int target = 4;
  calculate(output,target);
     
}
