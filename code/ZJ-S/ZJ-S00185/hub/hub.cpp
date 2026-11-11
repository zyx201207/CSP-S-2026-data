#include<bits/stdc++.h>
using namespace std;
int c, t, kskbl;
vector<int> g[500020];
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n - 1; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << k / 2 + k % 2 << endl;
	}
	return 0;
}
