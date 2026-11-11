#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;
bool Mbe;
int n, k, Typ;
vector<int> e[N];
bool st[N];
int col[N], cn, d[N];
int mi[21][N], dn, dfn[N], dep[N], pre[N];

int get(int x, int y) {
	return dfn[x] < dfn[y] ? x : y;
}
void dfs(int id, int fa) {
	mi[0][dfn[id] = ++ dn] = fa; dep[id] = dep[fa] + 1;
	for (int it : e[id]) if (it != fa) dfs(it, id);
}
int lca(int u, int v) {
	if (u == v) return u;
	if ((u = dfn[u]) > (v = dfn[v])) swap(u, v);
	int k = __lg(v - (u ++ ));
	return get(mi[k][u], mi[k][v - (1 << k) + 1]);
}
int dist(int x, int y) {
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
void dfs1(int id) {
	col[id] = cn;
	for (int it : e[id]) {
		if (!st[it] || col[it]) continue ;
		dfs1(it);
	}
}

void solve1() {
	int ans = 1e9;
	for (int S = 0; S < 1 << n; S ++ ) {
		int cnt = 0;
		for (int i = 0; i < n; i ++ ) {
			if (S >> i & 1) {
				cnt ++ ; st[i + 1] = 1;
			} else st[i + 1] = 0;
		} if (cnt != k) continue ;
		cn = 0; for (int i = 1; i <= n; i ++ ) col[i] = 0;
		for (int i = 1; i <= n; i ++ ) if (st[i] && !col[i]) cn ++ , dfs1(i);
		if (cn > 2) continue ;
		int res = 0;
		for (int i = 1; i <= n; i ++ ) {
			int c = 1e9;
			for (int j = 1; j <= n; j ++ ) if (st[j]) c = min(c, dist(i, j));
			res = max(res, c);
		} ans = min(ans, res);
	} cout << ans << '\n';
}
void dfs2(int id, int fa) {
	d[id] = d[fa] + 1; pre[id] = fa;
	for (int it : e[id]) if (it != fa) dfs2(it, id);
} vector<int> occ;
bool chk(int x) {
	int p = occ[x], q = occ[(int)occ.size() - x - 1];
	for (int i = 1; i <= n; i ++ ) if (min(dist(i, p), dist(i, q)) > x) return 0;
	return 1;
}
void solve2() {
	int X = 0, maxd = 0;
	for (int i = 1; i <= n; i ++ ) if (maxd < dep[i]) maxd = dep[i], X = i;
	dfs2(X, 0);
	int Y = 0; maxd = 0;
	for (int i = 1; i <= n; i ++ ) if (maxd < d[i]) maxd = d[i], Y = i;
	occ.clear(); int p = Y;
	while (p != X) occ.push_back(p), p = pre[p];
	occ.push_back(X); reverse(occ.begin(), occ.end());
	int l = 1, r = (int)occ.size() - 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (chk(mid)) r = mid;
		else l = mid + 1;
	} cout << r << '\n';
}
bool chk2(int x) {
	int m = n / 2;
	if (k & 1) {
		int y = (k + 1) / 2;
		int p = x, q = (m + 1) - x;
		int r1 = p + y - 1, l2 = q - (y - 1) + 1;
		for (int i = r1; i <= l2; i ++ ) {
			if (min(abs(i - r1), abs(i - l2)) + 1 > x) return 0;
		} return 1;
	} else {
		int y = k / 2;
		int p = x, q = (m + 1) - x;
		int r1 = p + y - 1, l2 = q - y + 1; bool flg = 1;
		for (int i = r1; i <= l2; i ++ ) if (min(abs(i - r1), abs(i - l2)) + 1 > x) flg = 0;
		if (flg) return 1;
		y = k / 2 + 1;
		r1 = p + y - 1, l2 = q - (y - 2) + 1; flg = 1;
		for (int i = r1; i <= l2; i ++ ) if (min(abs(i - r1), abs(i - l2)) + 1 > x) flg = 0;
		return flg;
	}
}
void solve3() {
	if (k == n) {
		cout << "0\n"; return ;
	}
	int l = 1, r = n - 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (chk2(mid)) r = mid;
		else l = mid + 1;
	} cout << r << '\n';
}

void mian() {
	cin >> n >> k;
	for (int i = 1; i <= n; i ++ ) e[i].clear();
	for (int i = 0, u, v; i < n - 1; i ++ ) {
		cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
	} dn = 0; dfs(1, 0); 
	for (int i = 1; i <= __lg(n); i ++ ) for (int j = 1; j + (1 << i) - 1 <= n; j ++ )
		mi[i][j] = get(mi[i - 1][j], mi[i - 1][j + (1 << (i - 1))]);
	if (n == k) cout << "0\n"; 
	else if (n <= 10) { solve1(); }
	else if (k == 2) { solve2(); }
	else if (Typ >= 13 && Typ <= 14) solve3();
}

bool Med;
int main() {
	cerr << (&Mbe - &Med) / 1048576.0 << "MB\n";
	freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> Typ >> T;
	while (T -- ) mian();
	return 0;
}
