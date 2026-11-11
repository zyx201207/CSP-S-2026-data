#include <bits/stdc++.h>
#define qwq ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int, int>
//#define int long long
using namespace std;
const int N = 5e5 + 5;
int c, n, m, d, q;
int w[N], k[505], a[505][N], t[505][N];
vector<pii> g[505];
int dis[505];
bool v[505];
bool cmp(pii a, pii b) {
	return a.second < b.second;
}
void dij(int s) {
	priority_queue<pii> que;
	memset(dis, 0x3f, sizeof dis);
	memset(v, 0, sizeof v);
	dis[s] = 0;
	v[s] = 1;
	while (que.size()) {
		pii u = que.top();
		que.pop();
		for (auto i : g[u.first]) {
			if (v[i.first]) continue ;
			v[i.first] = 1;
			que.push({i.first, i.second + dis[u.first]});
			dis[i.first] = dis[u.first] + i.second;
		}
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	qwq;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int x; cin >> a[i][j] >> x;
			t[i][a[i][j]] = x, v[a[i][j]] = 1;
			for (int l = 1; l < i; l++) {
				if (!v[a[l][j]]) continue ;
				g[i].push_back({l, t[i][a[i][j]] + t[l][a[i][j]]});
				g[l].push_back({i, t[i][a[i][j]] + t[l][a[i][j]]});
			}
		}
	}
	while (q--) {
		int x, y; cin >> x >> y;
		dij(x);
		cout << dis[y] << "\n";
	}
	return 0;
}
