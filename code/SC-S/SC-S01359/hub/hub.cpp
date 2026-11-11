#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,j,k) for(int i=j;i<=k;i++)
int popcount(int x) {
	int res = 0;
	while (x) {
		if (x & 1) res++;
		x >>= 1;
	}
	return res;
}
bool getbit(int x, int i) {
	return ((x >> (i - 1)) & 1ll);
}
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
	int c, tt;
	cin >> c >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<vector<int>>adj(n + 1);
		F(i, 1, n - 1) {
			int u, v;
			cin >> u >> v;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
		vector<vector<int>>dis(n + 1, vector<int>(n + 1));
		F(rt, 1, n) {
			function<void(int, int, int)> dfs = [&](int u, int fa, int d) -> void{
				dis[rt][u] = d;
				for (auto v : adj[u]) {
					if (v == fa)continue;
					dfs(v, u, d + 1);
				}
			};
			dfs(rt, 0, 0);
		}
		int maxstate = (1LL << n) - 1;
		int ans = LLONG_MAX;

		F(state, 0, maxstate) {
			if (popcount(state) != k) continue;

			vector<bool> unlock(n + 1);
			set<int>S;
			F(i, 1, n) {
				unlock[i] = getbit(state, i);
			}
			vector<bool>vis(n + 1);
			function<void(int, int)> dfs__ = [&](int u, int fa) -> void{
				vis[u] = 1;
				for (auto v : adj[u]) {
					if (v == fa)continue;
					if (!vis[v] && unlock[v])dfs__(v, u);
				}
			};
			int cnt = 0;
			F(i, 1, n) {
				if (unlock[i])S.insert(i);
				if (!vis[i] && unlock[i]) {
					dfs__(i, 0);
					cnt++;
				}
			}
			if (cnt > 2)continue;

			int _thisf = LLONG_MIN;
			F(i, 1, n) {
				int di = LLONG_MAX;
				for (int j : S)di = min(di, dis[i][j]);
				_thisf = max(_thisf, di);
			}
			ans = min (ans, _thisf);
		}
		cout << ans << '\n';
	}
	return 0;
}