#include <bits/stdc++.h>
using namespace std;
const int M = 5e5+5;
const int Q = 1e5+5;
int a[M];
int c, n, m, d, q;
int V[505][505];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		int u, w;
		cin >> u >> w;
		if (V[u][u] == 0 || V[u][u] < w)
			V[u][u] = w;
		if (t == 2) {
			int v, w2;
			cin >> v >> w2;
			if (V[u][v] == 0 || V[u][v] < w2)
				V[u][v] = w2;
			if (V[v][v] == 0 || V[v][v] < w2)
				V[v][v] = w2;
		}
	}
	for (int i = 1; i <= q; i++) {
		int u, v;
		cin >> u >> v;
		int ans = a[u] + a[v];
		cout << ans + V[u][v] << '\n';
	}
	return 0;
}