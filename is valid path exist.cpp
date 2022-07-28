/*
 Check if path exist
 
Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 ? 1 ? 2
- 0 ? 2
*/
 bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         vector<int> adj[n];
        queue<int>q;
        vector<bool>vis(n+1,false);
        if(n==1)
            return true;
        for(int i=0;i<edges.size();i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vis[source]=true;
        q.push(source);
        while(!q.empty())
        {
            int nodes = q.front();
            q.pop();
            for(auto it: adj[nodes])
            {
                if(!vis[it])
                {
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
        if(vis[destination]==true)
            return true;
        else
            return false;
    }
