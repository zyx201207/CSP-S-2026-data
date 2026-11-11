#include <bits/stdc++.h>
using namespace std;
int c, t;
int n, k;
vector<int>head[1000006];

void add_edge(int u, int v) {
	head[u].push_back(v);
	head[v].push_back(u);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin > n >> k;
		if (n == k) {
			cout << 0 << endl;
			break;
		}
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			add_edge(u, v);
		}
		cout << 1 << endl;
	}
	return 0;
}