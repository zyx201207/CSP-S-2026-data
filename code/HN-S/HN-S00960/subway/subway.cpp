#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e2 + 10, M = 5e5 + 10;
int c, n, m, d, q, tot, w[M], mp[N][N];
vector<pair<int, int> > G[M];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	memset(mp, 0x3f, sizeof mp);
	for (int i = 1, k, a, t; i <= n; i ++) {
		cin >> k; 
		for (int j = 1; j <= k; j ++) {
			cin >> a >> t;
			G[a].push_back({i, t});
		}
		mp[i][i] = 0;
	}
	for (int i = 1; i <= m; i ++) {
		for (auto to1 : G[i]) {
			int v1 = to1.first, w1 = to1.second;
			for (auto to2 : G[i]) {
				int v2 = to2.first, w2 = to2.second;
				if (v1 == v2) continue;
				mp[v1][v2] = mp[v2][v1] = min(mp[v1][v2], w1 + w2);
			}
		}
	}
	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				mp[i][j] = mp[j][i] = min(mp[i][j], mp[i][k] + mp[k][j]);
			}
		}
	}
	for (int i = 1, st, ed; i <= q; i ++) {
		cin >> st >> ed;
		int ans = 1e18;
		for (auto td1 : G[st]) {
			int v1 = td1.first, w1 = td1.second;
			for (auto td2 : G[ed]) {
				int v2 = td2.first, w2 = td2.second;
				ans = min(ans, mp[v1][v2] + w1 + w2);
			}
		}
		cout << ans + w[st] + w[ed] << '\n';
	}
	return 0;
}
// 同机房人均300+，灯丝了。。 
