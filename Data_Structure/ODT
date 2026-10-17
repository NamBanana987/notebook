struct Interval {
	int l, r, val;
	bool operator<(const Interval&X) const {
		return l < X.l;
	}
};

struct ODT {
	int n;
	set <Interval> s;
	ODT (int n) : n (n) {
		s.insert ({1, n, 0});
	}

	auto split (int pos) {
		if (pos > n) return s.end ();
		auto it = --s.upper_bound ({pos, 0, 0});
		if (it -> l == pos) return it;
		int l = it -> l, r = it -> r, val = it -> val;

		s.erase (it); 
		s.insert ({l, pos - 1, val});

		return s.insert ({pos, r, val}).first;
	}

	void assign (int l, int r, int t) {
		auto itR = split (r + 1), itL = split (l);
		for (auto it = itL; it != itR; ++it) 
			// lam gi do "it"
		s.erase (itL, itR);
		s.insert ({l, r, t});
	}
};
