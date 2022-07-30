/*
Redundant connection 
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
*/

int find(vector<int>&par,int i)
    {
        if(par[i]==-1)
            return i;
        return par[i]=find(par,par[i]);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
     vector<int>par(edges.size()+1,-1);
        vector<int>v;
        for(auto it : edges)
        {
            int x= it[0];
            int y= it[1];
            int p= find(par,x);
            int q= find(par, y);
             
            if(p==q)
                return it;
            par[p]=q;
        }
        return v;
    }
