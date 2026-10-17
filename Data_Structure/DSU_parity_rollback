struct Dsu {
	vi par, sz, parity;
	int n, num, bipartite = 1;
	vector <pair<int&, int>> hist;
	Dsu (int n) : n (n), num (n), par (n+1, 0), sz (n+1, 1), parity (n+1, 0) {
		iota (all (par, n), 1);
	}

	int snapshot () {return hist.size ();}
	void change (int &cur, int val) {
		hist.pb ({cur, cur});
		cur = val;
	}
	void rollback (int time) {
		while (hist.size () > time) {
			auto p = hist.back ();
			hist.pop_back ();
			p.fi = p.se;
		}
	}

	// neu ko rollback thi ham asc nho compress
	pii asc (int u) {
		if (par[u] == u) return {u, 0};
		pii R = asc (par[u]);
		return {R.fi, parity[u] ^ R.se};
	}

	void join (int u, int v) {
		pii gu = asc (u), gv = asc (v);
		int ru = gu.fi, pu = gu.se,
			rv = gv.fi, pv = gv.se;
		if (ru == rv) {
			if (pu == pv) 
				change (bipartite, 0);
			return;
		}

		if (sz[ru] > sz[rv]) {
			swap (ru, rv);
			swap (pu, pv);
		}
		change (num, num-1);
		change (par[ru], rv);
		change (sz[rv], sz[rv] + sz[ru]);
		change (parity[ru], pu ^ pv ^ 1);
	}
};
