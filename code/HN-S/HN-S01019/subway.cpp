#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, M = 5e5 + 5;
int c, n, m, d, q, dis[N][N], w[M];
struct Node {
	int to, w;
};
vector <Node> a[M];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i ++) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j ++) {
			int p, v;
			cin >> p >> v;
			a[p].push_back({i, v});
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			dis[i][j] = 1e18;
		}
		dis[i][i] = 0;
	}
	for(int i = 1; i <= m; i ++) {
		for(int j = 0; j < a[i].size(); j ++) {
			for(int k = j + 1; k < a[i].size(); k ++) {
				dis[a[i][j].to][a[i][k].to] = dis[a[i][k].to][a[i][j].to] = min(dis[a[i][j].to][a[i][k].to], a[i][j].w + a[i][k].w);
			}
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			for(int k = 1; k <= n; k ++) {
				dis[j][k] = min(dis[j][k], dis[i][k] + dis[i][j]);
			}
		}
	}
	for(int i = 1; i <= q; i ++) {
		int s, t;
		cin >> s >> t;
		int res = 1e18;
		for(auto it : a[s]) {
			for(auto it1 : a[t]) {
				res = min(res, it.w + it1.w + dis[it.to][it1.to] + w[s] + w[t]);
			}
		}
		cout << res << '\n';
	}
	return 0;
}