#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int c, T, n, d, x[N], a[N], sum[N], f[N], g[N];
int s[N], p[N], cnt = 0;
inline int calc(int l) {
	for (int i = 2; i <= cnt; i ++) {
		if (p[i - 1] != l && sum[p[i]] - sum[p[i - 1] - 1] <= d) {
			p[i - 1] --;
			return 1;
		}
	}
	return 0;
}
inline void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i ++) cin >> x[i];
	n --;
	for (int i = 1; i <= n; i ++) a[i] = x[i + 1] - x[i], sum[i] = sum[i - 1] + a[i];
//	if (n <= 300) {
//		int ans = 0;
//		for (int l = 1; l <= n; l ++) {
//			for (int r = l; r <= n; r ++) {
//				cnt = 0;
//				int x = 0;
//				for (int i = l; i <= r; i ++) {
//					if (x + a[i] > d) cout << i << ' ', s[++ cnt] = x, p[++ cnt] = i - 1, x = 0;
//					x += a[i];
//				}
//				s[++ cnt] = x, p[++ cnt] = r;
//				int o = 0;
//				for (int i = 1; i <= cnt; i ++) cout << p[i] << ' ';cout << '\n';
//				while (o < 2 && calc(l)) o ++;
//				for (int i = 1; i <= cnt; i ++) cout << p[i] << ' ';cout << '\n';
////				cout << o << ' ';
//				ans += o == 1;
//			}
//		}
//		cout << ans << '\n';
//		return ;
//	}
	memset(f, 0, sizeof(int) * (n + 4));
	memset(g, 0, sizeof(int) * (n + 4));
	for (int i = n; i >= 2; i --) {
		int r2 = upper_bound(sum + i, sum + n + 1, sum[i - 1] + d) - sum;
		int r1 = upper_bound(sum + i, sum + n + 1, sum[i - 2] + d) - sum;
		///r1 ~ r2 - 1
		if (r1 < r2)
			g[i] = r2 - r1 + g[r2];
	}
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
	for (int i = n; i >= 2; i --) {
		int r2 = upper_bound(sum + i, sum + n + 1, sum[i - 1] + d) - sum;
		int r1 = upper_bound(sum + i, sum + n + 1, sum[i - 2] + d) - sum;
		if (r1 < r2)
			f[i] = r2 - r1 + f[r2];
	}
	for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for (int l = 3; l <= n; l ++) {
		if (a[l] + a[l - 1] > d) continue;
		int r1 = upper_bound(sum, sum + n + 1, sum[l - 3] + d) - sum;
		int r2 = upper_bound(sum, sum + n + 1, sum[l - 2] + d) - sum;
		int c1 = r2 - r1;
		if (r2 != n + 1 && sum[r2] - sum[l - 1] <= d) ;
		else c1 += g[r2];
		int l1 = lower_bound(sum, sum + n + 1, sum[l] - d) - sum;
		int l2 = lower_bound(sum, sum + n + 1, sum[l - 1] - d) - sum;
//		cout << r1 << ' ' << r2 << ' ' << l1 << ' ' << l2 << '\n';
		int c2 = l1 - l2;
		if (l2 && sum[l - 2] - sum[l2] <= d);
		else c2 += f[n - l2 + 1];
//		cout << c1 << ' ' << c2 << ' ';
		if (r1 < r2 && l2 < l1) ans += c1 * c2;
//		cout << ans << '\n';
	}
	cout << ans << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T --) solve();
	return 0;
}