#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int c, T, k;
int n, dis[N], vis[N], f[N], siz[N], Max[N], cur;
vector<int> G[N];
int lowbit(int x) {
	return ((x) & (-x));
}
int count(int x) {
	int cnt = 0;
	while (x) x -= lowbit(x), cnt ++;
	return cnt; 
}
void dfs(int u, int fa) {
	f[u] = 1;
	for (int v : G[u]) {
		if (v == fa) continue;
		if (vis[v]) dfs(v, u);
	}
}
void dfs2(int u, int fa, int d) {
	dis[u] = min(dis[u], d);
	for (int v : G[u]) {
		if (v == fa) continue;
		dfs2(v, u, d + 1);
	}
}
void getroot(int u, int fa, int tot) {
	f[u] = fa;
	siz[u] = 1, Max[u] = 0;
	for (int v : G[u]) {
		if (vis[v] || v == fa) continue;
		getroot(v, u, tot);
		siz[u] += siz[v], Max[u] = max(Max[u], siz[v]); 
	}
	Max[u] = max(Max[u], tot - siz[u]);
	if (Max[cur] > Max[u]) cur = u;
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while (T --) {
		cin >> n >> k;
		for (int i = 1; i <= n; i ++) G[i].clear(), vis[i] = f[i] = dis[i] = siz[i] = Max[i] = 0;
		for (int i = 1, u, v; i < n; i ++) {
			cin >> u >> v;
			G[u].push_back(v), G[v].push_back(u);
		}
		if (c <= 3) {
			int ans = 1e9;
			for (int i = 0; i < (1 << n); i ++) {
				if (count(i) != k) continue;
				for (int j = 1; j <= n; j ++) {
					dis[j] = 1e9, vis[j] = f[j] = 0;
				}
				for (int j = 0; j < n; j ++) {
					if ((i >> j) & 1) {
						vis[j + 1] = 1, dis[j + 1] = 0;
					}
				} 
				int cnt = 0;
				for (int j = 1; j <= n; j ++) {
					if (vis[j] && !f[j]) {
						dfs(j, 0), cnt ++;
					}
					if (vis[j]) dfs2(j, 0, 0);
				}
				if (cnt > 2) continue;
				int res = 0;
				for (int j = 1; j <= n; j ++) res = max(res, dis[j]);
				ans = min(ans, res);
			}
			cout <<ans <<'\n';
			continue;
		}
		if (c == 13 || c == 14) {
			int m = n / 2;
			int las = m - k;
			if (las <= 0) {
				cout << "0\n";
				continue;
			} else {
				if (las < m) {
					cout <<"1\n";
				} else {
					if (k == 1) {
						cout << m / 2 + 1 <<'\n';
					} else {
						if (k & 1) {
							cout << (m / 2 - k / 2) / 2 + 1 <<'\n';
						} else {
							cout << (m / 2 + (m & 1) - k / 2) / 2 <<'\n';
						}
					}
				}
			}
		}
		if (k == 2) {
			Max[0] = 1e9;
			cur = 0;
			memset(dis, 0x3f, sizeof dis);
			getroot(1, 0, n);
			int to = 0, s = 0;
			for (int v : G[cur]) {
				if ((v == f[cur] && Max[cur] == n - siz[cur] + 1) || siz[v] == Max[cur]) {
					to = v;
					s = Max[cur];
					break;
				}
			}
			vis[to] = vis[cur] = 1;
			int u = cur;
			cur = 0;
			getroot(to, 0, s);
			dfs2(cur, 0, 0);
			cur = 0;
			getroot(u, 0, n - s);
			dfs2(cur, 0, 0);
			int ans = 0;
			for (int i = 1; i <= n; i ++) {
				ans = max(ans, dis[i]);
			}
			cout << ans << '\n';
			continue;
		}

	}
	return 0;
}
