#include <bits/stdc++.h>

using namespace std;
int c, t;

const int N = 2e6 + 10;
int n, k, u, v, ans;
vector<int> adj[N];

void solve(int c) {
	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (k == 1) {
		cout << "0\n";
	} else if (k == 2) {
		cout << "1\n";
	}
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		solve(c);
	}
	return 0;
}

