#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>
#define ll long long
using namespace std;
int c, t;
int n, k;
vector<int> edge[1000050];
bool vis[1000050];
ll idx, maxdep = -1;
void dfs1(int id, int deep) {
	if (deep > maxdep) {
		maxdep = deep;
		idx = id;
	}
	for (int v : edge[id]) {
		if (!vis[v]) vis[v] = true, dfs1(v, deep + 1), vis[v] = false;
	}
}
ll ddis;
ll dfs2(int id) {
	ddis = 1;
	for (int v : edge[id]) {
		if (!vis[v]) vis[v] = true, ddis = max(ddis, dfs2(v) + 1), vis[v] = false;
	}
	return ddis;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> c >> t;
	while (t--) {
		for (int i = 1; i <= n; ++i)
			edge[i].clear();
		cin >> n >> k;
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v), edge[v].push_back(u);
		}
		maxdep = -1; 
		memset(vis, 0, sizeof(vis));
		vis[1] = true;
		dfs1(1, 0);
		memset(vis, 0, sizeof(vis));
		vis[idx] = true;
		//cout << dfs2(idx) << ' ';
		cout << ceil((double)(dfs2(idx) - k) / 3) << '\n';
	}
	return 0;
}
