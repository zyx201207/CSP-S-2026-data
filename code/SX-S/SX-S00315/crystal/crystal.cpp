#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll m, n, a[500010], qzh[500010];

inline bool check(ll x) {
	for (int z = x; z <= n; z++) {
		if (a[z] *x - qzh[z] + qzh[z - x] <= m) {
			return 1;
		}
	}
	return 0;
}
int main(int argv, char **argc) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int z = 1; z <= n; z++) {
		cin >> a[z];
	}
	sort(a + 1, a + n + 1);

	for (int z = 1; z <= n; z++) {
		qzh[z] = qzh[z - 1] + a[z];
	}
	ll l = 1, r = n;

	while (l < r) {
		ll mid = (l + r + 1ll) >> 1ll;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1ll;
		}
	}
	cout << l;
	return 0;
}
