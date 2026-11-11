/*
subway
*/
#include <bits/stdc++.h>
#define ll long long
#define N 1010
#define INF 1e9
using namespace std;
struct Node {
	int id;
	ll t;
};
int c, n, m, d, q;
int w[N], k[N];
Node t[N][N];
ll dis[N][N];
void init() {
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) {
			dis[i][j] = INF;
		}
		dis[i][i] = 0;
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q; init();
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j) {
			cin >> t[i][j].id >> t[i][j].t;
		}
		for (int j = 1; j <= k[i]; ++j) {
			for (int p = 1; p <= k[i]; ++p) {
				int x = t[i][j].id;
				int y = t[i][p].id;
				ll xt = t[i][j].t;
				ll yt = t[i][p].t;
				dis[x][y] = min(dis[x][y], xt + yt);
				dis[y][x] = min(dis[x][y], xt + yt);
			}
		}
	}
	for(int k = 1; k <= m; ++k) {
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (dis[i][k] + dis[k][j] < dis[i][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + dis[x][y] << '\n';
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
*/

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
