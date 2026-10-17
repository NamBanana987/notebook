struct DynamicSegmentTree{

    struct Node {
        int left = 0; // id của node con bên trái mà nó quản lý
        int right = 0; // id của node con bên phải mà nó quản lý
        int sum = 0;
    };

    int nNode = 1; // node gốc
    vector<Node> st;
    DynamicSegmentTree(int _n): st(30*_n) {} // Ta cần lưu tối đa Q*LOGN node

    // update(1, 1, 1e9, pos, val)
    void update(int id, int l, int r, int pos, int val) {
        if(l == r) {
            st[id].sum = val;
            return;
        }

        int mid = l + r >> 1;
        if(mid >= pos) { // vị trí pos cần update thuộc bên trái node id quản lý thì ta sẽ gọi đệ quy sang trái

            if(st[id].left == 0) st[id].left = ++nNode; // nếu node bên trái của node Id chưa tồn tại thì ta tạo thêm
            update(st[id].left , l, mid, pos, val);

        }
        else { // tương tự khi đệ quy sang phải
            if(st[id].right == 0) st[id].right = ++nNode;
            update(st[id].right, mid+1, r, pos, val);
        }
        // khi back track lên thì ta sẽ tiến hành tính lại giá trị của node đang quản lý
        // node quản lý sẽ là tổng của 2 node con
        st[id].sum = st[st[id].left].sum + st[st[id].right].sum;

    }

    // query (1, 1, 1e9, u, v)
    int query(int id, int l, int r, int u, int v) {
        if(l > v || r < u ) return 0; // TH1 không thuộc đoạn truy vấn [u, v]
        if(l >= u && r <= v) return st[id].sum; // TH2 thuộc đoạn truy vấn [u, v]

        // tiến hành gọi đệ quy chia nhỏ đoạn [l, r] đang quản lý ra  để tiến tới đoạn [u, v] truy vấn

        int mid = l + r >> 1;
        int res = 0;
        if(st[id].left != 0) res += query(st[id].left, l, mid, u, v); // nếu node con bên trái có tồn tại thì ta gọi đệ quy
        if(st[id].right != 0) res += query(st[id].right, mid +1, r , u, v); // tương tự với bên phải
        return res; // return tổng giá trị đoạn thu được
    }


};

