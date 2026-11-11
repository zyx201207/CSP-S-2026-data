#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], ans[N], siz[N], vis[N], nxt[N];
vector<int>e[N];

void dfs(int x, int fa) {
	siz[x] = 1;
	for (auto v : e[x]) {
		dfs(v, x);
		siz[x] += siz[v];
	}
}

void dfs1(int x, int fa) {
	if (vis[a[x]] == 0) {
		ans[a[x]] += siz[x];
	}
	vis[a[x]]++;
	//cout << x << " " << vis[a[x]] << '\n';
	for (auto v : e[x]) {
		dfs1(v, x);
	}
	vis[a[x]]--;
}

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		nxt[a[i]] = i;
	}
	for (int i = n - 1; i >= 1; i--) {
		if (nxt[a[i]] != i)
			e[nxt[a[i]]].push_back(i);
		else
			e[i + 1].push_back(i);
	}
	dfs(n, 0);
	dfs1(n, 0);
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
