#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using _6969orz = tree<pair<ll, ll>, null_type, less<pair<ll, ll>>,
                      rb_tree_tag, tree_order_statistics_node_update>;

struct multisetLL {
	_6969orz MS;
	ll uid = 0;

	void insert (ll x) {
		MS.insert ({x, uid++});
	}

	void erase (ll x) {
		auto it = MS.lower_bound ({x, -1});
		if (it != MS.end () && it->first == x)
			MS.erase (it);
	}

	auto lower_bound (ll x) {
		return MS.lower_bound ({x, -1});
	}

	auto upper_bound (ll x) {
		return MS.upper_bound ({x, INF});
	}

	ll pos (_6969orz :: iterator it) {
		if (it == MS.end ())
			return MS.size () + 1;
		return MS.order_of_key (*it) + 1;
	}

	ll kth (ll k) {
		return MS.find_by_order (k - 1)->first;
	}
};
