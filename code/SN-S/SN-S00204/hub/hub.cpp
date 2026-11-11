#include <bits/stdc++.h>
using namespace std;
const int N = 4e3 + 5;
int C, T;
int n, K;
vector<int>v[N];

int d1[N], d2[N];
inline void dfs1(int x, int fa) {
	d2[x] = d2[fa] + 1;
	for (int y : v[x])
		if (y != fa) dfs1(y, x);
}
int dfn[N], tim, rk[N], siz[N];
inline void dfsn(int x, int fa) {
	dfn[x] = ++tim, rk[tim] = x, siz[x] = 1;
	for (int y : v[x])
		if (y != fa) dfsn(y, x),siz[x]+=siz[y];
}

struct Md {
	int d[N][N];
	inline void dfs(int x, int fa, int s) {
		d[s][x] = d[s][fa] + 1;
		for (int y : v[x]) {
			if (y == fa) continue;
			dfs(y, x, s);
		}
	}
	inline void init() {
		for (int i = 1; i <= n; i++) dfs(i, 0, i);
	}
	inline int dis(int x, int y) {
		return d[x][y] - 1;
	}
} A;

//struct Md {
//	int son[N], siz[N], top[N], dep[N], f[N];
//	inline void dfs1(int x, int fa) {
//		son[x] = 0;
//		f[x] = fa;
//		siz[x] = 1;
//		dep[x] = dep[fa] + 1;
//		for (int y : v[x]) {
//			if (y == fa) continue;
//			dfs1(y, x);
//			siz[x] += siz[y];
//			if (siz[y] > siz[son[x]]) son[x] = y;
//		}
//	}
//	inline void dfs2(int x, int t) {
//		top[x] = t;
//		if (!son[x]) return;
//		dfs2(son[x], t);
//		for (int y : v[x]) {
//			if (y != son[x] && y != f[x]) dfs2(y, y);
//		}
//	}
//	inline int LCA(int x, int y) {
//		while (top[x] != top[y]) {
//			if (dep[top[x]] < dep[top[y]]) swap(x, y);
//			x= f[top[x]];
//		}
//		return dep[x] < dep[y] ? x : y;
//	}
//	inline int dis(int x, int y) {
//		return dep[x] + dep[y] - 2 * dep[LCA(x, y)];
//	}
//	inline void init() {
//		dfs1(1, 0);
//		dfs2(1, 1);
//	}
//} A;

int rt, F1, F2, R1, R2, mid;

int dp[N], d[N], f[N];
inline void dfsf(int x, int fa) {
	f[x] = fa;
	for (int y : v[x])
		if (y != fa) dfsf(y, x);
}
int ins[N];
inline void dfsp(int x, int fa) {
	ins[x] = 1;
	d[x] = 0, dp[x] = 1;
	for (int y : v[x]) {
		if (y == fa) continue;
		dfsp(y, x);
		d[x] = max(d[x], d[y] + 1);
		if (d[y] + 1 > mid) dp[x] += dp[y];
	}
}

inline int chk() {
	for (int x = 1; x <= n; x++) {
		dfsp(x, 0);
		if (dp[x] <= K) return 1;
	}	
	for (int x = 1; x <= n; x++) {
		dfsn(x, 0), dfsf(x, 0);
		for (int y = 1; y < x; y++) {
			int fx = 0;
			for (int z : v[x]) {
				if (dfn[z] <= dfn[y] && dfn[y] <= dfn[z] + siz[z] - 1) {
					fx = z;
					break;
				}
			}
			for (int i = 1; i <= n; i++) ins[i] = 0;
			dfsp(x, fx), dfsp(y, f[y]);
			if (dp[x] + dp[y] > K) continue;
			int tg = 0;
			for (int i = 1; i <= n; i++) {
				if (ins[i] || A.dis(i, x) <= mid || A.dis(i, y) <= mid) continue;
				tg = 1; break;
			}
			if (!tg) return 1;
		}
	}
	return 0;
}

inline void init() {
	for (int i = 1; i <= n; i++) v[i].clear();
}
inline void solve() {
	init();
	cin >> n >> K;
	for (int i = 1, x, y; i < n; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	A.init();
	d2[0] = -1;
	dfs1(1, 0);
	F1 = 1, F2 = 1;
	for (int i = 2; i <= n; i++)
		if (d2[i] > d2[F1]) F1 = i;
	dfs1(F1, 0);
	for (int i = 1; i <= n; i++)
		if (d2[i] > d2[F2]) F2 = i;
	for (int i = 1; i <= n; i++) d1[i] = d2[i];
	dfs1(F2, 0);
	rt = 0, R1 = 0, R2 = 0;
	if (d1[F2] & 1) {
		for (int i = 1; i <= n; i++)
			if (d1[i] + d2[i] == d1[F2]) {
				if (d1[i] == (d1[F2] >> 1)) R1 = rt = i;
				else if (d1[i] == (d1[F2] >> 1) + 1) R2 = i;
			}
	}
	else {
		for (int i = 1; i <= n; i++)
			if (d1[i] + d2[i] == d1[F2]) {
				if (d1[i] == (d1[F2] >> 1)) rt = i;
				else if (d1[i] == (d1[F2] >> 1) + 1) R2 = i;
				else if (d1[i] == (d1[F2] >> 1) - 1) R1 = i;
			}
	}
	int L = 0, R = (d1[F2] + 1) >> 1, ans = n;
	while (L <= R) {
		mid = (L + R) >> 1;
		if (chk()) ans = mid, R = mid - 1;
		else L = mid + 1;
	}
	cout << ans << '\n';
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> C >> T;
	while (T--) solve();
	return 0;
}
