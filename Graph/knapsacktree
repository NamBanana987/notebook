/*__stO_stO_stO_stO_stO_stO_stO_zit_Orz_Orz_Orz_Orz_Orz_Orz_Orz__*/
		      #include<bits/stdc++.h>
			using namespace std;
			 #define name "zit"
	    using ll =   int  ;const ll MOD2=998244353; 
	    #define all(x,y) x.begin()+1, x.begin()+y+1
	    #define FOR(i,a,b) for(ll i=(a);i<=(b);++i)
	    using vl=vector<ll>; using pll=pair<ll,ll>;
	    const int maxn= 5001, MOD=1e9+7;// __   c:|
	    #define pb push_back// zit#6421  <(o )____|
	    const long long INF = 2e18;ll n;//(  ._> /|
	    #define All(x) x.begin(),x.end()/* `----'*/
vl adj[maxn];
vl sz (maxn), d (maxn), c (maxn);
ll b;

#define stop assert(0||!(cerr<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"));
#define ok cerr << "if u see this line , then ur code worked orz\n"
#define pr(orz) copy(orz,ostream_iterator<ll>(cerr," "));cerr<<'\n'
#define debug(x) cerr<<#x<<" = "<<x<<'\n'
#define el cerr<<'\n'

int dp[maxn][maxn][2];
// dp[u][k][1] = min cost

ll dfs (ll u = 1, ll par = 0) {
	// debug (u);
	// debug (par);
	// el;

	sz[u] = 1;
	for (ll & v : adj[u]) if (v != par) sz[u] += dfs (v, u);

	vector <vl> g (sz[u] + 1, vl (2, MOD));

	int cursz = 0;
	g[0][0] = g[0][1] = 0;

	for (ll & v : adj[u]) if (v != par) {
		for (int i = cursz; i >= 0; --i) {
			for (int j = 1; j <= sz[v]; ++j) {
				g[i + j][0] = min (g[i + j][0], g[i][0] + dp[v][j][0]);
				g[i + j][1] = min (g[i + j][1], g[i][1] + min (dp[v][j][0], dp[v][j][1]));
			}
		}
		cursz += sz[v];
	}

	for (int i = 1; i <= sz[u]; ++i) {
		dp[u][i][0] = min (g[i][0], g[i - 1][0] + c[u]);
		dp[u][i][1] = g[i - 1][1] + c[u] - d[u];
	}

	return sz[u];
}

void sibidi () {             cin >> n;
	cin >> b;

	for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) dp[i][j][0] = dp[i][j][1] = MOD;

	for (int i = 1; i <= n; ++i) {
		cin >> c[i] >> d[i];
		if (i >= 2) {
			int p; cin >> p;
			adj[i].pb (p);
			adj[p].pb (i);
		}
	}

	dfs ();

	// for (int i = 1; i <= n; ++i) {
	// 	for (int k = 1; k <= n; ++k ){
	// 		debug (i);
	// 		debug (k);
	// 		debug (dp[i][k][0]);
	// 		debug (dp[i][k][1]);
	// 		el;
	// 	}
	// }

	ll ans = 0;
	for (ll k = 1; k <= n; ++k) {
		if (min (dp[1][k][0], dp[1][k][1]) <= b) ans = max (ans, k);
	}
	// ok;

	cout << ans;
	
}                          signed main()                          {
		     if(fopen(name".inp","r"))
  {freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);ll _=1;
			      //cin>>_;
		   while(_--)sibidi();return 0;}
