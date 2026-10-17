/*
    EULER PATH / EULER CIRCUIT - HIERHOLZER

    Cong dung:
    - Tim duong di Euler: di qua moi canh dung chinh xac 1 lan.
    - Tim chu trinh Euler: duong di Euler co dinh dau = dinh cuoi.
    - Dung cho bai toan can tim thu tu di qua tat ca cac canh.

    Cach su dung:
    - n: so dinh, m: so canh (dinh danh tu 1 den n).
    - directed = 1 neu do thi co huong, = 0 neu vo huong.
    - Them canh bang add_edge(u, v).
    - Goi get_path() de lay duong di Euler.
    - Neu khong ton tai, ham tra ve mang rong.
    - Neu co, ket qua gom m + 1 dinh.

    Vi du:
    n = 3, m = 3
    Cac canh: (1, 2), (2, 3), (3, 1)

    Output:
    1 2 3 1

    Do phuc tap: O(n + m).
*/

struct Euler {
    int n, m = 0, directed;
    vector<vector<pair<int, int>>> adj;
    vector<int> deg_in, deg_out, used, ptr, path;

    Euler(int n, int directed) : n(n), directed(directed) {
        adj.resize(n + 1);
        deg_in.assign(n + 1, 0);
        deg_out.assign(n + 1, 0);
        ptr.assign(n + 1, 0);
    }

    void add_edge(int u, int v) {
        adj[u].push_back({v, m});
        if (!directed) adj[v].push_back({u, m});
        deg_out[u]++;
        deg_in[v]++;
        if (!directed) {
            deg_out[v]++;
            deg_in[u]++;
        }
        m++;
    }

    vector<int> get_path() {
        if (m == 0) return {};

        int s = -1, plus = 0, minus = 0;

        for (int u = 1; u <= n; u++) {
            if (directed) {
                int d = deg_out[u] - deg_in[u];
                if (d == 1) plus++, s = u;
                else if (d == -1) minus++;
                else if (d != 0) return {};
            } else {
                if (deg_out[u] % 2) {
                    plus++;
                    s = u;
                }
            }
        }

        if (directed) {
            if (!((plus == 0 && minus == 0) ||
                  (plus == 1 && minus == 1))) return {};
            if (plus == 0) {
                for (int u = 1; u <= n; u++)
                    if (deg_out[u]) {
                        s = u;
                        break;
                    }
            }
        } else {
            if (plus != 0 && plus != 2) return {};
            if (plus == 0) {
                for (int u = 1; u <= n; u++)
                    if (deg_out[u]) {
                        s = u;
                        break;
                    }
            }
        }

        used.assign(m, 0);
        vector<int> st = {s};
        path.clear();

        while (!st.empty()) {
            int u = st.back();

            while (ptr[u] < (int)adj[u].size() &&
                   used[adj[u][ptr[u]].second])
                ptr[u]++;

            if (ptr[u] == (int)adj[u].size()) {
                path.push_back(u);
                st.pop_back();
            } else {
                auto [v, id] = adj[u][ptr[u]++];
                if (used[id]) continue;
                used[id] = 1;
                st.push_back(v);
            }
        }

        if ((int)path.size() != m + 1) return {};
        reverse(path.begin(), path.end());
        return path;
    }
};
