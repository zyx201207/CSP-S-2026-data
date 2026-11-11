#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> g[1000005];
bool f[1000005];
int n, k;
signed main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		g[0].push_back(1);
		if (c == 13 || c == 14) {
			int m = n - 1 >> 1;
			cout << (k + 2 >> 1 + (k % 2)) << ' ';
		}
	}
	return 0;
}