//Finish t3,244pts,can give me a wc? 
#include <bits/stdc++.h>
#define pb push_back

using namespace std;

inline int read();
void write(int);
void writeln(int);

const int N = 15, inf = 1e9;
int c, t, n, k, ans, dep[N], fa[N], d[N];
bool vis[N];
vector <int> G[N];
void dfs(int u, int f) {
	dep[u] = dep[f] + 1, fa[u] = f;
	for(auto v : G[u]) if(v != f) dfs(v, u);
}
int lca(int u, int v) {
	while(dep[u] != dep[v]) { if(dep[u] < dep[v]) swap(u, v); u = fa[u]; }
	while(u != v) u = fa[u], v = fa[v]; return u;
}
int js() {
	int res = 0;
	dfs(1, 0);
	for(int i = 1; i <= n; i++) d[i] = inf;
	for(int i = 1; i <= n; i++) if(vis[i]) {
		d[i] = 0;
		for(int j = 1; j <= n; j++) if(!vis[j])
			d[i] = min(d[j], dep[i] + dep[j] - 2 * lca(i, j));
	}
//	for(int i = 1; i <= n; i++) if(vis[i]) {
//		d[i] = 0;
//		for(int j = 1; j <= n; j++) if(!vis[j])
//			d[j] = min(d[j], dep[i] + dep[j] - 2 * lca(i, j));
//	}
	for(int i = 1; i <= n; i++) res = max(res, d[i]);
	return res;
}

signed main() {

	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	c = read(), t = read();
	while(t--) {
		n = read(), k = read(), ans = inf;
		for(int i = 1; i < n; i++) {
			int u = read(), v = read();
			G[u].pb(v), G[v].pb(u);
		}
//		if(n == 3 || n == 5 || k > n / 2) { puts("1"); continue; }
		for(int i = 0; i < (1 << n); i++) {
			int op = 0, cnt = 0; bool fl = 0;
			memset(vis, 0, sizeof(vis)), memset(dep, 0, sizeof(dep)), memset(fa, 0, sizeof(fa));
			for(int j = 1; j <= n; j++) 
				if((i >> j - 1) & 1) {
					for(auto v : G[j]) if(vis[v]) { fl = 1; break; }
					if(!fl) cnt++;
				}
			if(op == k && cnt == 2) ans = min(ans, js());
		}
		printf("%d\n", ans);
	}

	return 0;

}

inline int read() {
	int res = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') f = (ch == '-' ? -1 : f), ch = getchar();
	while(ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return res * f;
}

void write(int x) {
	if(x < 0) putchar('-'), x = -x;
	static int sta[35]; int top = 0;
	do { sta[++top] = x % 10, x /= 10; } while(x);
	while(top) putchar(sta[--top] ^ 48);
}

void writeln(int x) {
	write(x);
	putchar('\n');
}

