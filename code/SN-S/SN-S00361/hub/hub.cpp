// gaoxuke xajdfz SN-S00361
#include <bits/stdc++.h>
using namespace std;

namespace gxk {
	void main() ;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	gxk::main();
	return 0;
}

// ---

#define int long long
#define rep(x, l, r) for (int x = (l); x <= (r); x++)
#define per(x, r, l) for (int x = (r); x >= (l); x--) 

namespace Maky {
	template <typename T> inline void chkmin(T &x, T y) {
		x = (x < y ? x : y);
		return ;
	}
	template <typename T> inline void chkmax(T &x, T y) {
		x = (x > y ? x : y);
		return ;
	}
} using namespace Maky;

namespace gxk {
	constexpr int maxn = 1000010;
	
	int C, TT, n, k, rt, d[maxn], maxd;
	vector <int> G[maxn], T[maxn];
	
	void dfs1(int u, int fa) {
		for (auto to : G[u]) {
			if (to == fa) continue;
			d[to] = d[u] + 1;
			dfs1(to, u);
		}
		return ;
	}
	int h[maxn], h2[maxn], f[maxn];
	void dfs2(int u, int fa) {
		h[u] = 0;
		for (auto to : G[u]) {
			if (to == fa) continue;
			dfs2(to, u);
			chkmax(h[u], h[to] + 1);
		}
		if (h[u] + d[u] == maxd && d[u] == maxd / 2) rt = u;
		return ;
	}
	int dfn[maxn], sz[maxn], nowdfn;
	void dfs3(int u, int fa) {
		sz[u] = 1;
		dfn[u] = ++nowdfn;
		h[u] = 0;
		h2[u] = 0;
		for (auto to : G[u]) {
			if (to == fa) continue;
			f[to] = u;
			dfs3(to, u);
			sz[u] += sz[to];
			int v = h[to] + 1;
			if (v > h[u]) h2[u] = h[u], h[u] = v;
			else if (v > h2[u]) h2[u] = v;
		}
		return ;
	}
	
	void get1(int u, int &res, int x) {
		if (h[u] >= x) res++;
		for (auto to : G[u]) {
			if (to == f[u]) continue;
			get1(to, res, x);
		}
		return ;
	}
	
	struct ssss {
		int x, d[maxn], maxx;
		void dfs(int u, int fa) {
			if (d[u] > maxx) maxx = d[u], x = u;
			for (auto to : T[u]) {
				if (to == fa) continue;
				d[to] = d[u] + 1;
				dfs(to, u);
			}
			return ;
		}
		int h[maxn];
		void dfs2(int u, int fa) {
			h[u] = 0;
			for (auto to : T[u]) {
				if (to == fa) continue;
				dfs2(to, u);
				chkmax(h[u], h[to] + 1);
			}
			if (h[u] + d[u] == maxx && d[u] == maxx / 2) x = u;
			return ;
		}
		int res, LIM;
		void dfs3(int u, int fa) {
			h[u] = 0;
			for (auto to : T[u]) {
				if (to == fa) continue;
				dfs3(to, u);
				int v = h[to] + 1;
				if (v > h[u]) h[u] = v;
			}
			if (h[u] >= LIM) res++;
			return ;
		}
		int work(int u, int lim) {
			res = 0;
			LIM = lim;
			d[u] = 0;
			maxx = -1;
			dfs(u, 0);
			maxx = -1, d[x] = 0;
			dfs(x, 0);
			dfs2(x, 0);
//			cout << x << endl;
			dfs3(x, 0);
			return res;
		}
	} zph;
	
	/*
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
	
	int chk(int x) {
//		cout << "lim: " << x << '\n';
		int Ans = n + 1;
		rep (U, 1, n) {
			int u = U;
			if (h[u] >= x) {
//				cout << u << '\n';
				int res = 0;
				get1(u, res, x);
				int nowdis = x;
				while (1) {
					if (u == rt) break;
					nowdis--;
					int fa = f[u], vv;
					if (h[u] + 1 == h[fa]) vv = h2[fa];
					else vv = h[fa];
					if (vv <= nowdis) u = fa;
					else break;
				}
				if (u == rt) {
					chkmin(Ans, res);
					continue;
				}
				int l = dfn[u], r = sz[u] + dfn[u] - 1;
				rep (i, 1, n) T[i].clear();
				rep (u, 1, n) {
					if (dfn[u] < l || dfn[u] > r) {
						for (auto to : G[u]) {
							if (dfn[to] < l || dfn[to] > r) {
								T[u].push_back(to);
//								cout << u << ' ' << to << '\n';
							}
						}
					}
				}
				int v = res + zph.work(f[u], x);
//				cout << u << ' ' << res << ' ' << v - res << '\n' << endl;;
				chkmin(Ans, v);
			}
		}
		return Ans;
	}
	
	void main() {
		cin >> C >> TT;
		while (TT--) {
			nowdfn = 0;
			cin >> n >> k;
			rep (i, 1, n - 1) {
				int x, y;
				cin >> x >> y;
				G[x].push_back(y);
				G[y].push_back(x);
			}
			if (k >= n) {
				cout << 0 << '\n';
				continue;
			}
			
			d[1] = 0;
			dfs1(1, 0);
			maxd = -1;
			rep (i, 1, n) if (d[i] > maxd) maxd = d[i], rt = i;
			d[rt] = 0;
			dfs1(rt, 0);
			maxd = -1;
			rep (i, 1, n) chkmax(maxd, d[i]);
			dfs2(rt, 0);
			
			maxd = -1;
			d[rt] = 0;
			dfs1(rt, 0);
			rep (i, 1, n) chkmax(maxd, d[i]);
			dfs3(rt, 0);
			f[rt] = 0;
			
//			cout << rt << endl;
			
			int l = 1, r = maxd - 1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (chk(mid) > k) l = mid + 1;
				else r = mid - 1;
			}
			cout << l << '\n';
			
			rep (i, 1, n) G[i].clear();
		}
		
		return ;
	}
}
