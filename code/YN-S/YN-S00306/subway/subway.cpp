#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 5e5 + 5;
int c, n, m, d, q, len[N];
long long w[M], f[N][N];
vector<pair<int, long long> >g[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> len[i];
		for (int j = 1; j <= len[i]; j++) {
			int x, val;
			cin >> x >> val;
			g[x].push_back({i, val});
		}
	}
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			for (int k = j + 1; k < g[i].size(); k++) {
				int x = g[i][j].first,  y = g[i][k].first;
				long long valx = g[i][j].second, valy = g[i][k].second;
				f[x][y] = min(f[x][y], valx + valy), f[y][x] = min(f[y][x], f[x][y]);
			}
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	for (int i = 1; i <= q; i++) {
		int x, y;
		long long ans = 1000000000000000000;
		cin >> x >> y;
		for (int a = 0; a < g[x].size(); a++) {
			for (int b = 0; b < g[y].size(); b++) {
				int X = g[x][a].first,  Y = g[y][b].first;
				long long valx = g[x][a].second, valy = g[y][b].second;
				ans = min(ans, f[X][Y] + valx + valy);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}