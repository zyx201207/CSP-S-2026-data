#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 5e5+5, N = 505, D = 25, inf = 1e9;
int c, n, m, d, q;
int w[M], k[N];
map <int, int> t[M];
vector <int> p[M], l[N];
int sz[N];
int dis[N][N];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios:: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int a, tm; cin >> a >> tm;
			t[a][i] = tm;
			p[a].push_back(i);
			l[i].push_back(a);
			sz[i]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		sort(l[i].begin(), l[i].end());
		for (int j = 1; j <= n; j++)
			dis[i][j] = inf;
		dis[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (i == j) continue;
			for (int a = 0, b = 0; a < sz[i] && b < sz[j]; ) {
				if (l[i][a] < l[j][b]) a++;
				else if (l[j][b] < l[i][a]) b++;
				else dis[i][j] = dis[j][i] = min(dis[i][j], t[l[i][a++]][i] + t[l[j][b++]][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dis[i][j] = dis[j][i];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for (int r = 1; r <= q; r++) {
		int s, e; cin >> s >> e;
		int ans = inf;
		for (int i: p[s]) for (int j: p[e])
			ans = min(ans, t[s][i] + dis[i][j] + t[e][j]);
		cout << ans + w[s] + w[e] << '\n';
	}
	return 0;
}
