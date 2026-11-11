#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
namespace IO {
const int SIZ = 1 << 20;
char buf[SIZ], *nw, *ed;
inline char getchar() {
	if (nw == ed) ed = buf + fread(buf, sizeof(char), SIZ, stdin), nw = buf;
	return *(nw++);
}
template<typename T> void read(T &x) {
	x = 0;
	int f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	x *= f;
}
template<typename T, typename ...Args> void read(T &x, Args &...args) {
	read(x), read(args...);
}
}
using IO::read;
using ll = long long;
const int N = 2e6 + 10;
int pre[N], suf[N];
ll a[N], n, m;
inline void calc(int *f) {
	int l = 0, r = 0;
	a[0] = -3e18;
	a[n + 1] = 3e18;
	for (int i = 1; i <= n; i++) {
		while (a[i] - a[l] > m) l++;
		while (r <= i && a[i + 1] - a[r + 1] > m) r++;
		if (l > r || l == i) f[i] = 1;
		else f[i] = r - l + f[l];
		if (l <= r && r < i) f[i]++;
//		cout << i << " " << l << " " << r << " " << f[i] << endl;
	}
}
inline void solve() {
	read(n, m);
	for (int i = 1; i <= n; i++) read(a[i]);
	calc(pre);
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) a[i] *= -1;
	calc(suf);
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) a[i] *= -1;
//	for (int i = 1; i <= n; i++) cout << pre[i] << " " << suf[n - i + 1] << endl;
	ll ans = 0;
	int l1 = 0, r1 = 0, l2 = 1, r2 = 1;
	for (int i = 1; i < n; i++) {
		if (a[i + 1] - a[i] > m) continue;
		while (a[i + 1] - a[l1] > m) l1++;
		while (r1 < i - 1 && a[i + 2] - a[r1 + 1] > m) r1++;
		while (r2 < n && a[r2 + 1] - a[i] <= m) r2++;
		while (a[l2] - a[i - 1] <= m || l2 <= i + 1) l2++;
		if (l1 > r1 || l2 > r2) continue;
		ll L = r1 - l1 + pre[l1], R = r2 - l2 + suf[n - r2 + 1];
		if (a[r2 + 1] - a[i + 1] <= m) R = r2 - l2 + 1;
		if (-a[l1 - 1] + a[i] <= m) L = r1 - l1 + 1;
//		cout << i << " " << l1 << " " << r1 << " " << l2 << " " << r2 << " " << L << " " << R << endl;
		ans += L * R;
	}
	cout << ans << "\n";
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, ttt;
	read(c, ttt);
	while (ttt--) solve();
}

/*
0 1
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
*/
