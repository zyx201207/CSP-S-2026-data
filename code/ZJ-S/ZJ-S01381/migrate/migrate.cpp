#include <bits/stdc++.h>

using namespace std;

#define ll long long 

namespace IO
{
#define gc getchar
#define pc putchar
	template<typename T> inline void read(T& x)
	{
		x = 0; char ch = gc(); int w = 1; 
		while (!isdigit(ch)) { if (ch == 0x2d) { w = 0; } ch = gc(); }
		while (isdigit(ch)) { x = x * 0xa + ch - 0x30; ch = gc(); }
		x = w ? x : -x; 
	}
	template<typename T> inline void write(T x)
	{
		if (x < 0) { pc(0x2d); x = -x; }
		if (x > 9) { write(x / 0xa); }
		pc(x % 0xa + 0x30);
	}
} using namespace IO;

const int N = 2e6 + 5; 
int n; ll d, x[N], ans;
int cnt, bel[N], bl[N]; 
int ql[N], qr[N], top;

inline void work() 
{
	read(n); read(d); for (int i = 1; i <= n; ++i) { read(x[i]); } bl[cnt = 1] = 1;
	for (int i = 1; i <= n; ++i) { if (i == 1 || x[i] - x[i - 1] <= d) { bel[i] = cnt; } else { bel[i] = ++cnt; bl[cnt] = i; } } bl[cnt + 1] = n + 1; 
	int L, R, l, r, mid, p1, p2; 
	for (int o = 1; o <= cnt; ++o) // o-th block
	{
//		cerr << ans << endl; //
		if (bl[o + 1] - bl[o] <= 2) { continue; }
		L = bl[o], R = bl[o + 1] - 1; top = 0;
		for (int i = L; i < R; ++i)
		{
			l = i; r = R; while (l < r) { mid = (l + r + 1) / 2; if (x[mid] - x[i] <= d) { l = mid; } else { r = mid - 1; } } p1 = l; 
			if (p1 == R) { break; }
			l = i; r = p1 + 1; while (l < r) { mid = (l + r) / 2; if (x[p1 + 1] - x[mid] <= d) { r = mid; } else { l = mid + 1; } } p2 = r;
//			cerr << i << ' ' << p1 << ' ' << p2 << endl; //
			if (p1 - p2 == 1) { ++top; ql[top] = p2 - 1; qr[top] = p1 + 1; i = p2 - 1; }
		}
		if (!top) { continue; }
		if (top == 1) { ans+= 1ll * (ql[1] - L + 1) * (R - qr[1] + 1); continue; }
		for (int i = 1; i <= top; ++i) {
			if (i == 1) { ans+= 1ll * (ql[i] - L + 1) * (qr[i + 1] - qr[i]); }
			else if (i == top) { ans+= 1ll * (ql[i] - ql[i - 1]) * (R - qr[i] + 1); }
			else { ans+= 1ll * (ql[i] - ql[i - 1]) * (qr[i + 1] - qr[i]); }
		}
	}
	write(ans); putchar(0xa);
	ans = 0; 
}

int main()
{
	freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
	int c, t; read(c); read(t); while (t--) { work(); }
	return 0; 
}
/*
0 1
6 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000
(1)

0 1
8 3
0 1 2 4 8 10 11 13
(2)

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
*/
