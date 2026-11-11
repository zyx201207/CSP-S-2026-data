#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) p << 1
#define rs(p) p << 1 | 1
#define lowbit(x) x&(-x)

const int N = 5e3 + 5;
const int P = 1e9 + 7;
const int INF = 1e18;

int n, k, vis[N], fa[N];
int mp[N][N], tot[N];

void init () {
	for (int i = 1; i <= n; i++) fa[i] = i;
}

int Find (int u) {
	if (fa[u] == u) return u;
	return fa[u] = Find(fa[u]);
}

void merge (int u, int v) {
	u = Find(u); v = Find(v);
	if (u == v) return ;
	fa[u] = v;
}

void solve () {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			mp[i][j] = INF;
		}
		mp[i][i] = 0;
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		mp[u][v] = mp[v][u] = 1;
	}
	
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				mp[i][j] = mp[j][i] = min(mp[i][j], mp[i][k] + mp[k][j]);
	
	int ans = INF;
	for (int s = 0; s < (1 << n); s++) {
		int cnt = 0; init();
		for (int i = 1; i <= n; i++) vis[i] = tot[i] = 0;
		for (int i = 1; i <= n; i++)
			vis[i] = (s >> (i - 1)) & 1, cnt += vis[i];
		if (cnt != k) continue;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (vis[i] && vis[j] && mp[i][j] == 1)
					merge(i, j);
		for (int i = 1; i <= n; i++)
			if (vis[i]) tot[Find(i)]++;
		cnt = 0;
		for (int i = 1; i <= n; i++)
			if (tot[i]) cnt++;
		if (cnt != 2) continue;
		int res = 0;
		for (int i = 1; i <= n; i++) {
			int tmp = INF;
			for (int j = 1; j <= n; j++) {
				if (vis[j]) tmp = min(tmp, mp[i][j]);
			}
			res = max(res, tmp);
		}
		ans = min(ans, res);
	}
	cout << ans << "\n";
}

signed main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, T = 1; cin >> c >> T;
	while(T--) solve();
	return 0;
}