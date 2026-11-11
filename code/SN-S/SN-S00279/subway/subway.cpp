#include <bits/stdc++.h>
#define il inline
#define int long long

using namespace std;

template <typename T> il void chkmin(T &x, T y) {x = min(x, y);}
template <typename T> il void chkmax(T &x, T y) {x = max(x, y);}
const int N = 5e5 + 5, M = 500 + 5;
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

int c, n, m, d, q;
int w[N];
#define pii array<int, 2>
vector <pii> V[N];

int dis[M][M];

il void main() {
	fin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) fin >> w[i];
	for(int i = 1; i <= n; i++) {
		int k; fin >> k;
		for(int j = 1; j <= k; j++) {
			int x, t; fin >> x >> t;
			V[x].push_back({i, t});
		}
	}
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(i != j) dis[i][j] = Inf;
	for(int x = 1; x <= m; x++) {
		int c = V[x].size();
		for(int j = 0; j < c; j++) for(int k = j + 1; k < c; k++) {
			pii a = V[x][j], b = V[x][k];
			chkmin(dis[a[0]][b[0]], a[1] + b[1]);
			chkmin(dis[b[0]][a[0]], a[1] + b[1]);
		}
	}
	for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) 
		chkmin(dis[i][j], dis[i][k] + dis[k][j]);
	while(q--) {
		int x, y; fin >> x >> y;
		int ans = Inf;
		for(auto a : V[x]) for(auto b : V[y]) chkmin(ans, a[1] + b[1] + dis[a[0]][b[0]]);
		ans += w[x] + w[y];
		fout << ans << '\n';
	}
}
}
il void File() {freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);}
bool End;
il void Usd() {cerr << (&Beg - &End) / 1024.0 / 1024.0 << "MB " << (double)clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";}
signed main() {
	File();
	My_Space::main();
	Usd(); return 0;
}

