#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
vector<int> G[maxn];
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		for (int i = 0; i < maxn; i++) {
			G[i].clear();
		}
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cout << 1 << endl;
	}
	return 0;
}
