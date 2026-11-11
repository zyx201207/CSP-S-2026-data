#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, k;
vector<int> G[1000005];
ll dis[1005][1005];
int fa[1000005];
int find(int x) {
//	cout << 1;
	if (x != fa[x]) fa[x] = find(fa[x]);
	return fa[x];
}
bool vis[1000005];
struct Edge {
	ll to, w;
	bool operator< (const Edge& c) const {
		return w > c.w;
	}
};
void dijkstra (int s) {
	for (int i = 1; i <= n; i++) dis[s][i] = 0x3f3f3f3f3f3f3f3f, vis[i] = false;
	priority_queue<Edge> q;
	q.push({s, 0});
	dis[s][s] = 0;
	while (q.size()) {
		Edge p = q.top();
		q.pop();
		if (vis[p.to]) continue;
		vis[p.to] = true;
		for (auto e : G[p.to]) {
			if (dis[s][e] > dis[s][p.to] + 1) {
				dis[s][e] = dis[s][p.to] + 1;
				q.push({e, dis[s][e]});
			}
		} 
	}
}
bool dvis[100005];
bool bvis[1000005];
void bfs1 (int s) {
	queue<int> q;
	q.push(s);
	while (q.size()) {
		int p = q.front();
		q.pop();
		if (!dvis[p]) continue;
		if (bvis[p]) continue;
		bvis[p] = true;
		for (int v : G[p]) q.push(v);
	}	
}
bool bvis2[1000005];
bool bfs2 (int s) {
	if (!bvis[s] || bvis2[s]) return false;
	queue<int> q;
	q.push(s);
	while (q.size()) {
		int p = q.front();
		q.pop();
		if (bvis2[p] || !bvis[p]) continue;
		bvis2[p] = true;
		for (int v : G[p]) q.push(v);
	}
	return true;
}
vector<int> vec;
ll minn = 1e18;
void dfs (int dep) {
	if (dep == k) {
		for (int i = 1; i <= n; i++) fa[i] = i, bvis[i] = false;
		for (int u : vec) bfs1(u);
		int cnnt = 0;
		for (int i = 1; i <= n; i++) cnnt += bfs2(i);
		if (cnnt == 2) {
			ll maxx = 0;
			for (int i = 1; i <= n; i++) {
				ll minn2 = 1e18;
				for (int j : vec) {
					minn2 = min (minn2, dis[i][j]);
				}
				if (dvis[i]) minn2 = 0;
				maxx = max(maxx, minn2);
			}
			minn = min(minn, maxx);
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!dvis[i]) {
			vec.push_back(i);
			dvis[i] = true;
			dfs (dep + 1);
			vec.push_back(i);
			dvis[i] = false;
		}
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			G[i].clear();
			fa[i] = i;
			dvis[i] = false;
		}
		vec.clear();
		minn = 1e18;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) dijkstra(i);
		dfs (0);
		cout << minn << '\n';
	}
	return 0;
} 
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/