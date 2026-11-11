#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
vector<int> edge[1000006];
bool v[1000006];
void build(int now, int fa, int depth) {
	return;
}
void dfs(int x, int chosed) {
	if (x == n + 1) {
		if (chosed == k) {
			int fa1 = -1, fa2 = -1;
			for (int i = 1; i <= n; i++) {
				if (v[i]) {
					
				}
			}
		}
		return;
	}
	if (chosed == k) {
		
		return;
	}
	v[x] = 1;
	dfs(x + 1, chosed + 1);
	v[x] = 0;
	dfs(x + 1, chosed);
	return;
}
void solve() {
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		edge[u].emplace_back(v);
		edge[v].emplace_back(u);
	}
	build(1, 0, 1);
	dfs(1, 0);
	return;
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, c;
	cin >> c >> T;
	while (T--) {
		solve();
	}
	return 0;
}
