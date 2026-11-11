#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 30, INF = 1e9;
int c, T, n, k, tmp = 0, res = 0;
int plan[MAXN], cnt = 0;
vector<int> edge[MAXN];
int mark[MAXN];
void dfs(int u, int pa) {
	mark[u] = 1;
	for(int v : edge[u]) {
		if(v == pa || !plan[v]) continue;
		dfs(v, u);
	}
}
queue<int> q;
int dis[MAXN];
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while(T--) {
		cin >> n >> k;
		for(int i = 1; i <= n; i++) edge[i].clear(), mark[i] = 0;
		for(int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		res = INF;
		for(int s = 0; s < (1 << n); s++) {
			cnt = 0;
			for(int d = 0; d < n; d++)
				plan[d + 1] = ((s >> d) & 1), cnt += plan[d + 1];
			if(cnt != k) continue;
			cnt = 0;
			for(int i = 1; i <= n; i++) mark[i] = 0;
			for(int i = 1; i <= n; i++)
				if(plan[i] && !mark[i]) dfs(i, 0), cnt++;
			if(cnt != 2) continue;
			tmp = 0;
			for(int i = 1; i <= n; i++) {
				mark[i] = dis[i] = 0;
				if(plan[i]) q.push(i), mark[i] = 1;
			}
			while(!q.empty()) {
				int u = q.front(); q.pop();
				tmp = max(tmp, dis[u]);
				for(int v : edge[u]) {
					if(mark[v]) continue;
					dis[v] = dis[u] + 1;
					mark[v] = 1;
					q.push(v);
				}
			}
			res = min(res, tmp);
		}
		cout << res << "\n";
	}
	return 0;
}
