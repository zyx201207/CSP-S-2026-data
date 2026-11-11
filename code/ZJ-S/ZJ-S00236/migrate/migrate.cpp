#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e2 + 5, inf = 0x3f3f3f3f3f3f3f3f;
int c, t, a[N], n, d, f[N][N], ans;
void solve() {
	cin >> n >> d; ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) f[i][j] = inf;
		for (int j = i + 1; j <= n; j++) {
			for (int k = j - 1; k >= i; k--) {
				if (a[j] - a[k] > d) break;
				f[i][j] = min(f[i][j], f[i][k] + 1);
			//if (f[i][j] < 0) cout << i << " " << j << " " << k << " " << f[i][j] << " " << f[i][k] << "\n";
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int cnt = 0;
			for (int k = i + 1; k < j; k++) {
				if (f[i][k] + f[k][j] == f[i][j]) {
					cnt++;
					if (cnt > 2) break;
//					if (i == 1 && (j == 5 || j == 6)) {
//						cout << j << " " << k << " " << f[i][k] << " " << f[k][j] << " " << f[i][k] << "\n";
//					}
				} 
			}
			ans += (cnt == 2);
		}
	}
	cout << ans << "\n";
	return ;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
//int cc, t, a[N], n, d, p, c[N][2], p2, tot, ans;
//void solve() {//wozenmehaiganxiangT3zhengjie
//	cin >> n >> d; p = p2 = 1, tot = ans = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		while (p <= n) {
//			if (a[p + 1] - a[i] > d) break;
//			p++;
//		}
//		if (p > n) p = n - 1;
//		if (p - i <= 1) continue;
//		while (p2 <= n) {
//			if (a[p2 + 1] - a[p] > d) break;
//			p2++;
//		}
//		if (p2 > n) p2 = n;
//		if (p2 == p) continue;
//		if (d - a[p2] + a[p] > a[p] - a[p - 1]) continue;
//		c[++tot][0] = i, c[tot][1] = p2;
//	}
//	for (int i = 1; i <= tot; i++) {
//		if (i == 1) {ans++; continue;}
//		if (i == tot) {/**/continue;}
//		if (c[i - 1][1] <= c[i][0]) {
//			
//		} else if (c[i - 1][1] == c[i][1]) {
//			
//		}
//	}
//	cout << ans << "\n";
//	return ;
//}