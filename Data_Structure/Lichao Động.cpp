struct Line {
	ll a, b;
	Line (ll a = 0, ll b = INF) : a (a), b (b) {}
	ll calc (ll x) {return a * x + b;}
};

struct Node {
	Line L;
	Node *lpt, *rpt;
	Node () : L (), lpt (nullptr), rpt (nullptr) {}
};

struct Lichao {
	Node *R = new Node ();
	void upd (Node *root, ll l, ll r, Line f) {
		if (l == r) {
			if (f.calc (l) < root -> L.calc (l)) root -> L = f;
			return;
		} ll mid = l + r >> 1;
		if (f.calc (mid) < root -> L.calc (mid)) swap (f, root -> L);

		if (f.a > root -> L.a) {
			if (root -> lpt == nullptr) root -> lpt = new Node ();
			upd (root -> lpt, l, mid, f);
		}

		if (f.a < root -> L.a) {
			if (root -> rpt == nullptr) root -> rpt = new Node ();
			upd (root -> rpt, mid + 1, r, f);
		}
	} void upd (ll l, ll r, Line f) {upd (R, l, r, f);}

	ll get (Node *root, ll l, ll r, ll x) {
		ll cur = root -> L.calc (x);
		if (l == r) return cur;
		ll mid = l + r >> 1;

		if (x <= mid) {
			if (root -> lpt == nullptr) return cur;
			return min (cur, get (root -> lpt, l, mid, x));
		}

		if (root -> rpt == nullptr) return cur;
		return min (cur, get (root -> rpt, mid + 1, r, x));
	} ll get (ll l, ll r, ll x) {return get (R, l, r, x);}
};
