#include <bits/stdc++.h>
#define il inline

using namespace std;

template <typename T> il void chkmin(T &x, T y) {x = min(x, y);}
template <typename T> il void chkmax(T &x, T y) {x = max(x, y);}
const int N = 2e5 + 5;
const int Inf = 2e9;
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

int n, k;
struct Node {
	int u, v;
}e[N];
vector <int> G[N];

int bu, bv, U, V;

vector <int> E[2];
il void dfs2(int x, int fth, int o) {
	E[o].push_back(x);
	for(auto v : G[x]) {
		if(v == fth) continue;
		if(x == bu && v == bv) continue;
		if(x == bv && v == bu) continue;
		dfs2(v, x, o);
	}
}

int mx[N], cnt[N];
il void dfs4(int x, int fth) {
	mx[x] = 0;
	for(auto v : G[x]) {
		if(v == fth) continue;
		if(x == bu && v == bv) continue;
		if(x == bv && v == bu) continue;
		dfs4(v, x);
		chkmax(mx[x], mx[v] + 1);
	}
	cnt[mx[x]]++;
}

il void solve() {
	for(int i = 1; i <= n; i++) G[i].clear();
	fin >> n >> k;
	for(int i = 1; i < n; i++) {
		int u, v; fin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		e[i] = {u, v};
	}
	int ans = Inf;
	for(int i = 1; i < n; i++) {
		bu = U = e[i].u, bv = V = e[i].v;
		E[0].clear(), E[1].clear();
		dfs2(U, 0, 0), dfs2(V, 0, 1);
		for(int x : E[0]) for(int y : E[1]) {
			for(int j = 1; j <= n; j++) cnt[j] = mx[j] = 0;
			dfs4(x, 0), dfs4(y, 0);
			int flg = 0;
			for(int i = n, s = 0; i >= 0; i--) {
				s += cnt[i];
				if(s > k) {chkmin(ans, i + 1); flg = 1; break ;}
			}
			if(flg == 0) chkmin(ans, 0);		
		}
	}
	fout << ans << '\n';
	
}

il void main() {
	fin >> Id >> T;
	while(T--) solve();
}
}
il void File() {freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);}
bool End;
il void Usd() {cerr << (&Beg - &End) / 1024.0 / 1024.0 << "MB " << (double)clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";}
signed main() {
	File();
	My_Space::main();
	Usd(); return 0;
}

