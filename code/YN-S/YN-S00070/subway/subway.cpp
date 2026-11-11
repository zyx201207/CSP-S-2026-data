#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
long long w[500010], judis[510][510];

struct distance {
	int top, index[25];
	long long dis[25];
} t[500010];

void init() {
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			judis[i][j] = 1e18;
			judis[j][i] = 1e18;
		}
	for (int i = 1; i <= m; ++i) {
		int top = t[i].top;
		for (int j = 1; j <= top; ++j) {
			for (int k = j + 1; k <= top; ++k) {
				int u = t[i].index[j], v = t[i].index[k];
				long long w1 = t[i].dis[j] + t[i].dis[k];
				judis[u][v] = min(judis[u][v], w1);
				judis[v][u] = min(judis[v][u], w1);
			}
		}
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				judis[i][j] = min(judis[i][j], judis[i][k] + judis[k][j]);
}

long long solve(int x, int y) {
	int top1 = t[x].top, top2 = t[y].top;
	long long ans = 1e18;
	for (int i = 1; i <= top1; ++i)
		for (int j = 1; j <= top2; ++j) {
			int u = t[x].index[i], v = t[y].index[j];
			long long w1 = w[x] + w[y] + judis[u][v] + t[x].dis[i] + t[y].dis[j];
			ans = min(ans, w1);
		}
	return ans;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
		cin >> w[i];
	for (int i = 1, k; i <= n; ++i) {
		cin >> k;
		for (int j = 1, u; j <= k; ++j) {
			cin >> u;
			int top = ++t[u].top;
			t[u].index[top] = i;
			cin >> t[u].dis[top];
		}
	}
	init();
	for (int i = 1, x, y; i <= q; ++i) {
		cin >> x >> y;
		cout << solve(x, y) << "\n";
	}
	return 0;
}