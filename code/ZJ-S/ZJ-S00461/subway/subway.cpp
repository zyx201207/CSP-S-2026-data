#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 510, maxd = 30, maxm = 5e5 + 10;
int pxz, n, m, ddd, q, w[maxm], d[maxn][maxn];
vector <pair <int, int> > r[maxm];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> pxz >> n >> m >> ddd >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		int k; cin >> k;
		for(int j = 1; j <= k; j++) {
			int x, t;
			cin >> x >> t;
			r[x].push_back({i, t});
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) d[i][j] = 1e18;
	}
	for(int i = 1; i <= n; i++) d[i][i] = 0;
	for(int i = 1; i <= m; i++) {
		for(auto x : r[i]) {
			for(auto y : r[i]) {
				if(x == y) continue;
				int id1 = x.first, t1 = x.second;
				int id2 = y.first, t2 = y.second;
				d[id1][id2] = min(d[id1][id2], t1 + t2);
			}
		}
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		int ans = w[x] + w[y], add = 1e18;
		for(auto u : r[x]) {
			for(auto v : r[y]) {
				int id1 = u.first, id2 = v.first;
				int t1 = u.second, t2 = v.second;
				add = min(add, t1 + t2 + d[id1][id2]);
			}
		}
		cout << ans + add << "\n";
	}
	return 0;
}
