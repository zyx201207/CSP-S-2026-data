#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, k;
int n[1000005];
vector<int> g[1000005];
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	return 0; 
}
