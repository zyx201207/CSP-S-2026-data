#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
int c, t;
vector<int> g[maxn];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}