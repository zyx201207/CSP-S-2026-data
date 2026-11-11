#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 505, M = 5e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, w[M];
pair <int, int> val[M];
ll dis[N][N];
vector <pair <int, int>> v[N], bel[M];

void solve() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int x, y;
			cin >> x >> y;
			v[i].push_back({x, y});
			bel[x].push_back({i, y});
		}
	}
	for (int i = 1; i <= n; i++) {
		for (auto _ : v[i]) {
			int x = _.first, y = _.second;
			val[x] = {y, i};
		}
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				dis[i][j] = 0;
				continue;
			}
			ll res = inf;
			for (auto _ : v[j]) {
				int x = _.first, y = _.second;
				if (val[x].second == i)
					res = min(res, (ll)val[x].first + y);				
			}
			dis[i][j] = res;
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];
	while (q--) {
		int x, y;
		cin >> x >> y;
		ll res = inf;
		for (auto _ : bel[x]) {
			int s = _.first, v1 = _.second;
			for (auto _2 : bel[y]) {
				int t = _2.first, v2 = _2.second;
				res = min(res, dis[s][t] + v1 + v2);
			} 
		}
		cout << res + w[x] + w[y] << "\n";
	}
	
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
    cin.tie(0), cout.tie(0), cerr.tie(0) -> sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}