#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int c, t, n, k, vis[N], ans, dis[N];
vector <int> a[N];
queue <int> q;
void dfs(int p, int x) {
	vis[p] = 1;
	for(auto it : a[p]) {
		if(x & (1 << it) && !vis[it]) {
			dfs(it, x);
		}
	}
}
void bfs(int p) {
	vis[p] = 1;
	for(auto it : a[p]) {
		if(!vis[it]) {
			dis[it] = dis[p] + 1;
			q.push(it);
			vis[it] = 1;
		}
	}
}
void dfs1(int p, int f) {
	// cerr << p << ' ' << f << '\n';
	for(auto it : a[p]) {
		if(it == f) {
			continue;
		}
		dis[it] = dis[p] + 1;
		dfs1(it, p);
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t --) {
		ans = 1e9;
		cin >> n >> k;
		for(int i = 0; i <= n; i ++) {
			a[i].clear();
		}
		for(int i = 1; i < n; i ++) {
			int u, v;
			cin >> u >> v;
			u --, v --;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		if(c == 13 || c == 14) {
			if(n == k) {
				cout << 0 << '\n';
				continue;
			}
			cout << (int)max(ceil((double)(1.0 * n / 2 + 1 - k) / 4), (double)1) << '\n';
		}
		else if(n <= 10) {
			for(int i = 0; i < (1 << n); i ++) {
				for(int j = 0; j <= n; j ++) {
					vis[j] = 0;
					dis[j] = 0;
				}
				int cnt = 0;
				for(int j = 0; j < n; j ++) {
					if(i & (1 << j)) {
						cnt ++;
					}
				}
				if(cnt != k) {
					continue;
				}
				cnt = 0;
				for(int j = 0; j < n; j ++) {
					if(i & (1 << j)) {
						if(!vis[j]) {
							cnt ++;
							dfs(j, i);
						}
					}
				}
				if(cnt > 2) {
					continue;
				}
				for(int j = 0; j <= n; j ++) {
					vis[j] = 0;
				}
				for(int j = 0; j < n; j ++) {
					if(i & (1 << j)) {
						vis[j] = 1;
						q.push(j);
					}
				}
				while(q.size()) {
					bfs(q.front());
					q.pop();
				}
				int res = 0;
				for(int j = 0; j < n; j ++) {
					res = max(res, dis[j]);
				}
				ans = min(ans, res);
			}
			cout << ans << '\n';
			continue;
		}
		else if(k == 2) {
			dis[0] = 0;
			dfs1(0, n + 1);
			int id = 0;
			for(int i = 0; i < n; i ++) {
				if(dis[i] > dis[id]) {
					id = i;
				}
			}
			dis[id] = 0;
			dfs(id, n + 1);
			int mx = 0;
			for(int i = 0; i < n; i ++) {
				mx = max(mx, dis[i]);
			}
			cout << ceil(1.0 * mx / 4) << '\n';
		}
	}
	return 0;
}