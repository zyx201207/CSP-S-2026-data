#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10, M = 510;
int w[N];
using P = pair<int, int>;
vector<P> vec[N];
vector<int> a[M], t[M];
int d[M][M], k[N];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int c, n, m, D, q;
	cin >> c >> n >> m >> D >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i]; // 站台到站厅 
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		a[i].resize(k[i] + 5);
		t[i].resize(k[i] + 5);
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			vec[a[i][j]].push_back({i, t[i][j]});
		}
	}
	memset(d, 0x3f, sizeof(d));
	for (int i = 1; i <= n; i++) {
		d[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int x = 0; x < (int)vec[i].size(); x++) {
			for (int y = 0; y < (int)vec[i].size(); y++) {
				int X = vec[i][x].first, Y = vec[i][y].first;
				d[X][Y] = min(d[X][Y], vec[i][x].second + vec[i][y].second);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		int xy = w[x] + w[y];
		int ans = 5e18;
		for (auto p : vec[x]) {
			for (auto q : vec[y]) {
				ans = min(ans, d[p.first][q.first] + p.second + q.second);
			}
		}
		ans += xy;
		cout << ans << "\n";
	}
	return 0;
}

/*
2e8 能放过吗？？？只有 1s......

O(md^2 + n^3 + qd^2)
*/