#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define N 505
#define M 500005
using namespace std;
int c, n, m, d, q, p;
ll w[M], u, v, f[N][N], ans, tmp, INF;
vector<pair<int, ll>>a[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> p;
		for (int j = 1; j <= p; j++) {
			cin >> u >> v;
			a[u].pb({i, v});
		}
	}
	memset(f, 0x3f, sizeof(f));
	INF = f[0][0];
	for (int i = 1; i <= m; i++)
		for (auto [x, y] : a[i])
			for (auto [u, v] : a[i])
				f[x][u] = min(f[x][u], y + v), f[u][x] = min(f[u][x], y + v);
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				f[j][k] = min(f[j][k], f[j][i] + f[i][k]);
	while (q--) {
		cin >> u >> v;
		ans = w[u] + w[v], tmp = INF;
		for (auto [s, t] : a[u])
			for (auto [x, y] : a[v])
				tmp = min(tmp, t + f[s][x] + y);
		ans += tmp;
		cout << ans << endl;
	}
	return 0;
}