#include <bits/stdc++.h>
using namespace std;
int c, t, n, k;
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i < n; ++i) {
			int u, v; cin >> u >> v;
		}
		int m = (n - 1) / 2;
		if (k <= m) cout << (m - k) / 4 + 2 << "\n";
		else if (k < n) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
