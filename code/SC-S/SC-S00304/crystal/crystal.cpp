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

const int N = 5e5 + 5;
int n;
ll a[N], m, s[N];

I ll calc(int l, int r) {
	int len = r - l + 1; ll truth = s[r] - s[l - 1];
	return a[r] * len - truth;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	read(n), read(m);
	fu (i, 1, n) read(a[i]);
	std::sort(a + 1, a + n + 1);
	fu (i, 1, n) s[i] = s[i - 1] + a[i]; 

	int ans = 0;
	fu (i, 1, n) {
		int l = 1, r = i;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (calc(mid, i) <= m) r = mid;
			else l = mid + 1;
		}
		if (calc(l, i) <= m) fmax(ans, i - l + 1);
	} Write(ans); 
    return Flush(), 0;
}