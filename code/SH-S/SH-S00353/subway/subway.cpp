#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 505
#define M 500005
int c, n, m, d, q, w[M], ed[N][N];
vector<pair<int, int>> e1[N + M];
template<typename T> void updmin(T &x, T y) { x = min(x, y); }
void floyd() {
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				updmin(ed[i][j], ed[i][k] + ed[k][j]);
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int k; cin >> k;
		for (int j = 1; j <= k; ++j) {
			int a, t; cin >> a >> t;
			e1[m + i].emplace_back(make_pair(a, t));
			e1[a].emplace_back(make_pair(m + i, t));
		}
	}
	memset(ed, 0x3f, sizeof ed);
	for (int i = 1; i <= n; ++i) ed[i][i] = 0;
	for (int i = 1; i <= m; ++i)
		for (size_t j = 0; j < e1[i].size() - 1; ++j)
			for (size_t k = j + 1; k < e1[i].size(); ++k) {
				auto w1 = e1[i][j], w2 = e1[i][k];
				int dis = w1.second + w2.second;
				updmin(ed[w1.first - m][w2.first - m], dis);
				updmin(ed[w2.first - m][w1.first - m], dis);
			}
	floyd();
	while (q--) {
		int x, y, ans = LLONG_MAX; cin >> x >> y;
		for (size_t i = 0; i < e1[x].size(); ++i)
			for (size_t j = 0; j < e1[y].size(); ++j) {
				auto w1 = e1[x][i], w2 = e1[y][j];
				updmin(ans, w1.second + ed[w1.first - m][w2.first - m] + w2.second);
			}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
