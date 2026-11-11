#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
int c, n, m;
int d, q;
struct Eged{
	int w;
	int a, t;
}g[M];
int dis[M][N];
void solve(int x, int y) {
	int sum = g[x].w;
	int sx, sy;
	int tx, ty;
	bool flag_s = false;
	bool flag_t = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= dis[i][0]; j++) {
			if (dis[i][j] == x && !flag_s) {
				sx = i;
				sy = j;
				flag_s = true;
			}
			if (dis[i][j] == y && !flag_t) {
				tx = i;
				ty = j;
				flag_t = true;
			}
		}
	}
	if (sx == tx) {
//		for (int i = 1; i <= dis[sx][0]; i++) cout << g[i].t << ' ';
//		cout << '\n';
		for (int i = 1; i <= dis[sx][0]; i++) {
			sum += g[dis[sx][i]].t;
			if (dis[sx][i] == x) {
				break;
			}
		}
	} else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				
			}
		}
	}
	sum += g[y].w;
	cout << sum << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m;
	cin >> d >> q;
	for (int i = 1; i <= m; i++) cin >> g[i].w;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		dis[i][0] = k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			g[a].t = t;
			dis[i][j] = a;
//			cout << g[dis[i][j]].t << ' ';
		}
//		for (int j = 1; j <= dis[i][0]; j++) cout << g[dis[i][j]].t << ' ';
//		cout << '\n';
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		solve(x, y);
	}
	return 0;
}
