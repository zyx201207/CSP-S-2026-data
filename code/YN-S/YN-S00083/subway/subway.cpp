#include <bits/stdc++.h>
using namespace std;
int w[500001];

struct node {
	int t, l;
};
vector<node> a[500001];
int s = 1e9, u, v;

void dfs(int x, int t) {
	if (x == v) {
		s = min(s, t);
		return;
	}
	for (int i = 0; i < a[x].size(); i++) {
		for (int j = 0; j < 5001; j++) {
			if (a[j].size() > 1)
				dfs(j, t + a[x][i].t + a[j][i].t);
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q, k, x1, t1;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> x1 >> t1;
			a[x1].push_back({i, t1});
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> u >> v;
		s = 1e9;
		dfs(u, 0);
		cout << s + w[u] + w[v];
	}
	return 0;
}
