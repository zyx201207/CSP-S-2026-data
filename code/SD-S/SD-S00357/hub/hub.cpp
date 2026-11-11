#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, k, _, d1[N], d2[N], st[N][20], dep[N], dfn[N], ts, fa[N];
vector<int> g[N], leaf;

void dfs1(int u, int F) {
	for (int v : g[u])
		if (v != F) d1[v] = d1[u] + 1, dfs1(v, u);
}
void dfs2(int u, int F) {
	for (int v : g[u])
		if (v != F) d2[v] = d2[u] + 1, dfs2(v, u);
}

void dfs(int u, int F) {
	dep[u] = dep[F] + 1;
	dfn[u] = ++ ts;
	fa[u] = F;
	bool flg = 0;
	for (int v : g[u])
		if (v != F) {
			st[v][0] = u;
			for (int i = 1; i < 20; ++ i ) st[v][i] = st[st[v][i - 1]][i - 1];
			dfs(v, u);
			flg = 1; 
		}
	if (!flg) leaf.push_back(u);
}

int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int i = 19; ~i; -- i )
		if (dep[st[a][i]] >= dep[b]) a = st[a][i];
	if (a == b) return a;
	for (int i = 19; ~i; -- i )
		if (st[a][i] != st[b][i]) a = st[a][i], b = st[b][i];
	return fa[a];
}

int jmp(int u, int k) {
	for (int i = 19; ~i; -- i )
		if (k >> i & 1) u = st[u][i];
	return u;
}

bool vis[N];
int pre[N], suf[N];
int plca[N], slca[N];

int dis(int x, int y) {
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
} 

bool chk(int mid) {
	vector<int> p;
	for (int u : leaf) {
		p.push_back(jmp(u, min(dep[u] - 1, mid)));
	}
//	memset(vis, 0, sizeof vis);
//	
//	sort(p.begin(), p.end(), [&](int x, int y) { return dep[x] > dep[y]; });
//	p.erase(unique(p.begin(), p.end()), p.end());
//	
//	priority_queue<pair<int, int>> q;
//	for (int u : p) q.emplace(dep[u], u), vis[u] = 1;
//	int cnt = p.size();
//	while (q.size() > 2) {
//		int u = q.top().second;
//		q.pop();
//		u = fa[u];
//		if (vis[u]) continue;
//		vis[u] = 1;
//		cnt ++ ;
//	}
//	return cnt <= k;
//	
//	return 0;
	sort(p.begin(), p.end(), [&](int x, int y) { return dfn[x] < dfn[y]; });
	p.erase(unique(p.begin(), p.end()), p.end());
	
	
//	cout << mid << " : ";
//	for (int u : p) cout << u << ' ';
//	cout << '\n';
	
	memset(vis, 0, sizeof vis);
	int cnt = 0;
	for (int i = 0; i < p.size(); ++ i ) {
		int u = p[i];
		while (!vis[u] && u) {
			vis[u] = 1, cnt ++, u = fa[u];
		}
		pre[i] = cnt;
		plca[i] = i == 0 ? p[i] : lca(plca[i - 1], p[i]); 
	}
	memset(vis, 0, sizeof vis);
	cnt = 0;
	for (int i = p.size() - 1; ~i; -- i ) {
		int u = p[i];
		while (!vis[u] && u) {
			vis[u] = 1, cnt ++, u = fa[u];
		}
		suf[i] = cnt;
		slca[i] = i + 1 == p.size() ? p[i] : lca(slca[i + 1], p[i]);
	}
	
//	for (int i = 0; i < p.size(); ++ i ) cout << pre[i] << ' '; cout << '\n';
//	for (int i = 0; i < p.size(); ++ i ) cout << plca[i] << ' '; cout << '\n';
	
	if (pre[p.size() - 1] - (dep[plca[p.size() - 1]] - 1) <= k) return 1;
	
	for (int i = 0; i + 1 < p.size(); ++ i ) {
		int u = plca[i], v = slca[i + 1];
//		cout << i << " ::: " << u << ' ' << v << '\n';
		if (dfn[v] <= dfn[u]) continue;
		int x = pre[i] - (dep[u] - 1), y = suf[i + 1] - (dep[v] - 1);
		if (x + y > k) continue;
		int t = dis(u, v);
		t -= (k - x - y);
		if (t <= 0 || (t + 1) / 2 <= mid) return 1; 
		
	}
	
	return 0;
}

int p[N], d[100][100];
int fifa(int x) { return p[x] == x ? x : p[x] = fifa(p[x]); }

int dw[N], up[N];
int F[N], G[N];

void DFS1(int u, int Fa) {
	fa[u] = Fa;
	dw[u] = F[u] = 0;
	int k1 = 0, k2 = 0;
	for (int v : g[u])
		if (v != Fa) {
			DFS1(v, u);
			if (dw[v] + 1 >= k1) k2 = k1, k1 = dw[v] + 1;
			else if (dw[v] + 1 >= k2) k2 = dw[v] + 1;
			F[u] = max(F[u], F[v]);
		}
	dw[u] = k1;
	F[u] = max(F[u], k1 + k2);
}

void DFS2(int u, int Fa, int c, int d) {
//	cout << u << ' ' << c << ' ' << d << '\n';
	// u 往子树外还能连 c，外面最大直径是d 
	int k1 = c, k2 = 0, k3 = 0;
	int f1 = d, f2 = 0;
	for (int v : g[u])
		if (v != Fa) {
			if (dw[v] + 1 >= k1) k3 = k2, k2 = k1, k1 = dw[v] + 1;
			else if (dw[v] + 1 >= k2) k2 = k1, k2 = dw[v] + 1;
			else if (dw[v] + 1 >= k3) k3 = dw[v] + 1;
			if (F[v] >= f1) f2 = f1, f1 = F[v];
			else if (F[v] >= f2) f2 = F[v];
		}
	for (int v : g[u])
		if (v != Fa) {
			int w = dw[v] + 1 == k1 ? k2 + k3 : k1 + (dw[v] + 1 == k2 ? k3 : k2);
			w = max(w, f1 == F[v] ? f2 : f1);
			G[v] = max(d, w);
			DFS2(v, u, max(c, dw[v] + 1 == k1 ? k2 : k1) + 1, G[u]);
		}
}

int solve() {
	cin >> n >> k;
	leaf.clear();
	for (int i = 1; i <= n; ++ i ) g[i].clear();
	ts = 0;
	for (int i = 1; i < n; ++ i ) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b), g[b].push_back(a);
	}
	if (n == k) return 0;
	
	if (_ == 13 || _ == 14) {
		int m = n / 2 + 2;
		int x = m / 2 + 1, y = m - m / 2 + 1;
		int k1 = k / 2, k2 = k - k / 2;
		return max(1, max((x - k1 + 1) / 2, (y - k2 + 1) / 2));
	}
	if (_ <= 3) {
		memset(d, 0x3f, sizeof d);
		for (int i = 1; i <= n; ++ i ) d[i][i] = 0;
		for (int i = 1; i <= n; ++ i ) for (int j : g[i]) d[i][j] = 1;
		for (int k = 1; k <= n; ++ k ) for (int i = 1; i <= n; ++ i ) for (int j = 1; j <= n; ++ j )
			d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		int res = 1e9;
		for (int s = 0; s < 1 << n; ++ s )
			if (__builtin_popcount(s) == k) {
				for (int i = 1; i <= n; ++ i ) p[i] = i;
				for (int i = 1; i <= n; ++ i ) if (s >> i - 1 & 1)
					for (int j : g[i]) if (s >> j - 1 & 1) p[fifa(i)] = fifa(j);
				int cnt = 0;
				for (int i = 1; i <= n; ++ i ) if (s >> i - 1 & 1)
					if (i == fifa(i)) cnt ++ ;
				if (cnt <= 2) {
					int mx = 0;
					for (int i = 1; i <= n; ++ i ) if (!(s >> i - 1 & 1)) {
						int mn = 1e9;
						for (int j = 1; j <= n; ++ j ) if (s >> j - 1 & 1)
							mn = min(mn, d[i][j]);
						mx = max(mx, mn); 
					}
					res = min(res, mx);
				}
			}
		return res;
	}
	
	if (_ == 7 || _ == 11 || _ == 12) {
		// 选两个点
		// 子树直径
		// 换根dp
		DFS1(1, 0), DFS2(1, 0, 0, 0);
		
		for (int i = 1; i <= n; ++ i ) {
//			cout << G[i] << ' ';
		}
		
		int res = 1e9;
		for (int i = 1; i <= n; ++ i ) res = min(res, max(F[i], G[i]));
		res = (res + 1) / 2;
		return res;
	}
	
	// 先求中点
	int s = 0;
	d1[1] = 0, dfs1(1, 0);
	int t = max_element(d1 + 1, d1 + n + 1) - d1;
	d2[t] = 0, dfs2(t, 0);
	s = max_element(d2 + 1, d2 + n + 1) - d2;
	d1[s] = 0, dfs1(s, 0);
	int rt, mn = 1e9;
	for (int i = 1; i <= n; ++ i )
		if (max(d1[i], d2[i]) < mn) {
			mn = max(d1[i], d2[i]);
			rt = i;
		}
	dfs(rt, 0);
	
//	cout << rt << '\n';
//	for (int u : leaf) cout << u << ' '; cout << '\n';
	
	int lo = 0, hi = (d2[s] + 1) / 2, res = -1;
	while (lo <= hi) {
		int mid = lo + hi >> 1;
		if (chk(mid)) res = mid, hi = mid - 1;
		else lo = mid + 1;
	}
	return res;
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> _ >> T;
	while (T -- ) cout << solve() << '\n';
	return 0;
}

/*
0 1
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
