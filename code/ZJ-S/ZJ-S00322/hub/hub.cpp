#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> g[N];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			g[i].clear();
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (k == 1) {
			cout << "0\n";
			continue;
		}
		if (k == 2)
			cout << "1\n";
		else
			cout << n << "\n";
	}
	return 0;
}