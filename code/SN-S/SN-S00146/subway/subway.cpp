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
const int N = 505, M = 5e5 + 10, K = 2e5 + 5;
int C, n, m, dd, qq;
int a[M];
struct edge {
	int y, w;
};
vector<edge> G[N + M]; 
int dis[N][N], vis[M + N], d[M + N];
struct node {
	int x, d;
	il bool operator < (const node & c) const {
		return d > c.d;
	}
};
priority_queue<node> q;
il void dijkstra(int S) {
//	cout << "DIJ " << S << ":\n";
	for (int i = 1; i <= n + m; i++) d[i] = INF, vis[i] = 0;
	d[S] = 0; q.push({S, 0});
	while (!q.empty()) {
		node f = q.top(); q.pop();
		if (vis[f.x]) continue;
		vis[f.x] = 1;
		for (edge i : G[f.x]) {
			if (d[i.y] > d[f.x] + i.w) {
				d[i.y] = d[f.x] + i.w;
				q.push({i.y, d[i.y]});
			}
		}
	}
//	cout << " d: "; for (int i = 1; i <= n + m; i++) cout << d[i] << " "; cout << "\n";
	for (int i = 1; i <= n; i++) 
		dis[S - m][i] = d[m + i];
//	cout << " dis "; for (int i = 1; i <= n; i++) cout << dis[S - m][i] << " "; cout << "\n";
}
namespace Solve1 {
	int dis[N][N], vis[M + N], d[M + N];
	queue<int> q;
	il void bfs(int S) {
		for (int i = 1; i <= n + m; i++) d[i] = INF, vis[i] = 0;
		d[S] = 0, vis[S] = 1;
		q.push(S);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (edge i : G[x]) {
				if (!vis[i.y]) {
					d[i.y] = d[x] + i.w;
					vis[i.y] = 1;
					q.push(i.y);
				}
			}
		}
		for (int i = 1; i <= n; i++) 
			dis[S - m][i] = d[m + i];
	}
	il int solve1() {
//		cerr << "Run\n";
		for (int i = 1; i <= n; i++) 
			bfs(m + i);
		while (qq--) {
			int x = read(), y = read();
			int ans = INF;
			for (edge i : G[x]) 
				for (edge j : G[y]) 
					ans = min(ans, i.w + j.w + dis[i.y - m][j.y - m]); 
			ans += a[x] + a[y];
			write(ans);
		}
		return 0;
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	freopen("subway5.in", "r", stdin);
//	freopen("mine.out", "w", stdout);
//	system("fc subway5.ans mine.out"); return 0;
	C = read(), n = read(), m = read(), dd = read(), qq = read();
	for (int i = 1; i <= m; i++) a[i] = read();
	for (int i = 1; i <= n; i++) {
		int kk = read();
		while (kk--) {
			int x = read(), w = read();
			G[x].push_back({m + i, w});
			G[m + i].push_back({x, w});
		}
	}
//	for (int i = 1; i <= n + m; i++) {
//		cout << "G " << i << ": ";
//		for (edge j : G[i]) cout << j.y << "|" << j.w << " ";
//		cout << "\n";
//	}
	if (16 <= C && C <= 19) return Solve1::solve1();
	for (int i = 1; i <= n; i++) 
		dijkstra(m + i);
	while (qq--) {
		int x = read(), y = read();
		int ans = INF;
		for (edge i : G[x]) 
			for (edge j : G[y]) 
				ans = min(ans, i.w + j.w + dis[i.y - m][j.y - m]); 
		ans += a[x] + a[y];
		write(ans);
	}
//	for (int i = 1; i <= qq; i++) {
//		int x = read(), y = read();
//		q[i] = {x, y, 0};
//		p[++tot] = x, p[++tot] = y;
//	}
//	sort(p + 1, p + 1 + tot);
//	tot = unique(p + 1, p + 1 + tot) - p - 1;
//	for (int i = 1; i <= tot; i++) 
//		id[p[i]] = i;
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
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
