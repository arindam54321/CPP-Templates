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
};