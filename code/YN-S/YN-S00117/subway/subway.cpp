#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 505, K = 505;
int c, n, m, d, q, w[M], t[N][K], g[N][M];
bool vis[M];
long long ans = 1e9;
vector<int>e[M];

void dfs(int u, int ed, int id, long long sum) {
	if (u == ed) {
		sum += w[ed];
		//cout << u << "  " << sum << endl;
		ans = min(ans, sum);
		return ;
	}
	for (auto v : e[u]) {
		if (!vis[v]) {
			vis[v] = 1;
			for (int i = 1; i <= n; i++)
				if (g[i][u] && g[i][v]) {
					if (id != i) {
						//cout << u << ' ' << v << ' ' << id << "->" << i << ' ' << sum << ' ' << g[i][u] << ' ' << g[i][v] << ' ' << sum +
						// g[i][u] + g[i][v] << endl;
						dfs(v, ed, i, sum + g[i][u] + g[i][v]);
					} else if (id == i) {
						//cout << u << ' ' << v << ' ' << id << "->" << i << ' ' << sum << ' ' << g[i][v] << ' ' << sum + g[i][v] << endl;
						dfs(v, ed, i, sum + g[i][v]);
					}
				}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in ", "r", stdin);
	freopen("subway.out ", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k, prea = 0;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			g[i][a] = t;
			if (j > 1) {
				e[prea].push_back(a);
				e[a].push_back(prea);
			}
			prea = a;
		}
	}
	while (q--) {
		int x, y;
		ans = 1e9;
		memset(vis, 0, sizeof(vis));
		cin >> x >> y;
		vis[x] = 1;
		dfs(x, y, 0, w[x]);
		cout << ans << endl;
	}
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
	32
	17

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

	35
	16
*/