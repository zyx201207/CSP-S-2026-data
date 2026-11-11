#include <bits/stdc++.h>

using namespace std;

const int N = 4999;
int c, n, m, d, q, ans;
int w[N], a[N][N], t[N][N], k[N], to[N];
void solve(int x, int y) {
	ans = 0;
	ans += w[x] + w[y];
	int zd;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {
			if (to[a[i][j]] > 1) zd = a[i][j]; 
		}
	}
	if (x == y + 1 || x == y - 1)
       	ans += t[x][x] + t[x][zd];
	else ans += t[x][x] + (t[x][zd] + t[zd][zd - 1]) + t[zd][y - 1];
		
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) cin >> a[i][j] >> t[i][j], to[a[i][j]]++;
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= 3; j++) cout << t[i][j] << ' ';
//		cout << endl;
//	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		solve(l, r);
		cout << ans << endl;
	}
	return 0;
}
