#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define fi first
#define se second
typedef vector <int> vi;
typedef vector <pii> vpi;
#define pb push_back

int cid;

template <class T> void rd(T &a, int c = 0) {
	while (!isdigit(c = getchar()));
	for (a = 0; isdigit(c); c = getchar()) a = (a << 3) + (a << 1) + (c ^ 48);
}
template <class T> void wrt(T x) {
	if (x > 9) wrt(x / 10);
	putchar(x % 10 ^ 48);
}

const int N = 1000005;

int n, k, u, v;
vi T[N]; 

namespace Sol1 {
	int glu, glv;
	int mx, p;
	vi zj;
	int mdp[N];
	int d1[N], d2[N], d3[N], d4[N]; 
	int ans;
	void dfs2(int u, int fa, int dis) {
		if (dis > mx) mx = dis, p = u;
		for (auto v : T[u]) {
			if (v == fa) continue;
			if (min(u, v) == glu && max(u, v) == glv) continue;
			dfs2(v, u, dis + 1);
		}
	}
	bool dfs3(int u, int B, int fa) {
		if (u == B) {
			zj.pb(u);
			return 1;
		}
		for (auto v : T[u]) {
			if (v == fa) continue;
			if (min(u, v) == glu && max(u, v) == glv) continue;
			if (dfs3(v, B, u)) {
				zj.pb(u);
				return 1;
			}
		}
		return 0;
	}
	int fdmd(int u) {
		int A, B;
		mx = -1, dfs2(u, 0, 0), A = p;
		mx = -1, dfs2(A, 0, 0), B = p;
		zj.clear();
		dfs3(A, B, 0);
		return zj[zj.size() / 2];
	}
	void dfs4(int u, int fa, int *d) {
		mdp[u] = 0;
		for (auto v : T[u]) {
			if (v == fa) continue;
			if (min(u, v) == glu && max(u, v) == glv) continue;
			dfs4(v, u, d);
			mdp[u] = max(mdp[u], mdp[v] + 1);
		}
//		cout << "!! " << u << " " << mdp[u] << endl;
		if (!fa) d[n]++;
		else d[mdp[u]]++;
	}
	void dfs1(int u, int fa) {
		for (auto v : T[u]) {
			if (v == fa) continue;
			dfs1(v, u);
		}
		if (!fa) return;
		glu = min(u, fa), glv = max(u, fa);
		int x = fdmd(u), y = fdmd(fa);
//		cout << u << "  " << fa << "  " << x << "  " << y << endl;
		rep(i, 0, n + 1) d1[i] = d3[i] = 0, d2[i] = d4[i] = 1e9;
		dfs4(x, 0, d1), dfs4(y, 0, d3);
		per(i, n, 0) d1[i] += d1[i + 1], d3[i] += d3[i + 1];
//		rep(i, 0, n) cout << d1[i] << " "; cout << endl;
//		rep(i, 0, n) cout << d3[i] << " "; cout << endl;
		rep(i, 0, n) d2[d1[i]] = min(d2[d1[i]], i), d4[d3[i]] = min(d4[d3[i]], i);
		rep(i, 1, n) d2[i] = min(d2[i], d2[i - 1]), d4[i] = min(d4[i], d4[i - 1]);
//		rep(i, 0, n) cout << d2[i] << " "; cout << endl;
//		rep(i, 0, n) cout << d4[i] << " "; cout << endl;
		rep(i, 0, k) ans = min(ans, max(d2[i], d4[k - i]));
//		cout << u << "  " << fa << " " << ans << endl;
	}
	void main() {
		ans = 1e9;
		dfs1(1, 0);
		wrt(ans), putchar(10);
	}
}

namespace Sol2 {
	int dep[N], anc[N][22];
	void dfs1(int u, int fa) {
		dep[u] = dep[fa] + 1, anc[u][0] = fa;
		for (auto v : T[u]) {
			if (v == fa) continue;
			dfs1(v, u);
		}
	}
	int lca(int u, int v) {
		if (dep[u] < dep[v]) swap(u, v);
		per(i, 20, 0) if (dep[anc[u][i]] >= dep[v]) u = anc[u][i];
		if (u == v) return u;
		per(i, 20, 0) if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
		return anc[u][0]; 
	}
	int dis(int u, int v) {
		return dep[u] + dep[v] - 2 * dep[lca(u, v)];
	}
	struct Info {
		int val, u, v;
	};
	bool operator< (Info a, Info b) {
		return a.val < b.val;
	}
	bool operator> (Info a, Info b) {
		return a.val > b.val;
	}
	Info operator+ (Info a, Info b) {
		if (a.val == -1) return b;
		if (b.val == -1) return a;
		Info R = max(a, b);
		int u1 = a.u, v1 = a.v, u2 = b.u, v2 = b.v;
		R = max(R, Info{dis(u1, u2), u1, u2});
		R = max(R, Info{dis(u1, v2), u1, v2});
		R = max(R, Info{dis(v1, u2), v1, u2});
		R = max(R, Info{dis(v1, v2), v1, v2});
		return R;
	}
	Info f[N], uf[N];
	void dfs2(int u, int fa) {
		f[u] = Info{0, u, u};
		for (auto v : T[u]) {
			if (v == fa) continue;
			dfs2(v, u);
			f[u] = f[u] + f[v];
		}
	}
	void dfs3(int u, int fa) {
		vi son;
		for (auto v : T[u]) {
			if (v == fa) continue;
			son.pb(v);
		}
		int sct = son.size();
		vector <Info> pr(sct + 2), sf(sct + 2);
		pr[0] = sf[sct + 1] = {-1, 0, 0};
		rep(i, 1, sct) pr[i] = sf[i] = f[son[i - 1]];
		rep(i, 1, sct) pr[i] = pr[i] + pr[i - 1];
		per(i, sct, 1) sf[i] = sf[i] + sf[i + 1];
		rep(i, 1, sct) {
			int v = son[i - 1];
			uf[v] = uf[u] + Info{0, u, u} + pr[i - 1] + sf[i + 1];
			dfs3(v, u);
		}
	}
	void main() {
		dfs1(1, 0);
		rep(j, 1, 20) rep(i, 1, n) anc[i][j] = anc[anc[i][j - 1]][j - 1];
		dfs2(1, 0);
		uf[1] = {-1, 0, 0};
		dfs3(1, 0);
		int ans = 1e9;
		rep(i, 2, n) ans = min(ans, max((f[i].val + 1) / 2, (uf[i].val + 1) / 2));
		wrt(ans), putchar(10);
	}
}

namespace Sol3 {
	void main() {
		int m = n / 2;
		per(i, n, 1) {
			int l1 = i, r2 = m - i + 1;
			int r1 = l1 + k - 2, l2 = r2;
//			if (i == 1) cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
			if (r1 + 1 >= l2) continue;
			if ((l2 - r1 + 1) / 2 + 1 > i) {
				wrt(i + 1), putchar(10);
				return;
			}
		}
		puts("1");
	}
}

void solve() {
	rd(n), rd(k);
	rep(i, 1, n) T[i].clear();
	repr(i, 1, n) {
		rd(u), rd(v);
		T[u].pb(v), T[v].pb(u);
	}
	if (n == k) {
		puts("0");
		return;
	}
	if (cid <= 10) return Sol1::main();
	if (cid <= 12) return Sol2::main();
	if (cid <= 14) return Sol3::main();
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int t;
	rd(cid), rd(t);
	while (t--) solve();
}
/*
0 2
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


0 1
5 2
1 2
2 3
3 4
4 5


14 1
7 2
1 2
2 3
2 3
1 2
2 3
2 3
*/
