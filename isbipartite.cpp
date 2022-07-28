/*
ISBIPATITE
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.

*/
bool checkbipartite(int node, vector<int>& vis, vector<vector<int>> &graph){
    queue<int> q;
    q.push(node);
    vis[node]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it: graph[node])
        {
            if(vis[it]==-1){
                q.push(it);
                vis[it] = 1-vis[node];
            }
            else if(vis[it]==vis[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> vis(n+1,-1);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==-1)
        {
            if(!checkbipartite(i,vis,graph))
            {
                return false;
            }
        }
    }
    return true;
}
