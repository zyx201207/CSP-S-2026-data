#include <bits/stdc++.h>
using ll = long long;
const int SZ = 1 << 16;
#define fu(i, a, b) for (auto i = a; i <= b; ++i) 
#define fd(i, a, b) for (auto i = a; i >= b; --i) 
#define fr(i, a, b) for (auto i = a; i < b; ++i) 
#define I inline 
char buf[SZ], cuf[SZ];
int is = SZ, os;
I char ge() { return !(is ^ SZ) && (fread(buf, 1, SZ, stdin), is = 0), buf[is ++]; } 
I bool Flush() { return fwrite(cuf, 1, os, stdout), os = 0; } 
I void pu(char c) { !(os ^ SZ) && Flush(), cuf[os ++] = c;  } 
template <typename T> I void read(T &x) { 
    char c = ge(); bool f = false; x = 0;
    while (c < '0' || '9' < c) f = c == '-', c = ge();
    while ('0' <= c && c <= '9') x = x * 10 + (c ^ 48), c = ge();
    f && (x = -x);
} 
template <typename T> I void write(T x) {
    char tmp[25]; int l = 0;
    if (x == 0) { pu('0'); return ; }
    if (x < 0) x = -x, pu('-');
    while (x) tmp[l ++] = x % 10 + '0', x /= 10;
    while (l) pu(tmp[-- l]);
}
template <typename T> I void Write(T x, bool f = true) { write(x); pu(f ? '\n' : ' '); }
template <typename T> I T max(T a, T b) { return a > b ? a : b; }
template <typename T> I T min(T a, T b) { return a < b ? a : b; }
template <typename T> I void fmax(T &a, T b) { a = a > b ? a : b; }
template <typename T> I void fmin(T &a, T b) { a = a < b ? a : b; }

const int N = 2e6 + 5, SN = 305;
int f[SN][SN], cid, n;
ll x[N], g[SN][SN], d;

I void TaskBF() {
	memset(f, 0x3f, sizeof f), memset(g, 0, sizeof g);
	fu (i, 1, n) fu (j, 1, n) if (llabs(x[i] - x[j]) <= d) f[i][j] = 1, g[i][j] = 1;

	fu (k, 1, n) fu (i, 1, n) fu (j, 1, n) if (f[i][k] + f[k][j] <= f[i][j]) {
		if (f[i][k] + f[k][j] == f[i][j]) g[i][j] += g[i][k] * g[k][j];
		else f[i][j] = f[i][k] + f[k][j], g[i][j] = g[i][k] * g[k][j];
	}

	int cnt = 0;
	fu (i, 1, n) fu (j, i + 1, n) if (g[i][j] == 2) ++ cnt;
	Write(cnt);
}

I void solve() {
	read(n), read(d);
	fu (i, 1, n) read(x[i]);

	if (cid <= 6) TaskBF();
	else {
		
	}
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

	read(cid); int T; read(T);
	while (T --) solve();
    return Flush(), 0;
}