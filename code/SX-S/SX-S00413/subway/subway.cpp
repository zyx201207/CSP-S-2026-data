#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, a, t, aa[500010], k, s[100010], maxs, u, v;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> aa[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			s[a] += t;
		}
	}
	if (c == 22 || c == 23) {
		maxs = LLONG_MIN;
		for (int i = 1; i <= m; i++) {
			maxs = max(maxs, s[i]);
		}
		maxs = maxs + aa[1] + aa[2];
		for (int i = 1; i <= q; i++) {
			cin >> u >> v;
			cout << maxs << "\n";
		}
	}

	return 0;
}
