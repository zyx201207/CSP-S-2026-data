//2026.10.31  zyb  card
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, a[N], w[N], cnt[N], c[N];
vector<int>e[N];

void dfs(int u) {
	for (auto v : e[u]) {
		dfs(v);
		cnt[u] += cnt[v];
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		w[i] = n + 1;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		w[a[i]] = i;
	}
	for (int i = 1; i <= m; i++) {
		if (w[i] == n)
			continue;
		e[a[w[i] + 1]].push_back(i);
	}
	dfs(a[n]);
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " \n"[i == m];
	}
	return 0;
}