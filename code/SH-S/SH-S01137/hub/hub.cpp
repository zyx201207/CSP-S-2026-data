#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i = (l); i <= (r); ++i)
#define ROF(i, r, l) for (int i = (r); i >= (l); --i)
#define popc(x) __builtin_popcountll((x))
#define SZ(v) int((v).size())
#define allc(v) (v).begin(), (v).end()
#define PB push_back
#define FI first
#define SE second
#define MP make_pair 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template<typename A, typename B>
void chkmax(A &a, B b) { a = (a > b) ? a : b; }
template<typename A, typename B>
void chkmin(A &a, B b) { a = (a < b) ? a : b; } 
bool Mbe;
namespace lyl {
	const int N = 1e6 + 5;
	const int inf = 0x3f3f3f3f;
	int n, k, A, B, d0, d1, Fa[N], mxdep1[N], dep[N], mxdep2[N], val[N], val2[N];
	int p1[N], p2[N], Fa1[N], Fa2[N], v1[N], v2[N], path[N], len, dis[N];
	bool on[N];
	vector<int> G[N]; 
	void find_d(int u, int fa, int d, int &U, int &D) {
		Fa[u] = fa;
		if (d > D) U = u, D = d;
		for (int v: G[u]) {
			if (v == fa) continue;
			find_d(v, u, d + 1, U, D);
		}
	}
	void predfs(int u, int fa) {
		dep[u] = 0;
		for (int v: G[u]) {
			if (v == fa || on[v]) continue;
			predfs(v, u);
			chkmax(dep[u], dep[v] + 1);
		}
	}
	bool flag[N];
	int tot1, tot2;
	void dfs0(int u, int fa) {
		mxdep1[u] = 0, Fa1[u] = fa;
		for (int v: G[u]) {
			if (v == fa) continue;
			dfs0(v, u);
			chkmax(mxdep1[u], mxdep1[v] + 1);
		}
		p1[++tot1] = u;
	} 
	int q1[N], l1, r1, q2[N], l2, r2, cost;
	void dfs1(int u, int fa, int d, int nowd, int dis) {
		if (!on[u]) chkmax(cost, -val2[u] + nowd - d);
		int mx = -1, mx2 = -1, fr = 0;
		for (int v: G[u]) {
			if (v == fa || on[v]) continue;
			if (dep[v] > mx) mx2 = mx, mx = dep[v], fr = v;
			else chkmax(mx2, dep[v]);
		}
		for (int v: G[u]) {
			if (on[v] || v == fa) continue;
			int newd = v == fr ? mx2 + 1 : mx + 1;
			dfs1(v, u, max(d, nowd - max(0, dis - newd)), nowd + (dep[v] >= dis), dis);
		}

	}
	bool check(int dis) {
		FOR (i, 1, n) val[i] = val2[i] = 0;
		FOR (i, 1, n - 1) {
			int u = p1[i], v = p2[i];
			val[Fa1[u]] += val[u] + (mxdep1[u] >= dis ? 1 : 0);
			val2[Fa2[v]] += val2[v] + (mxdep2[v] >= dis ? 1 : 0);
		}
		FOR (u, 1, n) ++val2[u], ++val[u];
		cost = 0;
		FOR (i, 0, len - 1) {
			dfs1(path[i], 0, 0, 0, dis);
			if (val2[path[i]] - cost <= k && (i == len - 1 || mxdep1[path[i + 1]] < dis)) return 1;
		}
		int j = len - 1, mid = j;
		l1 = 1, r1 = 0, l2 = 1, r2 = 0;
		ROF (i, len - 1, 0) {
			int u = path[i];
			if (i + 1 < len) {
				while (l1 <= r1 && v1[i + 1] >= v1[q1[r1]]) --r1;
				q1[++r1] = i + 1;
			}
			if (mid != (i + 1 + j) / 2) {
				if (q1[l1] == mid) ++l1; 
				while (l2 <= r2 && v2[q2[r2]] <= v2[mid]) --r2;
				q2[++r2] = mid--;
			}
			if (val2[u] > k) continue;
			while (j > i && val2[u] + val[path[j]] <= k) {
				if (q2[l2] == j) ++l2; --j;
				if (mid != (i + 1 + j) / 2) {
					if (q1[l1] == mid) ++l1; 
					while (l2 <= r2 && v2[q2[r2]] <= v2[mid]) --r2;
					q2[++r2] = mid--;
				}
			}
			if (i == len - 1 || mxdep1[path[i + 1]] < dis) return 1;
			if (j + 1 < len) {
				int mid2 = i + j + 1 >> 1;
				if (-i + v1[q1[l1]] > dis || (mid + 1 <= j && j + 1 + v2[q2[l2]] > dis)) continue;
				return 1;
			}
		}
		return 0;
	}
	void solveBF() {
		int res = inf;
		FOR (i, 0, (1 << n) - 1) {
			if (popc(i) != k) continue;
			FOR (j, 0, n - 1) flag[j] = (i >> j) & 1;
			int cnt = 0;
			FOR (j, 1, n) {
				for (int v: G[j]) {
					if (flag[j - 1] && flag[v - 1] && v > j) ++cnt;
				}
			}
			if (cnt < k - 2) continue;
			queue<int> q;
			FOR (j, 0, n - 1) 
				if (flag[j]) q.push(j + 1), dis[j + 1] = 0;
				else dis[j + 1] = inf; 
			while (SZ(q)) {
				int u = q.front(); q.pop();
				for (int v: G[u]) 
					if (dis[v] > dis[u] + 1) q.push(v), dis[v] = dis[u] + 1;
			}
			int ans = 0;
			FOR (j, 0, n - 1) chkmax(ans, dis[j + 1]);
			chkmin(res, ans);
		}
		cout << res << '\n';
	}
	void solve() {
		cin >> n >> k; A = B = d0 = d1 = 0;
		FOR (i, 1, n) G[i].clear(), dep[i] = mxdep1[i] = mxdep2[i] = val[i] = val2[i] = 0, on[i] = 0;
		FOR (i, 1, n - 1) {
			int u, v; cin >> u >> v;
			G[u].PB(v), G[v].PB(u);
		}
		if (n <= 20) return solveBF();
		find_d(1, 0, 0, A, d0);
		find_d(A, 0, 0, B, d1);
		if (k == 1) {
			cout << (d1 + 1) / 2 << '\n';
			return;
		}
		tot1 = tot2 = 0;
		dfs0(A, 0);
		swap(tot1, tot2);
		FOR (i, 1, n) swap(p1[i], p2[i]), swap(mxdep1[i], mxdep2[i]), swap(Fa1[i], Fa2[i]);
		dfs0(B, 0);
		len = 0; int u = B;
		while (u) on[u] = 1, path[len++] = u, u = Fa[u];
		FOR (i, 0, len - 1) predfs(path[i], 0);
		FOR (i, 0, len - 1) v1[i] = i + dep[path[i]], v2[i] = -i + dep[path[i]];
		int l = 0, r = (d1 + 1) / 2, mid;
		while (l < r) {
			mid = l + r >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		cout << l << '\n';
		
	}
}
bool Meb;
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int cid, T; cin >> cid >> T;
	while (T--) lyl::solve();
	// cerr << "Time: " << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n"; 
//	cerr << "Space: " << fabs(&Mbe - &Meb) / 1024.0 / 1024.0 << "MB\n";
	return 0;
}
