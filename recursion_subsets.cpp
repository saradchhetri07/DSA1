//https://leetcode.com/problems/subsets/
void solve(vector<int> nums,int index,vector<vector<int>>& ans,vector<int> output){
    if(index==nums.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    solve(nums,index+1,ans,output);
 
    int element = nums[index];
    output.push_back(element);
    solve(nums,index+1,ans,output);
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        solve(nums,index,ans,output);
        return ans;
        
    }
};
