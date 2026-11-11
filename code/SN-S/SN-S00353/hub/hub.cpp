#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3fLL;
bool BE;
int n, k, st[21][N], dfn[N], tim, dep[N];
vector<int> t[N];
bool ED;


void dfs(int x, int fa) {
	dfn[x] = ++tim;
	dep[x] = dep[fa] + 1;
	st[0][tim] = fa;
	for (int y : t[x]) {
		if (y == fa) continue;
		dfs(y, x);
	}
}


bool cmp(int x, int y) {
	return dfn[x] < dfn[y];
}


int lca(int x, int y) {
	if (x == y) return x;
	if (dfn[x] > dfn[y]) swap(x, y);
	int l = dfn[x] + 1, r = dfn[y];
	int k = __lg(r - l + 1);
	return min(st[k][l], st[k][r - (1 << k) + 1], cmp);
}


namespace Sub1 {
	int a[15], b[15], fa[15];
	
	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	
	void merge(int x, int y) {
		fa[find(x)] = find(y);
	}
	
	void solve() {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			a[i] = u;
			b[i] = v;
			t[u].push_back(v);
			t[v].push_back(u);
		}
		dfs(1, 0);
		for (int i = 1; i <= 20; i++) {
			for (int j = 1; j + (1 << i) - 1 <= n; j++) {
				int k = j + (1 << (i - 1));
				st[i][j] = min(st[i - 1][j], st[i - 1][k], cmp);
			}
		}
		int ans = INF;
		for (int sta = 0; sta < (1 << n); sta++) {
			if (__builtin_popcount(sta) != k) continue;
			for (int i = 1; i <= n; i++) fa[i] = i;
			for (int i = 1; i < n; i++) {
				int u = a[i], v = b[i];
				if (((sta >> (u - 1)) & 1) && ((sta >> (v - 1)) & 1)) {
					merge(u, v);
				}
			}
			set<int> st;
			for (int i = 1; i <= n; i++) {
				if ((sta >> (i - 1)) & 1) st.insert(find(i));
			}
			if (st.size() > 2) continue;
			int mxd = 0;
			for (int i = 1; i <= n; i++) {
				int mnd = INF;
				for (int j = 1; j <= n; j++) if ((sta >> (j - 1)) & 1) {
					int dis = dep[i] + dep[j] - 2 * dep[lca(i, j)];
					mnd = min(mnd, dis);
				}
				mxd = max(mxd, mnd);
			}
			ans = min(ans, mxd);
		}
		cout << ans << '\n';
	}
}


void clear() {
	tim = 0;
	for (int i = 1; i <= n; i++) t[i].clear();
}


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	cerr << ((&ED - &BE) >> 20) << "Mib\n";
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int tid, T;
	cin >> tid >> T;
	while (T--) {
		Sub1::solve();
		clear();
	}
	return 0;
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
*/
