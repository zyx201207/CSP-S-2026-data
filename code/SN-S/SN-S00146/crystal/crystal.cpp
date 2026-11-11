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
const int N = 5e5 + 10, M = 22;
int n, m, a[N], s[N];
int mx[N][M], Log2[N];
il void initST() {
	for (int i = 2; i <= n; i++) Log2[i] = Log2[i / 2] + 1;
	for (int i = 1; i <= n; i++) mx[i][0] = a[i];
	for (int j = 1; j <= Log2[n]; j++) 
		for (int i = 1; i + (1 << j) - 1 <= n; i++) 
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
}
il int getmx(int l, int r) {
	int s = Log2[r - l + 1];
	return max(mx[l][s], mx[r - (1 << s) + 1][s]);
}
il bool check(int len) {
	for (int i = 1; i + len - 1 <= n; i++) {
		int val = getmx(i, i + len - 1);
		if (len * val - (s[i + len - 1] - s[i - 1]) <= m) 
			return true;
	}
	return false;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	freopen("crystal4.in", "r", stdin);
//	freopen("mine.out", "w", stdout);
//	system("fc crystal4.ans mine.out"); return 0;
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) 
		s[i] = s[i - 1] + a[i];
	initST();
	int L = 1, R = n, res = 1;
	while (L <= R) {
		int mid = (L + R) >> 1;
		if (check(mid)) {
			res = mid;
			L = mid + 1;
		} else R = mid - 1;
	}
	write(res);
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
5 5
1 2 4 8 9

*/
