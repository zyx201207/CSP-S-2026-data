#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 5e5 + 3;
int c, n, m, d, q, w[M], k[N];
long long f[N][N];
vector<int> a[N], t[N];
vector<pair<int, int> > col[M];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) 
			if (i != j) f[i][j] = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1, x, y; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> x >> y;
			a[i].push_back(x);
			t[i].push_back(y);
			col[x].push_back({i, y});
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k[i]; j++) {
			for (auto v : col[a[i][j]]) {
				if (v.first == i) continue;
				f[v.first][i] = min(1ll * v.second + t[i][j], f[v.first][i]);
				f[i][v.first] = f[v.first][i];
			}
		}
	}
	for (int kk = 1; kk <= n; kk++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][kk] + f[kk][j], f[i][j]);
			}
		}
	}
	int st, ed;
	long long ans;
	for (int i = 1; i <= q; i++) {
		cin >> st >> ed;
		if (st == ed) {
			cout << "0\n";
			continue;
		}
		ans = 0x3f3f3f3f3f3f3f3f;
		for (auto v : col[st]) {
			for (auto u : col[ed]) {
				ans = min(ans, f[v.first][u.first] + v.second + u.second);
			}
		}
		cout << ans + w[st] + w[ed] << '\n';
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
