#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstring>

#define int long long

using namespace std;

const int M = 5e5 + 5, N = 505;

int c, n, m, d, q, sw[M], lk, u, v, w, t[N][N], dis[N][N], ans;
vector < pair <int, int> > s[M];

void floyd()
{
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> sw[i];
	for (int i = 1; i <= n; i++) {
		cin >> lk;
		u = i;
		for (int j = 1; j <= lk; j++) {
			cin >> v >> w;
			s[v].push_back({u, w});
		}
	}
	
	memset(t, 0x3f, sizeof t);
	for (int i = 1; i <= m; i++) {
		for (auto it : s[i]) {
			for (auto jt : s[i]) {
				if (it.first == jt.first) continue;
				t[it.first][jt.first] = min(t[it.first][jt.first], it.second + jt.second);
			}
		}
	}
	
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			dis[i][j] = t[i][j];
		}
	}
	
	floyd();
	
	while (q--) {
		cin >> u >> v;
		ans = 1e18;
		for (auto it : s[u]) {
			for (auto jt : s[v]) {
				ans = min(ans, dis[it.first][jt.first] + it.second + jt.second);
			}
		}
		cout << ans + sw[u] + sw[v] << '\n';
	}
	
	return 0;
}