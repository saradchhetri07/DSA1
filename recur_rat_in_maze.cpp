//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution{
    private:
    bool legitPath(vector<vector<int>> visited,int x,int y,vector<vector<int>> &m,int n){
        if((x >= 0 && x<n) && (y >=0 && y<n) &&  visited[x][y] !=1 && m[x][y] == 1){
            return true;
        }else{
            return false;
        }
        
    }
    
    void findPath(vector<vector<int>> &m,int srcx,int srcy,vector<string>& ans,string path,vector<vector<int>> visited,int n){
        //base condition
        if(srcx==n-1 && srcy==n-1){
            ans.push_back(path);
            return;
        }
        visited[srcx][srcy] = 1;
        
        //check if there is down path
            int newx = srcx+1;
            int newy = srcy;
        if(legitPath(visited, newx, newy,m,n)){
           
            path.push_back('D');
            findPath(m,newx,newy,ans,path,visited,n);
            path.pop_back();
        }
        //check if there is right path
         newx = srcx;
         newy = srcy+1;
        if(legitPath(visited, newx, newy,m,n)){
            path.push_back('R');
            findPath(m,newx,newy,ans,path,visited,n);
            path.pop_back();
        }
         //check if there is left path
         newx = srcx;
         newy = srcy-1;
        if(legitPath(visited, newx, newy,m,n)){
            path.push_back('L');
            findPath(m,newx,newy,ans,path,visited,n);
            path.pop_back();
        }
       
         //check if there is upward path
         newx = srcx-1;
         newy = srcy;
        if(legitPath(visited, newx, newy,m,n)){
            path.push_back('U');
            findPath(m,newx,newy,ans,path,visited,n);
            path.pop_back();
        }
        
        
        
        
        
        visited[srcx][srcy] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
      vector<string> ans;
      string path = "";
      if(m[0][0]==0){
          return ans;
      }
      vector<vector<int>> visited=m;
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              visited[i][j] = 0;
          }
      }
      int srcx=0;
      int srcy=0;
      
      findPath(m,srcx,srcy,ans,path,visited,n);
      sort(ans.begin(),ans.end());
        
    }
};
