#include <bits/stdc++.h>
#define int long long

using namespace std;

int _;
inline int read() {char ch = getchar(); int s = 0, w = 1; while (ch < '0' || ch > '9') {if (ch == '-') w *= -1; ch = getchar();} while (ch >= '0' && ch <= '9') s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar(); return s * w;}
inline void write(int x) {if (x < 0) putchar('-'), x *= -1; if (x > 9) write(x / 10); putchar(x % 10 + '0');}

const int N = 2e5 + 5;
struct node {
	int c, s;
	char a;
} a[N], b[N];
int n, mid, cur, sum, idx, m, ans;

inline void solve() {
	cin >> n;
	char x;
	int c;
	for (int i = 1; i <= n; ++i) {
		cin >> c >> x;
		sum += c;
		if (!idx || a[idx].a != x) a[++idx] = {c, 0, x};
		else a[idx].c += c;
	}
	if (sum & 1) {
		int mid = sum + 1 >> 1;
		bool f = 0;
		for (int i = 1; i <= idx; ++i) {
			a[i].s = a[i - 1].s + a[i].c;
			if (!f && a[i].s >= mid) {
				f = 1;
				if (mid - a[i - 1].s - 1 > 0) b[++m] = {mid - a[i - 1].s - 1, mid - 1, a[i].a};
				b[++m] = {1, mid , a[i].a};
				cur = m;
				if (a[i].s - mid > 0) b[++m] = {a[i].s - mid, a[i].s, a[i].a};
				mid = cur;
			} else b[++m] = a[i];
		}
//		for (int i =1 ; i <= m; ++i) cout << b[i].c << '\n';
		int l = 1, r = m;
		while (l < mid && r > mid) {
//			cout << l << ' ' << r << '\n';
			if (b[l].c > b[r].c) {
				b[l].c -= b[r].c;
				if (b[l].a != b[r].a) ans += b[r].c;
				--r;
			} else if (b[l].c == b[r].c) {
				if (b[l].a != b[r].a) ans += b[r].c;
				--r, ++l;
			} else {
				b[r].c -= b[l].c;
				if (b[l].a != b[r].a) ans += b[l].c;
				++l;
			}
		}	
	} else {
		int mid = sum >> 1;
		bool f = 0;
		for (int i = 1; i <= idx; ++i) {
			a[i].s = a[i - 1].s + a[i].c;
			if (!f && a[i].s >= mid) {
				f = 1;
				b[++m] = {mid - a[i - 1].s, mid, a[i].a};
				cur = m;
				if (a[i].s - mid > 0) b[++m] = {a[i].s - mid, a[i].s, a[i].a};
				mid = cur;
			} else b[++m] = a[i];
		}
		int l = 1, r = m;
		while (l <= mid && r > mid) {
//			cout << l << ' ' << r << '\n';
			if (b[l].c > b[r].c) {
				b[l].c -= b[r].c;
				if (b[l].a != b[r].a) ans += b[r].c;
				--r;
			} else if (b[l].c == b[r].c) {
				if (b[l].a != b[r].a) ans += b[r].c;
				--r, ++l;
			} else {
				b[r].c -= b[l].c;
				if (b[l].a != b[r].a) ans += b[l].c;
				++l;
			}
		}	
	}
	cout << ans;
}

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	_ = 1;
//	_ = read();
	while (_--) solve();
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/