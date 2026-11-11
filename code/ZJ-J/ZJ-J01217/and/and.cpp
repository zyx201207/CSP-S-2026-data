#include <bits/stdc++.h>
//#define int long long

using namespace std;

int _;
inline int read() {char ch = getchar(); int s = 0, w = 1; while (ch < '0' || ch > '9') {if (ch == '-') w *= -1; ch = getchar();} while (ch >= '0' && ch <= '9') s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar(); return s * w;}
inline void write(int x) {if (x < 0) putchar('-'), x *= -1; if (x > 9) write(x / 10); putchar(x % 10 + '0');}

const int N = 2e5 + 5;
int n, m, ans, a[N], tar;
vector<int> x[30];

inline bool cmp(int x, int y) {
	int x0 = x & tar, y0 = y & tar;
	if (x0 != y0) return x0 > y0;
	return x > y;
}

inline void solve() {
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		for (int j = 0; j < 30; ++j) if (a[i] >> j & 1) x[j].push_back(a[i]);
	}
	bool f = 0, fl = 0;
	for (int i = 30; ~i; --i) {
		if (x[i].size() < m) continue;
//		cout << i << '\n';
		for (int j = i; ~j; --j) {
			fl = 0;
			tar = 1 << j;
			sort(x[i].begin(), x[i].end(), cmp);
			ans = 0;
			for (int k = 0; k < m; ++k) {
//				cout << i << ' ' << k << ' ' << x[i][k] << '\n';
				if (!ans) ans = x[i][k];
				else ans &= x[i][k];
				if (x[i][k] >> j & 1) continue;
				fl = 1;
				break;
			}
			if (!f && !fl) f = 1;
			else if (f && !fl) write(ans), exit(0);
		}
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	_ = 1;
//	_ = read();
	while (_--) solve();
	return 0;
}
/*
4 2
3 15 12 12

*/