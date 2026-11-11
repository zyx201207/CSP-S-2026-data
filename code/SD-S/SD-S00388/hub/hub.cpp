#include <bits/stdc++.h>
using namespace std;
#define DBGMODE 0
#define dbg if(DBGMODE)cout
#define dnl if(DBGMODE)cout<<'\n'
#define ifd if(DBGMODE)
#define INF 2147483647
const int N = 13;
int c, t, n, k;
vector <int> g[N];
bool vis[N];
bool vvis[N];
void dfs (int start) {
	vvis[start] = 1;
	for (auto x : g[start]) {
		if (!vvis[x]) {
			dfs(x);
		}
	}
	return;
}
int dist[N];
struct mys {
	int id, d;
};
void bfs (int start) {
	for (int i = 0; i < N; ++ i) {
		dist[i] = -100000;
		vis[i] = 0;
	}
	queue <mys> q;
	q.push({start, 0});
	vis[start] = 1;
	while (q.size()) {
		mys cur = q.front();
		q.pop();
		for (auto x : g[cur.id]) {
			if (!vis[x]) {
				q.push({x, cur.d + 1});
				vis[x] = 1;
			}
		}
	}
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
	freopen ("hub.in","r",stdin);
	freopen ("hub.out","w",stdout);
	cin >> c >> t;
	while (t --) {
		cin >> n >> k;
		for (int i = 0; i < N; ++ i) {
			g[i].clear();
			vvis[i] = 0;
		}
		for (int i = 0; i < k; ++ i) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int parts = 0;
		int maxfd = -INF, ans = -INF;
		for (int i = 1; i <= n; ++ i) {
			if (!vvis[i]) {
				dfs (i);
				++ parts;
				bfs (i);
				int fdis = -10000, fid;
				for (int j = 1; j <= n; ++ j) {
					if (fdis < dist[i]) {
						fdis = dist[i];
						fid = i;
					}
				}
				bfs (fid);
				fdis = -10000;
				for (int j = 1; j <= n; ++ j) {
					if (fdis < dist[i]) {
						fdis = dist[i];
						fid = i;
					}
				}
				maxfd = max(maxfd, fid);
			}
		}
		if (parts <= 2) {
			ans = min(ans, fid);
		}
		cout << ans << '\n';
	}
	return 0;
}
