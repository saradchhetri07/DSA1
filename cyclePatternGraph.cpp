#include<unordered_map>
#include<list>
#include<queue>
// bool isCycle(unordered_map<int,list<int>> adj,int src){
//     unordered_map<int,bool> visited;
//     unordered_map<int,int> parent;
//     queue<int> q;
//     parent[src]=-1;
//     visited[src]=true;

//     q.push(src);

//     while(!q.empty()){
//         int front = q.front();
//         q.pop();

//         for(auto i:adj[front]){
//             if(visited[i] && i!=parent[front]){
//                 return true;
//             }else if(!visited[i]){
//                 q.push(i);
//                 visited[i]=true;
//                 parent[i]= front;
                
//             }
//         }
//     }
//     return false;

    
// }
bool dfs(unordered_map<int,list<int>> &adj,int node,int parent){
    
    unordered_map<int,bool> visited;

    visited[node]=true;


    for(auto i:adj[node]){
        if(visited[i] && i!=parent){
            return true;
        }else if(!visited[i]){
            dfs(adj,i,node);
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    
    unordered_map<int,list<int>> adj;

    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<n;i++){
        bool ans = dfs(adj,i,-1);
        if(ans==true){
            return "Yes";
        }
    }
    return "No";
    // for(int i=0;i<n;i++){
    //     bool ans = isCycle(adj,i);
    //     if(ans==1){
    //         return "Yes";
    //     }
    // }
    // return "No";
}
