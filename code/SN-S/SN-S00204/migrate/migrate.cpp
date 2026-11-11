#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int C, T;
int n, D;
int a[N];

//inline void solve() {
//	cin >> n >> D;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	int res = 0;
//	for (int R = 2; R <= n; R++) {
//		int ls = R, sz = 1, tg = 1, gt = 0;
//		while (ls > 1) {
//			int l = 1, r = ls - 1, ans = 0, mid = 0;
//			while (l <= r) {
//				mid = (l + r) >> 1;
//				if (a[ls] - a[mid] <= D) ans = mid, r = mid - 1;
//				else l = mid + 1;
//			}
//			if (ans == 0) break;
//			int tl = ans;
//			l = tl, r = ls - 1, ans = tl - 1, mid = 0;
//			while (l <= r) {
//				mid = (l + r) >> 1;
//				if (sz == 1 || a[ls + 1] - a[mid] > D) ans = mid, l = mid + 1;
//				else r = mid - 1;
//			}
//			if (tg == 2) res += ans - tl + 1;
//			int fl = ans;
//			if (sz > 1 && ans < ls - 1) {
//				int l = ans + 1, r = ls - 1, mid = 0;
//				while (l <= r) {
//					mid = (l + r) >> 1;
//					if (sz == 2 || a[ls + 2] - a[mid] > D) ans= mid, l = mid+1;
//					else r = mid - 1;
//				}
//				if (gt) res += ans - fl + 1;
//			}
//			gt = 0;
//			if (fl >= tl + 1) gt = 1;
//			sz = ls - tl, ls = tl;
//		}
////		cerr<<"R "<<R<<" "<<res<<"\n";
//	}
//	cout << res << '\n';
//}

int d[N],f[N];
inline void solve() {
	cin >> n >> D;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int res = 0;
	for (int R = 2; R <= n; R++) {
		f[R] = 1, d[R] = 0;
		for (int i = R - 1, j = R; i; --i) {
			while (j > i && a[j] - a[i] > D) --j;
			if (i == j) break;
			d[i] = d[j] + 1;
			int sum = f[j];
			if (j - 1 > i) {
				if (d[j - 1] == d[j]) sum += f[j - 1];
				if (j - 2 > i && d[j - 2] == d[j]) sum += f[j - 2];
			}
			sum = min(sum, 3ll);
			f[i] = sum;
			if (sum == 2) res += 1;
		}
	}
	cout << res << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> C >> T;
	while (T--) solve();
	return 0;
}
