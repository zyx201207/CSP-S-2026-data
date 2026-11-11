#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll INF2 = 0x3f3f3f3f3f3f3f3f;

int c, t;
const int N = 1e6 + 10;
int n, k;


vector<int> G[N];
int vis[N];
int dep[N], fa[N];
void dfs1(int u, int f) {
	dep[u] = dep[f]+1;
	fa[u] = f;
	for (auto v : G[u]) {
		if (v ^ f) dfs1(v, u);
	}
}
void dfs(int u, int f) {
	vis[u] = 0;
	for (auto v : G[u]) {
		if (v ^ f && vis[v] == 1) dfs(v, u);
	}
}
bool check(int mask) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (mask & (1 << (i-1))) {
			vis[i] = 1;	
			cnt++;
		}
	}
	if (cnt ^ k) return false;
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) {
			dfs(i, 0);
			cnt++;
		}
	}
	if (cnt > 2) return false;
	
	return true;
}
ll dt(int u, int v) {
	ll cnt = 0;
	while (u ^ v) {
		if (dep[u] < dep[v]) swap(u, v);
		cnt++;
		u = fa[u];
	}
	return cnt;
}
ll rst(int mask) {
	vector<int> s;
	s.push_back(-1);
	for (int i = 1; i <= n; i++) {
		if (mask & (1 << (i-1))) {
			s.push_back(i);
		}
	}
	
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll dis = INF;
		for (int j = 1; j <= k; j++) {
			dis = min(dis, dt(i, s[j]));
		}
		ans = max(ans, dis);
	}
	return ans;
}
void solve1() {
	for (int i = 1; i <= n; i++) G[i].clear();
	memset(dep, 0, sizeof dep);
	memset(fa, 0, sizeof fa);
	memset(vis, 0, sizeof vis);
	
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1, 0);
	
	ll ret = INF; 
	for (int mask = 0; mask < (1 << (n-1)); mask++) {
		if (check(mask)) {
			ret = min(ret, rst(mask));
		}
	}
	cout << ret << '\n';
}

signed main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(),cin.tie(0);

	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		solve1();
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

*/
