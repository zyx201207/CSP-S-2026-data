#include <bits/stdc++.h>

#define int long long
#define pii pair<int, int>
using namespace std;
const int M = 5e5 + 5;
const int N = 5e2 + 2;
// m <= 5e5 , n <= 5e2, d <= 20
int c, n, m, d, q;
int w[M];
int dis[N][N];
vector<pii> G[N];
// [id, val]
vector<pii> belong[M];
// [id, val]
signed main() {
	// if in submit
		freopen("subway.in", "r", stdin);
		freopen("subway.out", "w", stdout);
	// endif
	// if in test
		// freopen("subway7.in", "r", stdin);
		// freopen("subway.out", "w", stdout);
	// endif

	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i]; // ditie kou -> ditie ting
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			G[i].emplace_back(a, t);
			belong[a].emplace_back(i, t);
		}
	}
	memset(dis, 0x3f, sizeof(dis)); for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (pii x : belong[i]) {
			for (pii y : belong[i]) {
				int idx = x.first, idy = y.first;
				int vx = x.second, vy = y.second;
				if (idx == idy) continue;
				dis[idx][idy] = min(dis[idx][idy], vx + vy);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		int s, t;
		cin >> s >> t;// s != t ok
		int ans1 = w[s] + w[t], ans2 = LLONG_MAX;
		for (pii st : belong[s]) {
			for (pii ed : belong[t]) {
				// solve
				int x = st.first, y = ed.first;
				int vx = st.second, vy = ed.second;
				ans2 = min(ans2, dis[x][y] + vx + vy);
			}
		}
		cout << ans1 + ans2 << '\n';
	}
	return 0;
}
