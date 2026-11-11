// CSP 2026 rp++
// 多测清空
// 保证 sumn 手动清空
// 四倍线段树 
// 滚动数组清空
// long long 要不要开
// 开了会不会 MLE
// 代码过编译
// freopen 写对
// 文件名写对 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define repp(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define perr(i, a, b) for (int i = (a); i > (b); i--)
#define endl '\n'
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
inline int read(){
	int res = 0, f = 1; char c = getchar();
	while (!isdigit(c)){ if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)){ res = res * 10 + c - '0'; c = getchar(); }
	return res * f;
}

// Definitions.

const int N = 5e5 + 10;
int n, k, ff[N], sz[N], dep[N], top[N], dfn[N], wc[N], tc, ans = 1e18, fa[N], p[N];
vector<int> g[N];
void dfs1(int x, int fa){
	dep[x] = dep[fa] + 1;
	sz[x] = 1;
	ff[x] = fa;
	repp(i, 0, g[x].size()){
		int y = g[x][i];
		if (y == fa) continue;
		dfs1(y, x);
		sz[x] += sz[y];
		if (sz[y] > sz[wc[x]]) wc[x] = y;
	}
}
void dfs2(int x, int fa, int tp){
	top[x] = tp;
	dfn[x] = ++tc;
	if (wc[x] != 0){
		dfs2(wc[x], x, tp);
		repp(i, 0, g[x].size()){
			int y = g[x][i];
			if (y == fa || y == wc[x]) continue;
			dfs2(y, x, y);
		}
	}
}
int lca(int u, int v){
	while (top[u] != top[v]){
		if (dfn[u] < dfn[v]) swap(u, v);
		u = ff[top[u]];
	}
	if (dep[u] < dep[v]) return u;
	return v;
}
int getd(int u, int v){
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}
int find(int x){
	if (fa[x] == x) return fa[x];
	return fa[x] = find(fa[x]);
}
void merge(int x, int y){
	fa[find(x)] = find(y);
}
void dfs3(int x, int fa){
	repp(i, 0, g[x].size()){
		int y = g[x][i];
		if (y == fa) continue;
		dfs3(y, x);
		if (p[x] && p[y]) merge(x, y);
	}
}
void solve(int cas){
	// 多测不清空，亲人两行泪
	rep(i, 1, n) g[i].clear();
	rep(i, 1, n) ff[i] = sz[i] = dep[i] = top[i] = dfn[i] = wc[i] = fa[i] = p[i] = 0;
	tc = 1; ans = 1e18;
	n = read(), k = read();
	rep(i, 1, n - 1){
		int u = read(), v = read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 0, 1);
	rep(bs, 1, (1 << n) - 1){
		int cc = 0;
		rep(i, 1, n) p[i] = (bs >> (i - 1)) & 1, cc += p[i];
		if (cc != k) continue;
		rep(i, 1, n) fa[i] = i;
		dfs3(1, 0);
		int cnt = 0;
		rep(i, 1, n) 
			if (p[i] && find(i) == i)
				cnt++;
		if (cnt > 2) continue;
		int res = 0;
		rep(i, 1, n){
			int dd = 1e18;
			rep(j, 1, n) 
				if (p[j])
					dd = min(dd, getd(i, j));
			res = max(res, dd);
//			printf("%lld %lld %lld\n", i, dd, res);
		}
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c = read(), t = read();
	while (t--) solve(c);
	return 0;
}

/*

1 1
8 10
1 2
1 3
2 4
2 5
5 6
5 7
5 8

0 2
5 2
1 2
2 3
3 4
4 5

0 1
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

*/
