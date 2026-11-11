#include <bits/stdc++.h>
using namespace std;
//#define int long long
//注意有的要开long long
const int N = 5e5 + 5;
const long long INF = 1000000000000000000;
int c, n, m, d, q;
int w[N];
long long dis[505][505];

struct node {
	int lx;
	int sj;
};
vector<node> dian[N];
vector<node> v[505];//每条路线上的点

void floyd() {
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			int u = v[i][j].lx;
			int w = v[i][j].sj;
			for (int k = 0; k < dian[u].size(); k++) {
				int V = dian[u][k].lx;
				int W = dian[u][k].sj;
				if (V == i) {
					continue;
				}
				dis[i][V] = min(dis[i][V], (long long)(w + W));
				dis[V][i] = min(dis[V][i], (long long)(w + W));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (k == i || k == j) {
					continue;
				}
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int x, y;
			cin >> x >> y;
			v[i].push_back({x, y});
			dian[x].push_back({i, y});
		}
	}
	floyd();
	while (q--) {
		int x, y;
		cin >> x >> y;
		long long minn = INF;
		for (int i = 0; i < dian[x].size(); i++) {
			for (int j = 0; j < dian[y].size(); j++) {
				int u = dian[x][i].lx, w = dian[x][i].sj;
				int U = dian[y][j].lx, W = dian[y][j].sj;
				minn = min(minn, dis[u][U] + w + W);
			}
		}
		cout << minn + w[x] + w[y] << '\n';
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
