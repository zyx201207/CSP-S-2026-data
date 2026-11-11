#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int M = 5e2 + 10, N = 5e5 + 10;
int _, n, m, d, q, k[M];
LL w[N], dis[M + N];
vector<LL> a[M], t[M];
vector<pair<int, LL> > g[M + N];
void dfs(int x, int sum) {
	for (auto e : g[x]) {
		if (sum + e.second < dis[e.first]) {
			dis[e.first] = sum + e.second, dfs(e.first, dis[e.first]);
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> _ >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		a[i].resize(k[i] + 5), t[i].resize(k[i] + 5);
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			if (k[i] > 2) {
				g[a[i][j]].emplace_back(m + i, t[i][j]);
				g[m + i].emplace_back(a[i][j], t[i][j]);
			}
		}
		if (k[i] == 2) {
			g[a[i][1]].emplace_back(a[i][2], t[i][1] + t[i][2]);
			g[a[i][2]].emplace_back(a[i][1], t[i][1] + t[i][2]);
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		LL ans = 1e18;
		for (auto e : g[x]) {
			if (_ < 9 || _ > 11) for (int i = 1; i <= n + m; i++) dis[i] = 1e18;
			else for (int i = 1; i <= m; i++) dis[i] = 1e18;
			dis[x] = e.second, dfs(x, e.second);
			ans = min(ans, dis[y] - dis[x]);
		}
//		for (int i = 1; i <= m + n; i++) cout << dis[i] << " ";
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
