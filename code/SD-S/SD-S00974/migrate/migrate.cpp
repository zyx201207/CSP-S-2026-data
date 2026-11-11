#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define ili inline int
#define ilv inline void
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define fi first
#define se second
typedef vector <int> vi;
typedef vector <pii> vpi;
#define pb push_back

int Mbe;

const int N = 2000005;

int n;
ll d, a[N];
int to[N];
vi T[N];
int st[22][N];
int dep[N];
int df[N], ind;

template <class T> void rd(T &a, int c = 0, int f = 0) {
	while (!isdigit(c = getchar())) f |= c == '-';
	for (a = 0; isdigit(c); c = getchar()) a = (a << 3) + (a << 1) + (c ^ 48);
	f && (a = -a);
}
template <class T> void wrt(T x) {
	if (x > 9) wrt(x / 10);
	putchar(x % 10 ^ 48);
}
void dfs1(int u, int fa) {
	dep[u] = dep[fa] + 1;
	df[u] = ++ind;
	st[0][df[u]] = fa;
	for (auto v : T[u]) {
		dfs1(v, u);
	}
}
ili stq(int l, int r) {
	int k = 31 - __builtin_clz(r - l + 1);
	return max(st[k][l], st[k][r - (1 << k) + 1]);
}
ili lca(int u, int v) {
	if (u == v) return u;
	u = df[u], v = df[v];
	if (u > v) swap(u, v);
	return stq(u + 1, v);
}

struct Info {
	int mn1, ct1, mn2, ct2;
};
inline Info operator+ (Info a, Info b) {
	if (a.mn1 > b.mn1) swap(a, b);
	Info R;
	if (a.mn1 == b.mn1) {
		R.mn1 = a.mn1, R.ct1 = a.ct1 + b.ct1;
		if (a.mn2 == b.mn2) R.mn2 = a.mn2, R.ct2 = a.ct2 + b.ct2;
		else if (a.mn2 < b.mn2) R.mn2 = a.mn2, R.ct2 = a.ct2;
		else R.mn2 = b.mn2, R.ct2 = b.ct2;
	} else {
		R.mn1 = a.mn1, R.ct1 = a.ct1;
		if (a.mn2 == b.mn1) R.mn2 = a.mn2, R.ct2 = a.ct2 + b.ct1;
		else if (a.mn2 < b.mn1) R.mn2 = a.mn2, R.ct2 = a.ct2;
		else R.mn2 = b.mn1, R.ct2 = b.ct1; 
	}
	return R;
}

int tg[N << 2];
Info dat[N << 2];
#define ls (p << 1)
#define rs (p << 1 | 1)
#define M (L + R >> 1)

void build(int p, int L, int R) {
	dat[p] = {0, R - L + 1, 1e9, 0}, tg[p] = 0;
	if (L == R) return;
	build(ls, L, M), build(rs, M + 1, R);
}
ilv pushdown(int p) {
}
//bitset <500> jl[N]; 
int cur[N];
void modify(int p, int l, int r, int x, int id, int L = 1, int R = n) {
	if (l > r) return;
	if (l <= L && r >= R) {
		tg[p] += x;
		dat[p].mn1 += x, dat[p].mn2 += x;
		return;
	}
	if (tg[p]) {
		dat[ls].mn1 += tg[p], dat[ls].mn2 += tg[p], tg[ls] += tg[p];
		dat[rs].mn1 += tg[p], dat[rs].mn2 += tg[p], tg[rs] += tg[p];
		tg[p] = 0;
	}
	if (l <= M) modify(ls, l, r, x, id, L, M);
	if (r > M)  modify(rs, l, r, x, id, M + 1, R);
	dat[p] = dat[ls] + dat[rs];
}

void W(int u, int x) {
	if (u != to[u]) {
		if (u + 1 != to[u]) {
			if (to[to[u] - 1] > to[u]) modify(1, to[u] + 1, to[to[u] - 1] - (to[to[u] - 1] == to[to[u]]), x, u);
			if (to[to[u]] != to[u] && to[to[u]] != to[to[u] - 1]) {
				if (to[to[to[u] - 1]] > to[to[u]]) modify(1, to[to[u]] + 1, to[to[to[u] - 1]] - (to[to[to[u] - 1]] == to[to[to[u]]]), x, u);
			}
			if (dep[to[u]] == dep[to[u] - 1]) modify(1, lca(to[u], to[u] - 1), n, x, u);
			if (u + 2 != to[u]) {
				if (to[to[u] - 2] > to[u]) modify(1, to[u] + 1, to[to[u] - 2] - (to[to[u] - 2] == to[to[u]]), x, u);
				if (dep[to[u]] == dep[to[u] - 2]) modify(1, lca(to[u], to[u] - 2), n, x, u);
			}
		}
	}
}
//void dfs(int p, int L, int R) {
//	if (L == R) {
//		cout << dat[p].mn1 << " ";
//		return;
//	}
//	pushdown(p);
//	dfs(ls, L, M), dfs(rs, M + 1, R);
//}
ll ans;
void dfs2(int u, int fa) {
//	cout << "! " << u << " " << to[u] << endl;
//	dfs(1, 1, n),cout << endl;
	cur[u] = 0;
	W(u, 1);
//	dfs(1, 1, n),cout << endl;
//	cout << dat[1].mn1 << "   " << dat[1].ct1 << "   " << dat[1].mn2 << "   " << dat[1].ct2 << endl;
	if (dat[1].mn1 == 0) {
		if (dat[1].mn2 == 1) ans += dat[1].ct2;
	} else if (dat[1].mn1 == 1) ans += dat[1].ct1;
//	cout << ans << endl;
	for (auto v : T[u]) dfs2(v, u);
	cur[u] = 0;
	W(u, -1);
}

//int cter;

int ader = 0;

void sol() {
//	cerr << ++cter << endl;
	ind = 0;
//	int _ = clock();
	rd(n), rd(d);
	rep(i, 1, n) rd(a[i]), T[i].clear();
//	ader += clock() - _;
	to[n + 1] = n;
	per(i, n, 1) {
		to[i] = to[i + 1];
		while (a[to[i]] - a[i] > d) to[i]--;
		if (to[i] != i) T[to[i]].pb(i);
//		cout << i << " " << to[i] << endl;
	}
	rep(i, 1, n) if (i == to[i]) dfs1(i, 0);
	rep(j, 1, 20) rep(i, 1, n - (1 << j) + 1) st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << j - 1)]);
//	lca(3,4); return; 
	ans = 0;
	build(1, 1, n);
	per(i, n, 1) {
		if (i == to[i]) {
			if (i != n) cur[0] = 0, modify(1, i + 1, n, 2, 0);
			dfs2(i, 0);
		}
	}
	wrt(ans), putchar(10);
}

int Med;

int main() {
//	int _ = clock();
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int t; rd(t), rd(t);
	while (t--) sol();
//	cerr << clock() - _ << " " << ader;
}
/*
0 1
10 9
2 4 6 9 11 13 15 17 19 20 

ans:3
*/
