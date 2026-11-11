#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define min(a, b) a < b ? a : b
using namespace std;

struct Edge{
	int to, w;
};

int c, n, m, r, q, w[500005];
ll d[505][505];
vector <Edge> e1[505], e2[500005];



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> r >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			int a, t;
			cin >> a >> t;
			e1[i].push_back({a, t});
			e2[a].push_back({i, t});
		}
	}
	
	for (int i = 1; i <= n; ++i) for (int j = i + 1; j <= n; ++j) {
		d[i][j] = d[j][i] = inf;
		d[i][i] = 0;
	}
	for(int i = 1; i <= m; ++i) {
		int len = e2[i].size();
		for (int j = 0; j < len; ++j) {
			for (int k = j + 1; k < len; ++k) {
				d[e2[i][j].to][e2[i][k].to] = d[e2[i][k].to][e2[i][j].to] = min(d[e2[i][j].to][e2[i][k].to], e2[i][j].w + e2[i][k].w);
			}
		}
	}
	
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		}
	}
	
	for (int i = 1; i <= q; ++i) {
		int x, y;
		ll ans = inf;
		cin >> x >> y;
		int len_x = e2[x].size(), len_y = e2[y].size();
		for (int j = 0; j < len_x; ++j) {
			for (int k = 0; k < len_y; ++k) {
				ans = min(ans, e2[x][j].w + d[e2[x][j].to][e2[y][k].to] + e2[y][k].w);
			}
		} cout << ans + w[x] + w[y] << '\n';
	}
	
	return 0;
}