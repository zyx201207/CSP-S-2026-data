#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 105;

// freopen()
// 40pts on 18:03
// 关注 luogu@jackzhangcn2013 谢谢喵

int n, k;
vector<int> g[N];
bool is[N], vis[N];
void dfs(int u) {
	vis[u] = 1;
	for(int v : g[u]) {
		if(vis[v]) {
			continue;
		}
		if(!is[v]) {
			continue;
		}
		dfs(v);
	}
}
int dis[N];
int bfs(int s) {
	queue<int> q;
	q.push(s);
	for(int i = 1; i <= n; i++) {
		dis[i] = 1e18;
	}
	dis[s] = 0;
	int res = 1e18;
	while(!q.empty()) {
		int u = q.front();
//		cout << s << ' ' << u << endl;
		q.pop();
		if(is[u]) {
			res = min(res, dis[u]);
		}
		for(int v : g[u]) {
			if(dis[u] + 1 < dis[v]) {
				q.push(v);
				dis[v] = dis[u] + 1;
			}
		}
	}
	return res;
}
void solve() {
	cin >> n >> k;
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 1e18;
	for(int i = 0; i < (1 << n); i++) {
		vector<int> vec;
		for(int j = 1; j <= n; j++) {
			if(i & (1 << (j - 1))) {
				vec.emplace_back(j);
				is[j] = 1;
			}
		}
		if(vec.size() != k) {
			continue;
		}
		int c = 0;
		for(int i = 0; i < vec.size(); i++) {
			int u = vec[i];
			if(!vis[u]) {
				dfs(u);
				c++;
			}
		}
		if(c > 2) {
			continue;
		}
		int ma = 0;
		for(int u = 1; u <= n; u++) {
			ma = max(ma, bfs(u));
//			cout << bfs(u) << endl;
		}
		ans = min(ans, ma);
	}
	cout << ans << endl;
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--) {
		solve();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/