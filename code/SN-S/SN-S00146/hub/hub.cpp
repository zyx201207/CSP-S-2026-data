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
const int N = 1e6 + 10;
int C, n, kk;
vector<int> G[N];
namespace Solve1 {
	int dep[N], dfn[N], id[N << 1], tim;
	il void dfs(int x, int fa) {
		dep[x] = dep[fa] + 1;
		id[++tim] = x;
		dfn[x] = tim;
		for (int y : G[x]) {
			if (y == fa) continue;
			dfs(y, x);
			id[++tim] = x;
		}
	}
	int mn[N << 1][22], Log2[N << 1];
	il void initST() {
		for (int i = 2; i <= tim; i++) Log2[i] = Log2[i / 2] + 1;
		for (int i = 1; i <= tim; i++) mn[i][0] = dfn[id[i]]; 
		for (int j = 1; j <= Log2[tim]; j++) 
			for (int i = 1; i + (1 << j) - 1 <= tim; i++) 
				mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
	}
	il int getlca(int x, int y) {
		if (dfn[x] > dfn[y]) swap(x, y);
		int s = Log2[dfn[y] - dfn[x] + 1];
		return id[min(mn[dfn[x]][s], mn[dfn[y] - (1 << s) + 1][s])];
	}
	il int getdis(int x, int y) {
		return dep[x] + dep[y] - 2 * dep[getlca(x, y)];
	}
	int vis[N], col, tag[N];
	il void dfs1(int x) {
		vis[x] = col;
		for (int y : G[x]) 
			if (tag[y] && !vis[y]) dfs1(y);
	}
	il int solve1() {
		tim = 0;
		dfs(1, 0);
		initST();
		int res = INF;
		for (int s = 0; s < (1 << n); s++) {
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				tag[i] = ((s >> (i - 1)) & 1);
				vis[i] = 0;
				cnt += tag[i];
			}
			if (cnt != kk) continue;
			col = 0;
			for (int i = 1; i <= n; i++) {
				if (tag[i] && !vis[i]) {
					col++;
					dfs1(i);
				}
			}
			if (col > 2) continue;
			int mx = 0;
			for (int i = 1; i <= n; i++) if (!tag[i]) {
				int mn = INF;
				for (int j = 1; j <= n; j++) if (tag[j]) 
					mn = min(mn, getdis(i, j));
				mx = max(mx, mn);
			}
			res = min(res, mx);
	//		cout << "S " << s << ": " << mx << "\n";
		}
		write(res);
		return 0;
	}
}
int U, col[N];
il void dfs(int x, int c) {
	col[x] = c;
	for (int y : G[x]) {
		if (y == U || col[y]) continue;
		dfs(y, c);
	}
}
int X, Y, dep[N], fa[N];
il void dfs1(int x, int fa) {
	dep[x] = dep[fa] + 1;
	X = dep[X] > dep[x] ? X : x;
	for (int y : G[x]) {
		if (y == fa || col[y] != col[x]) continue;
		dfs1(y, x);
	}
}
il void dfs2(int x, int fr) {
	fa[x] = fr;
	dep[x] = dep[fr] + 1;
	Y = dep[Y] > dep[x] ? Y : x;
	for (int y : G[x]) {
		if (y == fr || col[y] != col[x]) continue;
		dfs2(y, x);
	}
}
int mx[N];
il void dfs3(int x, int fr) {
//	cerr << x << "\n"; 
	mx[x] = 0;
	for (int y : G[x]) {
		if (y == fr || col[y] != col[x]) continue;
		dfs3(y, x);
		mx[x] = max(mx[x], mx[y] + 1);
	}
}
struct node {
	int x, val;
	il bool operator < (const node & c) const {
		return val < c.val; 
	}
};
priority_queue<node> q;
int vis[N];
il int calc(int x, int kk) {
	dfs1(x, 0);
	dfs2(X, 0);
	int len = dep[Y] / 2;
	int p = Y;
	while (len--) p = fa[p];
	dfs3(p, 0); 
	int cnt = 1;
	for (int i = 1; i <= n; i++) vis[i] = 0;
	while (!q.empty()) {
//	cerr << "Run1 " << q.size() << "\n";
		q.pop();
	}
//	cerr << "Run " << kk << "\n";
	vis[p] = 1;
	for (int y : G[p]) 
		if (col[y] == col[p]) 
			q.push({y, mx[y]});
	while (!q.empty() && cnt < kk) {
		cnt++;
		node f = q.top(); q.pop();
		vis[f.x] = 1;
		for (int y : G[f.x]) {
			if (vis[y] || col[y] != col[p]) continue;
			q.push({y, mx[y]});
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (col[i] != col[p]) continue;
		int fl = vis[i];
		for (int y : G[i]) {
			if (col[y] != col[p]) continue;
			fl &= vis[y];
		}
		if (!fl) res = max(res, mx[i]);
//		cout << " X " << i << " " << fl << "\n";
	}
//	cerr << "res: " << kk << ": " << res << "\n";
//	cerr << " vis: "; for (int i = 1; i <= n; i++) cout << vis[i] << " "; cout << "\n";
//	cerr << " mx : "; for (int i = 1; i <= n; i++) cout << mx[i] << " "; cout << "\n";
	return res;
}
il int solve() {
	n = read(), kk = read();
	for (int i = 1; i <= n; i++) G[i].clear();
	for (int i = 1; i < n; i++) {
		int x = read(), y = read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	if (C <= 3) return Solve1::solve1();
	int res = INF;
	for (int u = 1; u <= n; u++) {
		for (int v : G[u]) {
			if (v < u) continue;
//			cerr << "S " << u << " " << v << " : ";
			for (int i = 1; i <= n; i++) col[i] = 0;
			U = v;
			dfs(u, 1);
			U = u;
			dfs(v, 2);
			int mn = INF;
			for (int k = 1; k < kk; k++) 
				mn = min(mn, max(calc(u, k), calc(v, kk - k)));
//			cerr << mn << "\n";
			res = min(res, mn);
		}
	}
//	cerr << "RES: " << res << "\n";
	write(res);
	return 0;
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
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
1 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

1 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/
