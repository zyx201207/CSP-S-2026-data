#include <bits/stdc++.h>

using namespace std;

vector<int> Fa;

void Init(int q) {
	Fa.assign(q + 1, 0);
	for(int i = 1; i <= q; i++) {
		Fa[i] = i;
	}
}

int Find(int u) {
	if(u == Fa[u]) {
		return u;
	}
	return Fa[u] = Find(Fa[u]);
}

void Union(int u, int v) {
	Fa[Find(u)] = Find(v);
}

int main() {
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m + 1);
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	vector<int> k(n + 1);
	vector<vector<int>> a(n + 1), t(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		a[i].assign(k[i] + 1, 0);
		t[i].assign(k[i] + 1, 0);
		for(int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	vector<int> x(q + 1), y(q + 1);
	for(int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	
	Init(m);
	
	
	// try'na get more points
	for(int i = 1; i <= q; i++) {
		cout << w[x[i]] + w[y[i]] << '\n';
	}
	
	
	return 0;
}
