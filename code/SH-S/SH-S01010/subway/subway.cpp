#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define N 505

int c, n, m, d, q;
int a[500005];
vector<pair<int, long long>> h[500005];
long long f[N][N];

void solve() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> a[i];
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		f[i][i] = 0;
		for (int j = 1; j <= k; j++) {
			int v; long long w; cin >> v >> w;
			for (int k = 0; k < h[v].size(); k++) {
				int l = h[v][k].first;
				f[i][l] = f[l][i] = min(f[i][l], w+h[v][k].second);
			}
			h[v].push_back({i, w});
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while (q--) {
		int x, y; cin >> x >> y;
		long long ans = 9e18;
		for (int i = 0; i < h[x].size(); i++) {
			int u = h[x][i].first;
			for (int j = 0; j < h[y].size(); j++) {
				int v = h[y][j].first;
				ans = min(ans, f[u][v] + a[x] + a[y] + h[x][i].second + h[y][j].second);
			}
		}
		cout << ans << '\n'; 
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int T = 1;
	// cin >> T;
	while (T--) solve();
	return 0;
}
