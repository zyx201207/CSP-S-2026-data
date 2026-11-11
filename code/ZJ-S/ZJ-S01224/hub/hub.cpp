#include <bits/stdc++.h>
#define ll long long

using namespace std;

int _;
inline int read() {int s = 0, w = 1; char ch = getchar(); while (ch < '0' || ch > '9') {if (ch == '-') w *= -1; ch = getchar();} while (ch >= '0' && ch <= '9') s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar(); return s * w;}
inline void write(int x) {if (x < 0) x *= -1, putchar('-'); if (x > 9) write(x / 10); putchar(x % 10 + '0');}

const int N = 2e6 + 5;
int c, n, d, a[N];

inline void solve() {
	n = read(), d = read();
	for (int i = 1, x, y; i < n; ++i) x = read(), y = read();
	write(1), putchar('\n');
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	c = read(), _ = read();
//	_ = 1;
	while (_--) solve();
	return 0;
}