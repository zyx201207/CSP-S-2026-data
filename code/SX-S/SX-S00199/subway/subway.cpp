#include <bits/stdc++.h>
using namespace std;

struct node {
	int a;
	long long t;
};
long long dis[505][505];
vector<node> v[500005];
long long w[500005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a;
			long long t;
			cin >> a >> t;
			v[a].push_back(node{i, t});
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			dis[i][j] = 1e18;
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			for (int k = j + 1; k < v[i].size(); k++) {
				dis[v[i][j].a][v[i][k].a] = min(dis[v[i][j].a][v[i][k].a], v[i][j].t + v[i][k].t);
				dis[v[i][k].a][v[i][j].a] = min(dis[v[i][k].a][v[i][j].a], v[i][j].t + v[i][k].t);
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
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		long long ans = 1e18;
		for (int j = 0; j < v[x].size(); j++) {
			for (int k = 0; k < v[y].size(); k++) {
				ans = min(ans, v[x][j].t + v[y][k].t + dis[v[x][j].a][v[y][k].a] + w[x] + w[y]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
