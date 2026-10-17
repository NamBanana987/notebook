struct Node {
	int cnt;
	Node *c[2];
	Node () : cnt (0) {
		c[0] = c[1] = nullptr;
	}
};
const int lg = 30;
struct Trie {
	Node *root = new Node ();
	int num = 0;

	void upd (int v, int delta) {
		num += delta;
		Node *cur = root;
		for (int i = lg; i >= 0; --i) {
			int bit = (v >> i & 1);
			if (cur -> c[bit] == nullptr) cur -> c[bit] = new Node ();
			cur = cur -> c[bit];
			cur -> cnt += delta;
		}
	}
	int kth (int k) {
		if (num < k) return -1;

		int ans = 0;
		Node *cur = root;

		for (int i = lg; i >= 0; --i) {
			if (cur -> c[0] && cur -> c[0] -> cnt >= k) 
				cur = cur -> c[0];
			else {
				ans += (1 << i);
				if (cur -> c[0])
					k -= cur -> c[0] -> cnt;
				if (cur -> c[1] == nullptr) break;
				cur = cur -> c[1];
			}
		}
		return ans;
	}
	int lwb (int v) { // #<v + 1
		int ans = 0;
		Node *cur = root;
		for (int i = lg; i >= 0; --i) {
			int bit = (v >> i & 1);
			if (bit && cur -> c[0]) ans += cur -> c[0] -> cnt;

			if (cur -> c[bit] == nullptr) break;
			cur = cur -> c[bit];
		}
		return ans + 1;
	}
};
