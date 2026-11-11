#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505, M = 5e5+5, D = 25;
int c, n, m, d, q;
ll w[M];
int t[N][M];
ll f[N][N];//shortest road i to j
vector<int> p[M];

void Floyd() {
//	cout << 'a' << endl;
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << f[i][j] << ' ';
//		}
//		cout << endl;
//	}
}

void query(int x, int y) {
	ll ans = LLONG_MAX;
	pair<int, int> pa;
	for (int u : p[x]) {
		for (int v : p[y]) {
			if (ans > f[u][v]) {
				ans = f[u][v];
				pa = {u, v};
			}
//			cout << u << 'c' << v << endl;
		}
	}
//	cout << ans << endl;
//	cout << pa.first << 'b' << pa.second << endl;
	ans += w[x] + w[y] + (ll)t[pa.first][x] + (ll)t[pa.second][y];
	cout << ans << '\n';
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a;
			cin >> a;
			cin >> t[i][a]; //road i to stop a
			p[a].push_back(i);
		}
	}
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= m; i++) {
		for (int u : p[i]) {
			for (int v : p[i]) {
				if (u == v)
					continue;
				f[u][v] = min(f[u][v], (ll)t[u][i] + t[v][i]);
			}
		}
	}
	Floyd();
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		query(x, y);
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
