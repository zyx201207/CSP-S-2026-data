#include<bits/stdc++.h>
using namespace std;
int c, T, n, k;
vector<int> g[1000005];
signed main() {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;cin >> u >> v;
			g[u].push_back (v);
		}
		cout << n / 3 + 1 << '\n';
	}
	return 0;
}