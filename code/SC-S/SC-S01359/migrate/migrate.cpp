#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,j,k) for(int i=j;i<=k;i++)
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
	int c, tt;
	cin >> c >> tt;
	while (tt--) {
		int n, d;
		cin >> n >> d;
		vector<int>x(n + 1);
		F(i, 1, n)cin >> x[i];
		vector<vector<int>>adj(n + 1);
		F(u, 1, n) {
			F(v, u + 1, n) {
				if(u == v)continue;
				if(x[v] - x[u] <= d) {
					adj[u].emplace_back(v);
				}
			}
		}
		queue<pair<int, int>>q;
		vector<vector<int>>dis(n + 1, vector<int>(n + 1, LLONG_MAX));
		vector<vector<int>>cnt(n + 1, vector<int>(n + 1, 0));
		vector<vector<bool>>vis(n + 1, vector<bool>(n + 1));
		F(s, 1, n) {
			dis[s][s] = 0;
			cnt[s][s] = 1;
			q.emplace(dis[s][s], s);
			while (!q.empty()) {
				int u = q.front().second;
				q.pop();
				if (vis[s][u])continue;
				vis[s][u] = 1;
				for (int v : adj[u]) {
					if (dis[s][v] > dis[s][u] + 1) {
						dis[s][v] = dis[s][u] + 1;
						cnt[s][v] = cnt[s][u];
						if (!vis[s][v])q.emplace(dis[s][v], v);
					} else if (dis[s][v] == dis[s][u] + 1) {
						cnt[s][v] += cnt[s][u];
					}
				}
			}
		}
		int ans = 0;
		F(i, 1, n) {
			F(j, i + 1, n) {
				if (cnt[i][j] == 2) ans ++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}