#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e2 + 7;
int c, n, m, d, q;
int w[N];
int k[30], a[510][N], t[510][N];
void solve (int x, int y) {
	int ans = 0;
//	cout << (x + y) / 2 << '\n';
	ans = w[x] + t[x][x] + t[(y + x) / 2][(y + x) / 2 + 1] + w[y]; // 先到达 起点站
//	cout << w[x] << ' ' << t[x][x] << ' ' << w[y] << ' ' << t[(y + x) / 2][(y + x) / 2 + 1] << '\n';
	for (int i = 1; i < (y + x) / 2; i++) {
		ans += (t[i + 1][i + 1] + t[i + 1][i]);
	}
	cout << ans << '\n';
	// 
	return ;
}
signed main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= k[i]; j++) {
//			cout << t[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		solve (x, y);
	}
	// 如果你想从 1 走到 2
	// 每次站内换乘都需要从一条线路的站台先走到站厅，
	// 再从站厅走到另一条线路的站台。
	return 0;
}
