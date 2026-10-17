struct FenwickTree
{
    int n;
    vector<vector<int>> pos, bit;
    void init(int _n){
        n = _n;
        pos.assign(n + 5, {});
        bit.assign(n + 5, {});
    }

    void fakeAdd(int u, int v){
        for(; u < n; u += u&-u){
            pos[u].pb(v);
        }
    }

    void fakeQuery(int u, int v){
        for(; u > 0; u -= u&-u){
            pos[u].pb(v);
        }
    }

    void compress(){
        for(int i = 1; i < n; i++){
            pos[i].push_back(0);
            sort(all(pos[i]));
            pos[i].erase(unique(all(pos[i])), pos[i].end());
            bit[i].assign(sz(pos[i]) + 1, 0);
        }
    }
    
    void add(int u, int v, int x){
        for(int i = u; i < n; i += i&(-i)){
            for(int j = upper_bound(all(pos[i]), v) - pos[i].begin(); j < bit[i].size(); j += j&(-j)){
                bit[i][j] += x;
            }
        }
    }

    int get(int u, int v){
        int sum = 0;
        for(int i = u; i > 0; i -= i&(-i)){
            for(int j = upper_bound(all(pos[i]), v) - pos[i].begin(); j > 0; j -= j&(-j)){
                sum += bit[i][j];
            }
        }
        return sum;
    }


    int query(int x1, int y1, int x2, int y2){
        return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1) ;
    }
};
