#include <bits/stdc++.h>
#define il inline
#define int long long

using namespace std;

bool Beg;
namespace Zctf1088 {
namespace IO {
	const int bufsz = 1 << 20;
	char ibuf[bufsz], *p1 = ibuf, *p2 = ibuf;
	#define getchar() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, bufsz, stdin), p1 == p2) ? EOF : *p1++)
	il int read() {
		int x = 0; char ch = getchar(); bool t = 0;
		while (ch < '0' || ch > '9') {t ^= ch == '-'; ch = getchar();}
		while (ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
		return t ? -x : x;
	}
	char obuf[bufsz], *p3 = obuf, stk[50];
	#define flush() (fwrite(obuf, 1, p3 - obuf, stdout), p3 = obuf)
	#define putchar(ch) (p3 == obuf + bufsz && flush(), *p3++ = (ch))
	il void write(int x, bool t = 0) {
		int top = 0;
		x < 0 ? putchar('-'), x = -x : 0;
		do {stk[++top] = x % 10 | 48; x /= 10;} while (x);
		while (top) putchar(stk[top--]);
		t ? putchar(' ') : putchar('\n');
	}
	struct FL {
		~FL() {flush();}
	} fl;
}
using IO::read; using IO::write;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e6 + 10;
int C, n, d, a[N];
int f[N], g[N];
il int solve1() {
	int res = 0;
	for (int l = 1; l < n; l++) {
		for (int i = 1; i <= n; i++) f[i] = INF, g[i] = 0;
		f[l] = 0, g[l] = 1;
		for (int i = l + 1; i <= n; i++) {
			for (int j = l; j < i; j++) {
				if (a[i] - a[j] <= d) {
					if (f[j] + 1 < f[i]) {
						f[i] = f[j] + 1;
						g[i] = g[j];
					} else if (f[j] + 1 == f[i]) {
						g[i] += g[j];
					}
				}
			}
			res += (g[i] == 2);
//			if (g[i] == 2) cout << "! " << l << " " << i << "\n";
		}
//		cout << l << ":\n";
//		cout << " F "; for (int i = 1; i <= n; i++) cout << f[i] << " "; cout << "\n";
//		cout << " G "; for (int i = 1; i <= n; i++) cout << g[i] << " "; cout << "\n";
	}
	write(res);
	return 0;
}
int q[N], head, tail, s[N];
il int solve() {
	n = read(), d = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	if (C <= 6) return solve1();
	int res = 0;
	for (int l = 1; l < n; l++) {
		for (int i = 0; i <= n; i++) f[i] = INF, g[i] = 0;
		f[l] = 0, g[l] = 1, s[l] = 1;
		head = 1, tail = 0;
		q[++tail] = l;
		for (int i = l + 1; i <= n; i++) {
			while (head <= tail && a[q[head]] < a[i] - d) head++;
			if (head > tail) break;
			int L = head, R = tail, p = -1;
			while (L <= R) {
				int mid = (L + R) >> 1;
				if (f[q[mid]] == f[q[head]]) {
					p = mid;
					L = mid + 1;
				} else R = mid - 1;
			}
			f[i] = f[q[head]] + 1;
			g[i] = s[p] - s[head - 1];
			if (g[i] > 2) continue;
			while (head <= tail && f[q[tail]] > f[i]) tail--;
			q[++tail] = i;
			s[tail] = s[tail - 1] + g[i];
			res += (g[i] == 2);
//			if (g[i] == 2) cout << "! " << l << " " << i << "\n";
		}
//		cout << l << ":\n";
//		cout << " F "; for (int i = 1; i <= n; i++) cout << f[i] << " "; cout << "\n";
//		cout << " G "; for (int i = 1; i <= n; i++) cout << g[i] << " "; cout << "\n";
	}
	write(res);
	return 0;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
//	freopen("migrate3.in", "r", stdin);
//	freopen("mine.out", "w", stdout);
//	system("fc migrate3.ans mine.out"); return 0;
	C = read(); int qq = read();
	while (qq--) solve();
	return 0;
}}
bool End;
il void Usd() {cerr << "\nUsd: " << (&Beg - &End) / 1024.0 / 1024.0 << "MB " << (double)clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";}
signed main() {
	Zctf1088::main();
//	Usd();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
6 3
0 1 2 3 4 7

*/
