#include<iostream>
#include<algorithm>
#define int long long
#define gc getchar
#define pc putchar
using namespace std;
int rd() {
	int res = 0, c = gc();
	bool f = false;
	while (c < 48 || c > 57) {
		if (c == 45) f = true;
		c = gc();
	}
	while (48 <= c && c <= 57) res = (res << 3) + (res << 1) + (c ^ 48), c = gc();
	if (f) return -res;
	return res;
}
void wr(int x) {
	if (x < 0) pc(45), x = -x;
	if (x > 9) wr(x / 10);
	pc(x % 10 + 48);
}
const int maxn = 2e6 + 5;
//bool st;
int c;
int n, d;
int a[maxn];
int f[maxn];
int b[maxn];
int lf[maxn];
int rf[maxn];
int lb[maxn];
int rb[maxn];
int mf[maxn];
int mb[maxn];
//bool nd;
void MAIN() {
	int ans = 0;
	n = rd(), d = rd();
	for (int i = 1; i <= n; i ++) a[i] = rd();
	for (int i = 0; i <= n + 1; i ++) {
		f[i] = -1;
		b[i] = -1;
		lf[i] = -1;
		rf[i] = -1;
		lb[i] = -1;
		rb[i] = -1;
		mf[i] = 0;
		mb[i] = 0;
	}
	if (c == 11 || c == 12) {
		int x = d / (a[2] - a[1]);
		for (int i = 1; i <= n; i ++) ans += n / d;
		wr(ans), pc('\n');
		return;
	}
	if (13 <= c && c <= 16) {
		if (a[n] - a[1] <= d) {
			puts("0");
			return;
		}
		int cnt = 0, R = 0;
		for (int i = 1; i <= n; i ++) {
			if (f[i] == n && b[i] == 1) cnt ++, R = i;
		}
		if (cnt >= 3) {
			puts("0");
			return;
		}
		if (cnt == 2) {
			for (int i = 1; i <= n && f[i] == R; i ++) ans ++;
			wr(ans), pc('\n');
			return;
		}
		for (int i = 1; i <= n; i ++) if (f[i] == R + 1) ans ++;
		wr(ans), pc('\n');
		return;
	}
	for (int i = 1; i <= n; i ++) {
		f[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
		b[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a; 
	}
	for (int i = 1; i <= n; i ++) {
		if (f[i] != f[i - 1]) lb[f[i]] = i;
		if (f[i] != f[i + 1]) rb[f[i]] = i;
		if (b[i] != b[i - 1]) lf[b[i]] = i;
		if (b[i] != b[i + 1]) rf[b[i]] = i;
	}
//	for (int i = 1; i <= n; i ++) {
//		if (rb[i] == i) {
//			rb[i] --;
//			if (rb[i] > lb[i]) lb[i] = rb[i] = -1;
//		} 
//		if (lf[i] == i) {
//			lf[i] ++;
//			if (rf[i] > lf[i]) lf[i] = rf[i] = -1;
//		}
//	}
	for (int i = n; i; i --) {
		if (~rf[i]) mb[i] = mb[rf[i]] + (rf[i] - lf[i] + 1);
	}
	for (int i = 1; i <= n; i ++) {
		if (~lb[i]) mf[i] = mf[lb[i]] + (rb[i] - lb[i] + 1);
	}
//	for (int i = 1; i <= n; i ++) {
//		wr(i), pc(':'), pc('\n');
//		wr(f[i]), pc(' ');
//		wr(b[i]), pc(' ');
//		wr(lf[i]), pc(' ');
//		wr(rf[i]), pc(' ');
//		wr(lb[i]), pc(' ');
//		wr(rb[i]), pc(' ');
//		wr(mf[i]), pc(' ');
//		wr(mb[i]), pc('\n');
//	}
	for (int i = 1; i < n; i ++) {
		if (a[i + 1] - a[i] <= d && mb[i] && mf[i + 1] && !(f[i] == i + 1 || b[i + 1] == i)) {
			int u = mb[i], v = mf[i + 1];
			if (f[i] == i + 1) v --;
			if (b[i + 1] == i) u --;
			ans += u * v;
//			wr(u), pc(' ');
//			wr(v), pc('\n');
//			if (f[i] == i + 1 || b[i + 1] == i) ans --;
		}
	}
	wr(ans), pc('\n');
}
signed main() {
//	cerr << &nd - &st;
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = rd();
	int T = rd();
	while (T --) {
		MAIN();
	}
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/
