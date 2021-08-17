class fenwick {
public:
    int N;
    vector<int> fen;
    
    void init(int n)
    {
        N=n;
        fen.resize(0);
        for(int i=0;i<N;i++)
            fen.emplace_back(0);
    }
    
    void update(int i,int add)
    {
        while(i<N)
        {
            fen[i]+=add;
            i+=(i&(-i));
        }
    }
    
    int sum(int i)
    {
        int s=0;
        while(i>0)
        {
            s+=fen[i];
            i-=(i&(-i));
        }
        return s;
    }
    
    // Find lower-bound using binary lifting
    int findlb(int k)
    {
        int i=0,s=0;
        for(int j=log2(N);j>=0;j--)
        {
            if(i+(1<<j)<N && fen[i+(1<<j)]+s<k)
            {
                i+=(1<<j);
                s+=fen[i];
            }
        }
        return i+1;
    }
};
