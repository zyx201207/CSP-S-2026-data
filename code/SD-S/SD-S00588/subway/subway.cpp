#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using db = double;

const int MAXM = 5e5 + 5;
const int MAXN = 505;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int w[MAXM];
vector<pair<int, int>> xian[MAXM];
ll dis[MAXN][MAXN];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
		xian[i].reserve(d);
	}
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			int a, t;
			cin >> a >> t;
			xian[a].push_back({i, t});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; ++i) dis[i][i] = 0;
	for (int i = 1; i <= m; ++i) {
		for (auto it1 : xian[i]) {
			int x = it1.first, t1 = it1.second;
			for (auto it2 : xian[i]) {
				int y = it2.first, t2 = it2.second;
				dis[x][y] = min<ll>(dis[x][y], t1 + t2);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
			}
		}
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		ll ans = INF;
		for (auto it1 : xian[u]) {
			int x = it1.first, t1 = it1.second;
			for (auto it2 : xian[v]) {
				int y = it2.first, t2 = it2.second;
				ans = min(ans, t1 + t2 + dis[x][y]);
			}
		}
		cout << ans + w[u] + w[v] << '\n';
	}
}
