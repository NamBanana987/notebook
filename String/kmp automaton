vl calc_pi (string & s) {
	vl pi (s.size (), 0);
	for (ll i = 1; i < s.size (); ++i) {
		ll j = pi[i - 1];
		while (j && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

vector <vl> calc_aut (string & s) {
	vector <vl> aut (s.size () + 1, vl (26, 0));
	vl pi = calc_pi (s);
	aut[0][s[0] - 'a'] = 1;

	s += '#';

	for (ll i = 1; i < s.size (); ++i) {
		FOR (c,0,25) {
			if (c + 'a' != s[i]) aut[i][c] = aut[pi[i - 1]][c];
			else aut[i][c] = i + 1;
		}
	}
	
	s.pop_back ();
	return aut;
}
