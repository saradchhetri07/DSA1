//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
private:
    void solve(vector<string>& ans,string output,int index,string digits,vector<string> mapping){
        if(index==digits.length()){
            ans.push_back(output);
            return;
        }
        int digitval = digits[index] - '0';
        string val= mapping[digitval];
        for(int i=0;i<val.length();i++){
            output.push_back(val[i]);
            solve(ans,output,index+1,digits,mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output="";
        if(digits.length()==0){
            return ans;
        }
        int index=0;
        vector<string> mapping{"","","abc","def","ghi","jkl","mno","qprs","tuv","wxyz"};
        solve(ans,output,index,digits,mapping);
        return ans;
    }
};
