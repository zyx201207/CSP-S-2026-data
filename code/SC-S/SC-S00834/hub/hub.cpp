#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
int cid, T, n, q, head[MAXN], k, cnt, flag, m, f[MAXN];
struct edge{
	int v, nxt;
}e[MAXN << 1];
void adde(int u, int v) {
	e[++ k] = {v, head[u]}, head[u] = k;
	e[++ k] = {u, head[v]}, head[v] = k;
}
struct tree{
	int mx, tag;
}t[MAXN << 2];
void push(int rt, int res) {
	t[rt].mx += res;
	t[rt].tag += res;
}
void pushdown(int rt) {
	if(t[rt].tag != 0) {
		push(rt << 1, t[rt].tag);
		push(rt << 1 | 1, t[rt].tag);
		t[rt].tag = 0;
	}
}
void build(int l, int r, int rt) {
	t[rt] = {0, 0};
	if(l == r) return;
	int m = l + r >> 1;
	build(l, m, rt << 1);
	build(m + 1, r, rt << 1 | 1);
}
void update(int l, int r, int p, int res, int rt) {
	if(l == r) {
		t[rt].mx = res;
		return;
	}
	int m = l + r >> 1;pushdown(rt);
	if(p <= m) update(l, m, p, res, rt << 1);
	else update(m + 1, r, p, res, rt << 1 | 1);
	t[rt].mx = max(t[rt << 1].mx, t[rt << 1 | 1].mx);
}
void modify(int l, int r, int L, int R, int res, int rt) {
	if(L <= l && r <= R) return push(rt, res);
	int m = l + r >> 1;pushdown(rt);
	if(L <= m) modify(l, m, L, R, res, rt << 1);
	if(m < R) modify(m + 1, r, L, R, res, rt << 1 | 1);
	t[rt].mx = max(t[rt << 1].mx, t[rt << 1 | 1].mx);
}
int read() {
	int x = 0;char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
	return x;
}
void dfs1(int u, int fa, int x) {
	f[u] = 0;
	for(int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(v != fa) dfs1(v, u, x), f[u] = max(f[u], f[v]);
	}
	++ f[u];
	if(f[u] > x) ++ cnt;
}
void dfs2(int u, int fa, int x) {
	if(flag) return;
	int mx = 0, smx = 0;
	for(int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(v != fa) {
			if(f[v] > mx) smx = mx, mx = f[v];
			else if(smx < f[v]) smx = f[v];
		}
	}
	for(int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(v != fa) {
			if(fa) {
				++ m;
				update(1, n, m, (f[v] == mx ? smx : mx), 1);
				modify(1, n, m / 2, m, 1, 1);
				if(f[u] > x) -- cnt;
			}
			if(t[1].mx <= x) {
				if(cnt <= q) {
					flag = 1;
					return;
				}
				dfs2(v, u, x);
			}
			if(flag) return;
			if(fa) {
				if(f[u] > x) ++ cnt;
				modify(1, n, m / 2, m, -1, 1);
				update(1, n, m, 0, 1);
				-- m;
			}
		}
	}
}
bool chk(int u, int x) {
	cnt = flag = m = 0;
	dfs1(u, 0, x);
	if(cnt <= q) return 1;
	build(1, n, 1);
	dfs2(u, 0, x);
	return flag;
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cid = read(), T = read();
	while(T --) {
		n = read(), q = read();k = 0;
		for(int i = 1; i <= n; i ++) head[i] = 0;
		for(int i = 1, u, v; i < n; i ++) u = read(), v = read(), adde(u, v);
		int l = 0, r = n, mid;
		while(l <= r) {
			mid = l + r >> 1;
			int fl = 0;
			for(int i = 1; i <= n; i ++) if(chk(i, mid)) {
				fl = 1;
				break;
			}
			if(!fl) l = mid + 1;
			else r = mid - 1;
		}
		printf("%d\n", r + 1);
	}
}