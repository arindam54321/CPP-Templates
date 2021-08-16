class DSU {
public:
    vector<int> parent,rankk;
    
    void make_set(int n)
    {
        for(int i=0;i<n;i++)
        {
            parent.emplace_back(i);
            rankk.emplace_back(0);
        }
    }

    int findpar(int n)
    {
        if(n==parent[n]) return n;
        return parent[n]=findpar(parent[n]);
    }
    
    void unite(int u,int v)
    {
        u=findpar(u);
        v=findpar(v);
        
        if(rankk[u]<rankk[v]) 
            parent[u]=v;
        else if(rankk[v]<rankk[u]) 
            parent[v]=u;
        else
        {
            parent[v]=u;
            rankk[u]+=1;
        }
    }
};