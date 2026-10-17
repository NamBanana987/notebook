struct Sparse {
	ll n; 
	vl LG;
	vector<vector<pll> > st;
	pll better (pll & a, pll & b) {
		return min (a, b);
	}

	Sparse(ll n, vl & a) : n(n), LG (n + 1, 0), st(n + 1, vector<pll> (20, {0, 0})) {
		for (ll i = 1; i <= n; ++i) {
			st[i][0] = {a[i], i};
			if (i > 1) LG[i] = LG[i/2] + 1;
		}
		for (ll j = 1; j <= 19; ++j) 
			for (ll i = 1; i + (1<<j) - 1 <= n; ++i)
				st[i][j] = better(st[i][j-1], st[i + (1<<(j-1))][j-1]);
	}
	pll rmq(ll l, ll r) {
		if (l > r) return {INF, 0};
		ll k = LG[r-l+1];
		return better(st[l][k], st[r - (1<<k) + 1][k]);
	}
};
