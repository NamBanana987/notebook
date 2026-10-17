struct PersistentSegTree {

    struct Node {
        int left, right, sum;
    };

    int nNode = 0;
    vector<Node> st;

    PersistentSegTree(int _n): st(30*_n) {} // số node tối đa sẽ tạo ra khi xét hết N version

    int F(int left, int right) {
        return st[left].sum + st[right].sum;
    }

    int build(int l, int r) {
        int id = nNode++;
        if(l == r) {
            st[id] = {0, 0, 0};
            return id;
        }
        int mid = l + r >> 1;
        st[id].left = build(l, mid);
        st[id].right = build(mid+1, r);

        st[id].sum = F(st[id].left, st[id].right);

        return id;
    }


    int update(int old_id, int l, int r, int p, int v) {
        int new_id = nNode++;
        if(l == r) {
            st[new_id] = {0, 0, v};
            return new_id;
        }
        int mid = l + r >> 1;
        if(mid >= p) {
            st[new_id].left = update(st[old_id].left, l, mid, p, v);
            st[new_id].right = st[old_id].right; // id của node con bên phải của node cũ cùng tầng
        }
        else {
            st[new_id].right = update(st[old_id].right, mid+1, r, p, v);
            st[new_id].left = st[old_id].left;
        }

        st[new_id].sum =F(st[new_id].left, st[new_id].right);
        return new_id;
    }


    int query(int id, int l, int r, int u, int v) {
        if(l > v || r < u) return 0;
        if(l >= u && r <= v) return st[id].sum;
        int mid = l + r >> 1;
        return query(st[id].left, l, mid, u, v) + query(st[id].right, mid+1, r, u, v);
    }


};



PersistentSegTree Tree(N);

