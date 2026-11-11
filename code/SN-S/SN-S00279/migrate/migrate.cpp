#include <bits/stdc++.h>
#define il inline
#define int long long

using namespace std;

template <typename T> il void chkmin(T &x, T y) {x = min(x, y);}
template <typename T> il void chkmax(T &x, T y) {x = max(x, y);}
const int N = 2e6 + 5;
const int Inf = 1e18;
bool Beg;
namespace My_Space {
struct IO {
	static const int Size = (1 << 21);
	char buf[1 << 21], *p1 = buf, *p2 = buf; int st[105], Top;
	~IO() {clear();}
	il void clear() {fwrite(buf, 1, Top, stdout); Top = 0;}
	il char gc() {return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, Size, stdin), p1 == p2) ? EOF : *p1++;}
	il void pc(const char c) {Size == Top && (clear(), 0); buf[Top++] = c;}
	template <typename T> il IO &operator >> (T &x) {
		x = 0; bool f = 0; char c = gc();
		while(!isdigit(c)) f |= (c == '-'), c = gc();
		while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
		f ? x = -x : 0;
		return *this;
	}
	il IO &operator << (const char c) {pc(c); return *this;}
	il IO &operator << (const char *s) {for(int i = 0; s[i]; i++) pc(s[i]); return *this;}
	template <typename T> il IO &operator << (T x) {
		if(x < 0) x = -x, pc('-');
		do st[++st[0]] = x % 10, x /= 10; while(x);
		while(st[0]) pc('0' + st[st[0]--]);
		return *this;
	}
}fin, fout;

int Id, T;
int n, d, a[N];
int nxt[N];
int f[N][3];
/*
0 - 1 1
1 - 2 1
2 - * 2
*/

il void solve() {
	for(int i = 1; i <= n; i++) f[i][0] = f[i][1] = f[i][2] = 0;
	fin >> n >> d;
	for(int i = 1; i <= n; i++) fin >> a[i];
	for(int i = n, j = n; i >= 1; i--) {
		while(a[j] - a[i] > d) j--;
		nxt[i] = j;
	}
	for(int i = n; i >= 1; i--) {
		if(nxt[i] == i) continue;
		//f[i][0]
		int p = nxt[i];
		int x = nxt[p], y = nxt[p - 1];
		if(y < x - 1) f[i][0] += f[p][0];
		else if(y == x - 1) f[i][0] += f[p][1];
		else if(y == x) f[i][0] += f[p][2];
		f[i][0] += y - p;
		if(p - 2 >= i) {
			int z = nxt[p - 2];
			if(z == x) f[i][0] = 0;
			else f[i][0] -= z - p;
		}
		//f[i][1]
		if(y < x - 1) f[i][1] = f[p][0];
		else if(y == x - 1) f[i][1] = f[p][1];
		//f[i][2]
		f[i][2] += x - p;
		if(y <= x - 1) f[i][2] += f[p][2];
		f[i][2] -= y - p;
	}
	int ans = 0;
	for(int i = n; i >= 1; i--) ans += f[i][0];
	fout << ans << '\n';
}

il void main() {
	fin >> Id >> T;
	while(T--) solve();
}
}
il void File() {freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);}
bool End;
il void Usd() {cerr << (&Beg - &End) / 1024.0 / 1024.0 << "MB " << (double)clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";}
signed main() {
	File();
	My_Space::main();
	Usd(); return 0;
}

