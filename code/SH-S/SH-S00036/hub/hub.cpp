#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 105;
bool vis[MAXN];
int n, k, ans, dist[MAXN][MAXN];
vector<int> graph[MAXN];

void dfs(int x, int tot, int sum){
	if (tot == 3 || n - x + 1 + sum < k)
		return;
	if (x == n + 1 || sum == k){
		int cnt = 0;
		for (int i = 1; i <= n; ++i){
			int res = INF;
			for (int j = 1; j <= n; ++j){
				if (vis[j])
					res = min(res, dist[i][j]);
			}
			cnt = max(cnt, res);
		}
		ans = min(ans, cnt);
		return;
	}
	bool found = false;
	int now = tot;
	for (int y : graph[x]){
		if (vis[y]){
			found = true;
			break;
		}
	}
	if (!found)
		++now;
	vis[x] = true;
	dfs(x + 1, now, sum + 1);
	vis[x] = false;
	dfs(x + 1, tot, sum);
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--){
		cin >> n >> k;
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				if (i == j)
					dist[i][j] = 0;
				else
					dist[i][j] = INF;
			}
			graph[i].clear();
		}
		for (int i = 1; i <= n - 1; ++i){
			int u, v;
			cin >> u >> v;
			dist[u][v] = dist[v][u] = 1;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		ans = INF;
		dfs(1, 0, 0);
		cout << ans << '\n';
	}
}
