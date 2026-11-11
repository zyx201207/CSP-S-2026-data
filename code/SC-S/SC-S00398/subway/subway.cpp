#include<bits/stdc++.h>
using namespace std;
const int N = 505, M = 2e4 + 5, INF = 1e9;
struct AC{
	int nx, lg;
};
vector<AC> edge[M+N];
int c, n, m, d, q;
int k;
int w[M];
int dist[M+N];
bool vis[M+N];
int main(){
//	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	bool f = 1;
	int h;
	for (int i = 1; i <= n; i ++) {
		cin >> k;
		for (int j = 1; j <= k; j ++) {
			int a, t;
			cin >> a >> t;
			if (i == 1 && j == 1) h = t;
			else if (h != t) f = 0;
			edge[a].push_back({m + i, t});
			edge[m + i].push_back({a, t});
		}
	}
	while(q --){
		int x, y;
		cin >> x >> y;
		for (int i = 1; i <= m+n; i ++){
			dist[i] = INF;
			vis[i] = 0;
		}
		dist[x] = 0;
		if (f) {
			queue<int> q;
			q.push(x);
			vis[x] = 1;
			while (!q.empty()){
				int u = q.front();
				q.pop();
				for (int i = 0; i < edge[u].size(); i ++){
					int v = edge[u][i].nx;
					if (!vis[v]) {
						vis[v] = 1;
						dist[v] = dist[u] + 1;
						q.push(v);
					}
				}
			}
			cout << w[x] + dist[y] * h + w[y] << '\n';
		} else {
			for (int step = 1; step <= m+n; step ++) {
				int minn = INF, u;
				for (int i = 1; i <= m+n; i ++) {
					if (!vis[i] && minn >= dist[i]) {
						minn = dist[i];
						u = i;
					}
				}
				vis[u] = 1;
				for (int i = 0; i < edge[u].size(); i ++) {
					int v = edge[u][i].nx;
					int g = edge[u][i].lg;
					if (dist[v] > dist[u] + g) {
						dist[v] = dist[u] + g;
					}
				}
			}
			cout << w[x] + dist[y] + w[y] << '\n';
		}
	}
	return 0;
}