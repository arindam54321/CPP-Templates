class segment{
public:
    int N;
    vector<int> a,seg;
    
    void init(int n)
    {
        N=n;
        a.resize(N);
        seg.resize(4*N);
    }
    
    void build(int i,int low,int high)
    {
        if(low==high)
        {
            seg[i]=a[low];
            return;
        }
        int mid=(low+high)/2;
        build(i*2+1,low,mid);
        build(i*2+2,mid+1,high);
        
        // depends on question
        seg[i]=min(seg[i*2+1],seg[i*2+2]);
    }
    
    int query(int i,int low,int high,int from,int to)
    {
        if(from<=low && to>=high)
        {
            return seg[i];
        }
        else if(from>high || to<low)
        {
            // depends on question
            return INT_MAX;
        }
        else
        {
            int mid=(low+high)/2;
            int left=query(i*2+1,low,mid,from,to);
            int right=query(i*2+2,mid+1,high,from,to);
            // depends on question
            return min(left,right);
        }
    }
    
    void update(int ind, int pos, int low, int high, int val) {
    	if (low == high && pos == low) {
    		seg[ind] = val;
    		a[pos] = val;
    		return;
    	} if (pos < low || pos > high) {
    		return;
    	}
 
    	int mid = (low + high) / 2;
    	if (pos <= mid) {
    		update(2 * ind + 1, pos, low, mid, val);
    	} else {
    		update(2 * ind + 2, pos, mid + 1, high, val);
    	}
        
        // depends on question
        seg[i] = min(seg[i * 2 + 1], seg[i * 2 + 2]);
    }

};
