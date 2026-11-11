#include <bits/stdc++.h>
#define il inline
#define int long long

using namespace std;

template <typename T> il void chkmin(T &x, T y) {x = min(x, y);}
template <typename T> il void chkmax(T &x, T y) {x = max(x, y);}
const int N = 5e5 + 5;
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

int n, m, a[N];

il void main() {
	fin >> n >> m;
	for(int i = 1; i <= n; i++) fin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 1, l = 1, tar = a[1], sum = 0;
	for(int r = 2; r <= n; r++) {
		sum += (r - l) * (a[r] - tar); tar = a[r];
		while(sum > m) {
			sum -= (tar - a[l]); l++;
		}
		chkmax(ans, r - l + 1);
	}
	fout << ans << '\n'; 
}
}
il void File() {freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);}
bool End;
il void Usd() {cerr << (&Beg - &End) / 1024.0 / 1024.0 << "MB " << (double)clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";}
signed main() {
	File();
	My_Space::main();
	Usd(); return 0;
}

