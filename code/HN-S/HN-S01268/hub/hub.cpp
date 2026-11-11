#include <bits/stdc++.h>

using namespace std;

const int N = 2001000;

int c, T, n, m, ans;
vector<int> e[N];

void dfs(int p, int fa, int dep) {
	if (e[p].size() == 1) ans = min(ans, dep);
	for (auto i : e[p]) {
		if (i == fa) continue;
		dfs(i, p, dep + 1);
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	ans = n + 1;
	dfs(1, 0, 1);
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) e[i].clear();
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while (T--) solve();
	return 0;
} 
