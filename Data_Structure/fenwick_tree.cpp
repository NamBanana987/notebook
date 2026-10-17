struct FenwickRangeUpdateRangeQuery {
    int n;
    vector<long long> fen1, fen2;

    FenwickRangeUpdateRangeQuery(int _n) : n(_n), fen1(_n + 5, 0), fen2(_n + 5, 0) {}

    void add(int id, long long val) {
        for (int i = id; i <= n; i += i & -i) {
            fen1[i] += val;
            fen2[i] += val * id;
        }
    }

    void update(int l, int r, long long val) {
        add(l, val);
        add(r + 1, -val);
    }

    long long get(int id) {
        long long res1 = 0, res2 = 0;
        for (int i = id; i > 0; i -= i & -i) {
            res1 += fen1[i];
            res2 += fen2[i];
        }
        return (id + 1) * res1 - res2;
    }

    long long query(int l, int r) {
        return get(r) - get(l - 1);
    }
};
