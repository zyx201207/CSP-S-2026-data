#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 10;
int n, m, a[M], lst[M], nxt[M], sum[M], deg[M], ans[M];
vector<int> g[M];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		lst[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (lst[a[i]] != i) {
			g[i].push_back(lst[a[i]]);
			deg[lst[a[i]]]++;
		} else {
			g[i].push_back(i + 1);
			deg[i + 1]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		sum[i] = 1;
		if (deg[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < g[x].size(); i++) {
			int e = g[x][i];
			sum[e] += sum[x];
			deg[e]--;
			if (!deg[e]) q.push(e);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (lst[a[i]] == i) ans[a[i]] = sum[i];
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
