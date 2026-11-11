#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10, M = 510, INF = 0x3f3f3f3f3f3f3f3fLL;
bool BE;
int tid, n, m, d, q;
vector<pair<int, int>> vec[N];  // (id, val)
int w[N], f[M][M];
bool ED;


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	cerr << ((&ED - &BE) >> 20) << "Mib\n";
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> tid >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int x, t;
			cin >> x >> t;
			vec[x].push_back({i, t});
		}
	}
	// build
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; i++) f[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (auto pu : vec[i]) {
			for (auto pv : vec[i]) {
				int u = pu.first, v = pv.first, w = pu.second + pv.second;
				f[u][v] = min(f[u][v], w);
				f[v][u] = min(f[v][u], w);
			}
		}
	}
	// floyd
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	// answer
	while (q--) {
		int s, t;
		cin >> s >> t;
		int ans = INF;
		for (auto pu : vec[s]) {
			for (auto pv : vec[t]) {
				int u = pu.first, v = pv.first, w = pu.second + pv.second;
				ans = min(ans, w + f[u][v]);
			}
		}
		ans += w[s] + w[t];
		cout << ans << '\n';
	}
	return 0;
}

