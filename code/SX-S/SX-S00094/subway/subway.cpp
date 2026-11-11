#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5 * 1e5+9;

struct station {
	ll time;
	ll sub[22];
	ll next[22];
} a[N];

ll dfs(ll x, ll y, ll cnt, ll id) {
	if (x == y) {
		return cnt + a[x].sub[id];
	}
	ll mmin = INT_MAX;
	bool is = true;
	for (int i = 1; i <= 20; i++) {
		if (a[x].next[i] == 0)
			continue;
		if (id != i) {
			mmin = min(mmin, dfs(a[x].next[i], y, cnt + a[x].sub[i] + a[x].sub[id], i));
			is = false;
		} else {
			mmin = min(mmin, dfs(a[x].next[id], y, cnt, id));
			is = false;
		}
	}
	return mmin;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ll c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> a[i].time;
	for (int i = 1; i <= n; i++) {
		ll k;
		cin >> k;
		ll o = 0;
		for (int j = 1; j <= k; j++) {
			ll p;
			cin >> p;
			if (j != 1) {
				a[o].next[i] = p;
			}
			o = p;
			cin >> a[p].sub[j];
		}
	}
	while (q--) {
		ll x, y;
		cin >> x >> y;
		ll ans = a[y].time + a[x].time;
		ans += dfs(x, y, 0, 0);
		cout << ans << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
