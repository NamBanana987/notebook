struct Edge {
	int v, w;
}; vector <vector<Edge>> adj (N), adjct (N);
vl adj2[N];
 
bool del[N];
vl h (N), tour (2 * N), pos (N), par (N, 0);
vector <vector<int>> st (19, vector <int> (2 * N, 0)); 
						
vl sz (N), par_ct (N), d (N), sumD (N), cnt (N), sumD2(N), cnt2(N);
 
int timer = 0;
void dfs (int u) {
	pos[u] = ++timer;
	tour[timer] = u;
 
	for (auto & e : adj[u]) {
		int v = e.v, w = e.w;
		if (v == par[u]) continue;
		par[v] = u;
		h[v] = h[u] + 1;
		d[v] = d[u] + w;
		dfs (v);
		tour[++timer] = u;
	}
}
 
int better (int u, int v) {if (h[u] <= h[v]) return u; return v;}
void build () {
	for (int i = 1; i <= timer; ++i) st[0][i] = tour[i];
	for (int j = 1; j < 19; ++j) 
		for (int i = 1; i + (1 << j) - 1 <= timer; ++i) 
			st[j][i] = better (st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}
 
vector <int> lg2 (2*N, -1);
int log2 (int x) {
	if (lg2[x] != -1) return lg2[x];
	if (x == 1) return 0;
	return lg2[x] = 1 + log2 (x / 2);
}
 
int LCA (int u, int v) {
	int a = pos[u], b = pos[v];
 
	if (a > b) swap (a, b);
	int len = b - a + 1, k = log2 (len);
 
	return better (st[k][a], st[k][b - (1 << k) + 1]);
}
 
int dist (int u, int v) {
	int L = LCA (u, v);
	return d[u] + d[v] - 2 * d[L];
}
 
int Sz (int u, int p) { sz[u] = 1;
	for (auto & e : adj[u]) if (e.v != p && !del[e.v]) 
		sz[u] += Sz (e.v, u); return sz[u];
}
 
int centroid (int u, int p, int & tsz) {
	for (auto & e : adj[u]) if (e.v != p && !del[e.v] && sz[e.v] > tsz / 2) 
		return centroid (e.v, u, tsz);
	return u;
}
 
void decompose (int u, int p) {
	int tsz = Sz (u, 0);
	int G = centroid (u, 0, tsz);
	del[G] = 1;
 
	par_ct[G] = p;
 
	for (auto & e : adj[G]) {
		int v = e.v;
		if (del[v]) continue;
		decompose (v, G);
	}
}
 
void toggle (int u, int delta) { int x = u;
	for (; u; u = par_ct[u]) {
		int D = dist (x, u);
		cnt[u] += delta;
		sumD[u] += delta * D;
		if (par_ct[u]) {
			int D2 = dist (x, par_ct[u]);
			cnt2[u] +=delta;
			sumD2[u] += delta * D2;
		}
	}
}
 
ll query (int u) {
	ll ans = sumD[u];
	int x = u;
 
	for (; par_ct[u]; u = par_ct[u]) {
		int p = par_ct[u];
		int D = dist (x, p);
		ans += cnt[p] * D + sumD[p];
		ans -= cnt2[u] * D + sumD2[u];
	}
 
	return ans;
}
