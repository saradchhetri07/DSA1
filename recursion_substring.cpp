//https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=0
void solve(string str,vector<string>& ans,int index,string output){
    if(index==str.size()){
        if(output!=""){
            ans.push_back(output);
        }
         return;
    }
    //exclude
    solve(str,ans,index+1,output);
    
    //include
    char element = str[index];
    output.push_back(element);
    solve(str,ans,index+1,output);
    
}
vector<string> subsequences(string str){
	// Write your code here
    vector<string> ans;
    int index=0;
    string output;
    solve(str,ans,index,output);
    return ans;
	
}
