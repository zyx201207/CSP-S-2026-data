// 愿望……和你，在一起

#include <bits/stdc++.h>
#include <cassert>
//#define int long long
using namespace std;

bool beginmem_qwq;

constexpr int N = 1000100;
constexpr int mod = 998244353;

//constexpr int inf = 2e18;

inline int power(int a, int b, int c) {
	int res = 1; while (b) {
		if (b & 1) res = res * a % c;
		a = a * a % c, b >>= 1;
	} return res;
}

inline int inversion(int x) {
	return power(x, mod - 2, mod);
}

using u8 = unsigned char;

using i16 = short;
using u16 = unsigned short;

using u32 = unsigned;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;

namespace Solver {
	
	int cccc;
	
	inline void init() {
		
	}
	
	vector<int> adj[N];
	int st[N][20], dep[N], maxdep[N], up[N], n, k;
	
//	int f[4010][3][4010][2], g[3][4010][2], siz[4010], maxdep[N], dep[N], up[N];
	
	inline void dfs_init(int u, int fa) {
		dep[u] = dep[fa] + 1, maxdep[u] = 1, up[u] = fa;
		for (int &v : adj[u]) if (v != fa) {
			dfs_init(v, u);
			maxdep[u] = max(maxdep[u], maxdep[v] + 1);
		}
	}
	
	// f[i][j][k][0/1] : i 点为根的子树, 划分了 j 个块(j=0,1,2), 子树内用了 k 个点, i 点是否被选, 距离 i 点最近的没被染色距离是多少 
	
//	inline void dfs(int u, int fa, int p) {
//		siz[u] = 1;
//		if (maxdep[u] <= p) f[u][0][0][0] = maxdep[u] - 1;
//		if (maxdep[u] <= p + 1) f[u][1][1][1] = 0;
//		for (int &v : adj[u]) if (v != fa) {
//			dfs(v, u, p);
//			memset(g, 0, sizeof g);
//			for (int i = 0; i <= min(siz[u], k); ++i)
//				for (int j = 0; j <= min(siz[v], i) && j <= k - i; ++j) {
//					// 已经用了 i 个点, 当前 v 的子树内选 j 个点 
//					// 1. 根结点 u 被选择 
//					if (i) {
//						if (f[u][1][j][1] <= p && f[v][0][j][0] <= p) g[1][i + j][1] = 0;
//						if (f[u][1][j][1] <= p && f[v][1][j][1] <= p) g[1][i + j][1] = 0;
//						if (f[u][1][j][1] <= p && f[v][1][j][0] <= p) g[2][i + j][1] = 0;
//						if (f[u][2][j][1] <= p && f[v][1][j][1] <= p) g[2][i + j][1] = 0;
//					}
//					// 2. 根结点 u 没有被选择 
//					do {
//						if (f[u][0][j][0] < p && f[v][0][j][0] < p) g[]
//						if (f[u][1][j][0] <= p && f[v][0][j][0] <= p) g[1][i + j][1] = 
//					} while (0);
//				}
//			siz[u] += siz[v];
//		}
//	}
	
//	inline int chk(int p) {
//		for (int i = 1; i <= n; ++i)
//			for (int j = 0; j <= k; ++j)
////				f[i][0][j] = f[i][1][j] = f[i][2][j] = 1e9;
//				f[i][0][j][0] = f[i][0][j][1] = f[i][1][j][0] = f[i][1][j][1] = f[i][2][j][0] = f[i][2][j][1] = 1e9;
//		dfs(1, 0, p);
//	}
	
	inline int lca(int a, int b) {
		if (dep[a] < dep[b]) swap(a, b);
		for (int i = 19; ~i; --i) if (dep[a] - dep[b] >> i & 1) a = st[a][i];
		if (a == b) return a;
		for (int i = 19; ~i; --i)
			if (st[a][i] != st[b][i]) a = st[a][i], b = st[b][i];
		return st[a][0];
	}
	
	inline int dist(int a, int b) {
		return dep[a] + dep[b] - 2 * dep[lca(a, b)];
	}
	
	int dis[N], qqiq, rua[N], su[N];
	
	inline void dfs(int u, int fa) {
		maxdep[u] = rua[u] = 1;
		for (int &v : adj[u]) if (v != fa) {
			dfs(v, u);
			maxdep[u] = max(maxdep[u], maxdep[v] + 1);
		}
	}
	
	inline void sol() {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) adj[i].clear() ;
		for (int i = 1; i < n; ++i) {
			int a, b; cin >> a >> b;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		} // int l = 1, r = n, best = -1;
		if (n == k) { cout << 0 << '\n'; return; }
		dfs_init(1, 0);
		if (k == 2) {
			for (int i = 1; i <= n; ++i) dis[i] = 1e9;
			queue<int> q;
			q.emplace(1), dis[1] = 0;
			while (q.size()) {
				int t = q.front();
				q.pop();
				for (int &g : adj[t]) {
					if (dis[g] > dis[t] + 1) {
						dis[g] = dis[t] + 1;
						q.emplace(g);
					}
				}
			}
			int diam = -1, id = -1;
			for (int i = 1; i <= n; ++i)
				if (dis[i] > diam) diam = dis[id = i];
			for (int i = 1; i <= n; ++i) dis[i] = 1e9;
			q.emplace(id), dis[id] = 0;
			while (q.size()) {
				int t = q.front();
				q.pop();
				for (int &g : adj[t]) {
					if (dis[g] > dis[t] + 1) {
						dis[g] = dis[t] + 1;
						q.emplace(g);
					}
				}
			} diam = *max_element(dis + 1, dis + n + 1) ;
			int p1 = id;
			for (int i = 1; i <= n; ++i)
				if (dis[i] == diam) {
					id = i;
					break;
				}
			int p2 = id;
			vector<int> pth;
			int u1 = p1, u2 = p2;
			if (dep[u1] < dep[u2]) swap(u1, u2);
			while (dep[u1] != dep[u2]) u1 = up[u1];
			while (u1 != u2) u1 = up[u1], u2 = up[u2];
			assert(u1 == u2 && u1);
			int LCA = u1, tmp = p1;
			while (tmp != LCA) pth.emplace_back(tmp), tmp = up[tmp];
			pth.emplace_back(LCA);
			vector<int> pth2;
			tmp = p2;
			while (tmp != LCA) pth2.emplace_back(tmp), tmp = up[tmp];
			reverse(pth2.begin(), pth2.end());
			for (int &i : pth2) pth.emplace_back(i);
			int l = 1, r = (int)pth.size() - 1, best = r + 1;
			for (int i = 1; i <= n; ++i) st[i][0] = up[i];
			for (int i = 1; i < 20; ++i)
				for (int j = 1; j <= n; ++j) st[j][i] = st[st[j][i - 1]][i - 1];
			auto chk = [&](int x) -> int {
				int v1 = pth[x], v2 = pth[(int)pth.size() - x - 1];
				for (int i = 1; i <= n; ++i)
					if (dist(i, v1) > x && dist(i, v2) > x) return 0;
				return 1;
			};
//			cerr << "pth.size() = " << pth.size() << '\n';
			while (l <= r) {
				int mid = l + r >> 1;
				chk(mid) ? (best = mid, r = mid - 1) : (l = mid + 1);
			}
			cout << best << '\n';
			return;
		}
		if (n > 100) {
			// A 性质 只用考虑一条长度为 n/2+2 的链 带若干个凸起 
			int m = n / 2 + 2; 
//			cerr << "SUB A!\n";
			int l = 1, r = m, best = r + 1;
			auto chk = [&](int p) {
				for (int i = 0; i <= max(n, m) + 3; ++i) su[i] = 0;
				for (int i = p + 1, j = 1; i <= m && j <= k / 2; ++i, ++j) su[i] = 1;
				for (int i = m - p - 1, j = 1; i >= 1 && j <= (k + 1) / 2; --i, ++j) su[i] = 1;
				int emp = 0;
				for (int i = p + 1; i <= m - p - 1; ++i)
					if (!su[i]) ++emp;
				if (emp > p + p) return 0;
				for (int i = 0; i <= m + 1; ++i) dis[i] = 1e9;
				for (int i = 1; i <= m; ++i)
					if (su[i]) dis[i] = 0;
				for (int i = p + 2; i <= m - p - 1; ++i)
					if (!su[i]) dis[i] = dis[i - 1] + 1;
				for (int i = m - p - 1; i >= p + 2; --i)
					if (!su[i]) dis[i] = min(dis[i], dis[i + 1] + 1);
				for (int i = p + 1; i <= m - p - 1; ++i) {
					if (i >= 3 && i <= m - 1) {
						if (dis[i] > p - 1) return 0;
					} else {
						if (dis[i] > p) return 0;
					}
				} return 1;
			};
//			cerr << "chk(45000) = " << chk(45000) << ' ' << k << '\n';
			while (l <= r) {
				int mid = l + r >> 1;
				chk(mid) ? (best = mid, r = mid - 1) : (l = mid + 1);
			}
			cout << best << '\n';
			return;
		}
		for (int i = 1; i <= n; ++i) st[i][0] = up[i];
		for (int i = 1; i < 20; ++i)
			for (int j = 1; j <= n; ++j) st[j][i] = st[st[j][i - 1]][i - 1];
		int l = 1, r = n - 1, best = n;
		auto chk = [&](int p) {
			for (int u = 1; u <= n; ++u)
				for (int v = u + 1; v <= n; ++v) {
					int LCA = lca(u, v);
					vector<int> pth, pth2;
					int tmp = u, okk = 1;
					while (tmp != LCA) pth.emplace_back(tmp), tmp = up[tmp];
					pth.emplace_back(LCA), tmp = v;
					while (tmp != LCA) pth2.emplace_back(tmp), tmp = up[tmp];
					reverse(pth2.begin(), pth2.end());
					for (int &i : pth2) pth.emplace_back(i);
					assert(pth.size() > 1);
					int ban_u = pth[1], ban_v = pth[(int)pth.size() - 2];
					qqiq = p;
					for (int i = 0; i <= n; ++i) maxdep[i] = rua[i] = su[i] = 0;
					dfs(u, ban_u);
					dfs(v, ban_v);
					int need = 0;
					queue<int> q;
//					cerr << "============================================================\n";
					for (int i = 1; i <= n; ++i) su[i] = 0;
					for (int i = 1; i <= n; ++i)
						if (i == u || i == v || rua[i] && maxdep[i] > p) {
							su[i] = 1, ++need;
//							cerr << "MUST " << i << '\n';
							q.emplace(i);
						}
					if (need > k) {
						okk = 0;
						goto yuqing;
					}
					while (q.size()) {
						int t = q.front() ;
						q.pop();
						if (t != u && t != v) {
							for (int &g : adj[t]) {
								if (rua[g] || maxdep[g] <= p) continue;
								su[g] = 1, ++need;
								if (need > k) {
									okk = 0;
									goto yuqing;
								}
							}
						}
					}
					yuqing:;
					if (okk) {
						for (int i = 1; i <= n; ++i) dis[i] = 1e9;
						queue<int> q;
						for (int i = 1; i <= n; ++i)
							if (su[i]) q.emplace(i), dis[i] = 0; //, cerr << "su : " << i << '\n';
						while (q.size()) {
							int t = q.front(); q.pop();
//							cerr << "dis[" << t << "] = " << dis[t] << '\n';
							for (int &g : adj[t])
								if (dis[g] > dis[t] + 1) {
									dis[g] = dis[t] + 1;
									if (dis[g] > p) {
										okk = 0;
										goto dududu;
									}
									q.emplace(g);
								}
						}
						dududu:;
						if (okk) {
//							cerr << "when p = " << p << ": " << u << ", " << v << " is OK, need = " << need << ".\n";
//							cerr << "INFO: " << ban_u << ' ' << ban_v << '\n';
//							cerr << "QwQ: " << dis[u] << ' ' << dis[v] << '\n';
//							cerr << "DIST: ";
//							for (int i = 1; i <= n; ++i) cerr << dis[i] << ' ';
//							cerr << '\n';
							return 1;
						}
					}
				}
			return 0;
		};
		while (l <= r) {
			int mid = l + r >> 1;
			chk(mid) ? (best = mid, r = mid - 1) : (l = mid + 1);
		} cout << best << '\n';
//		while (l <= r) {
//			int mid = l + r >> 1;
//			chk(mid) ? (best = mid, r = mid - 1) : (l = mid + 1);
//		} cout << best << '\n';
	}
}

inline void calc_forever1210();

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> Solver::cccc;
	int T = 1;
	cin >> T;
	Solver::init();
	while (T--) {
		Solver::sol();
	}
	calc_forever1210();
	return 0;
}

bool endmem_qwq;

inline void calc_forever1210() {
	cerr << fixed << setprecision(5);
//	cerr << "Memory Used " << abs(&beginmem_qwq - &endmem_qwq) / 1048576. << " MB.\n";
}

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



/*

2

*/


