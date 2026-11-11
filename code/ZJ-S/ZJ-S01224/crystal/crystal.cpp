#include <bits/stdc++.h>
#define int long long

using namespace std;

int _;
inline int read() {int s = 0, w = 1; char ch = getchar(); while (ch < '0' || ch > '9') {if (ch == '-') w *= -1; ch = getchar();} while (ch >= '0' && ch <= '9') s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar(); return s * w;}
inline void write(int x) {if (x < 0) x *= -1, putchar('-'); if (x > 9) write(x / 10); putchar(x % 10 + '0');}

const int N = 5e5 + 5;
int n, m, ans = 1, a[N], sum[N];

inline void solve() {
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	for (int i = 2, l, r; i <= n; ++i) {
		l = 0, r = i;
		while (l + 1 < r) {
			int mid = l + r >> 1;
			if ((i - mid) * a[i] - (sum[i - 1] - sum[mid - 1]) <= m) r = mid;
			else l = mid;
		}
//		cout << i << ' ' << r << '\n';
		ans = max(ans, i - r + 1);
	}
	write(ans);
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	_ = read();
	_ = 1;
	while (_--) solve();
	return 0;
}