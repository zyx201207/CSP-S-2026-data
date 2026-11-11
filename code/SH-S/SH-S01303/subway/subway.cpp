#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 501;
const int M = 500010;
vector<pair<int, int>> bel[M];
int c, n, m, d, q, a, t, w[M], k[N];
inline void optimizeIO(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
}
i64 dis[N][N];
template <class T>
inline void chkmin(T &a, const T &b) {
	if (a > b) a = b;
}
int main(void) {
	memset(dis, 0x3f, sizeof(dis));
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	optimizeIO(), cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i], dis[i][i] = 0;
		for (int j = 0; j < k[i]; j++) {
			cin >> a >> t;
			bel[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= m; i++) {
		const int sz = bel[i].size();
		for (int j = 0; j < sz; j++) {
			auto &[u, tu] = bel[i][j];
			for (int k = 0; k < j; k++) {
				auto &[v, tv] = bel[i][k];
				chkmin<i64>(dis[u][v], tu + tv);
				chkmin<i64>(dis[v][u], tu + tv);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				chkmin(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		int a, b;
		cin >> a >> b;
		i64 ans = LLONG_MAX;
		for (auto &[u, tu] : bel[a]) {
			for (auto &[v, tv] : bel[b]) {
				chkmin(ans, tu + tv + dis[u][v]);
			}
		}
		cout << ans + w[a] + w[b] << '\n';
	}
	return 0;
}
