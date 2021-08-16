int N=100005,logg=20;
vector<vector<int>> adj(N),lca(N,vector<int>(logg+1));
vector<int> level(N);
// Initialize level[] = 0 , lca[][] = -1 

void dfs(int n,int par)
{
    lca[n][0]=par;
    for(int i=1;i<=logg;i++)
        lca[n][i]=lca[lca[n][i-1]][i-1];
        
    for(auto it:adj[n])
    {
        if(it!=par)
        {
            level[it]=level[n]+1;
            dfs(it,n);
        }
    }
}

int LCA(int u,int v)
{
    if(level[u]>level[v]) swap(u,v);
    
    for(int i=logg;i>=0;i--)
    {
        if(lca[v][i]!=-1&&level[lca[v][i]]>=level[u])
            v=lca[v][i];
    }
    
    if(u==v)
        return u;
    
    for(int i=logg;i>=0;i--)
    {
        if(lca[u][i]!=lca[v][i])
        {
            u=lca[u][i];
            v=lca[v][i];
        }
    }
    
    return lca[v][0];
}
