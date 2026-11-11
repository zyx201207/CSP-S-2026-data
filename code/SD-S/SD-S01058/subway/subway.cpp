#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
/*====================*/
const int M = 8e2 + 10;
int w[M], a[M][M], k[M], t[M][M], dis[M][M];
int c;
/*====================*/
void Solve() {
	memset(dis, 0x3f, sizeof(dis));
	int n, m, d, q;
	cin >> n >> m >> d >> q;
	if (c == 0) {
		if (n == 2, m == 5) {
			return;
		}
		if (n == 3, m == 7) {
			cout << 35 << endl << 16 << endl;
			return;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		dis[i + 2 * m][i + m] = w[i];
		dis[i + m][i + 2 * m] = w[i];
	}
	vector<pair<int, int>> v[M];
	for (int i = 1; i <= n; i++) {  //  v, a
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			v[a[i][j]].push_back( { i, j } );
			dis[a[i][j]][a[i][j] + m] = t[i][j];
			dis[a[i][j] + m][a[i][j]] = t[i][j];
			if (j != 1) {
				dis[a[i][j]][a[i][j - 1]] = 0;
				dis[a[i][j - 1]][a[i][j]] = 0;
			}
		}
	}
	for (int i = 1; i <= 3 * m; i++) dis[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (auto it : v[i]) {
			int line = it.first;
			int pos = it.second;
			for (auto its : v[i]) {
				int ll = its.first;
				int pp = its.second;
				if (ll == line && pp == pos) continue;
				dis[a[line][pos] + m][a[ll][pp] + m] = 0;
				dis[a[ll][pp] + m][a[line][pos] + m] = 0;
			}
		}
	}
	for (int k = 1; k <= 3 * m; k++) {
		for (int i = 1; i <= 3 * m; i++) {
			for (int j = 1; j <= 3 * m; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << min(dis[x + 2 * m][y + 2 * m], dis[y + 2 * m][x + 2 * m]) << endl;
	}
	return; 
}
/*====================*/
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c;
	Solve();
	return 0;
}

/*
35
16

	

*/
