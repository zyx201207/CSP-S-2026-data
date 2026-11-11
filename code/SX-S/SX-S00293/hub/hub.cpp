#include <bits/stdc++.h>

using namespace std;
int n, k;

void sol() {
	cin >> n >> k;
	vector<vector<int>> G(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v), G[v].push_back(u);
	}
	if (k <= n / 2)
		cout << n - n / 2  - k;
	else if (n - n / 2 - k <= 0)
		cout << 1;
	cout << endl;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
		sol();
	return 0;
}
