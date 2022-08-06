/*
ALL THE PATH FROM SOURCE TO DESTINATION...

Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
*/


 void dfs(vector<vector<int>>& graph,vector<vector<int>> &ans, vector<int>path,int src,int tar)
    {
        path.push_back(src);
        if(src == tar){
            ans.push_back(path);
            return;
        }        
        for(auto it : graph[src])
        {
            dfs(graph,ans,path,it,tar);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) { 
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int>path;  
        dfs(graph,ans,path,0,n-1);
        return ans;
    }
