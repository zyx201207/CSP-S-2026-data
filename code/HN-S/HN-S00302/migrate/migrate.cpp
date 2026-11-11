#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node {
	int v, w;
};
int c, t;
int n, d;
bool vis[2000010];
int a[2000010];
int dis[2000010], ans[2000010];
vector<int> e[2000010];
priority_queue<node> q;
bool operator < (const node a, const node b) {
	return a.w > b.w;
}
void dij(int s) {
	for (int i = s; i <= n; i++) {
		dis[i] = 0x3f3f3f3f;
		vis[i] = false;
	}
	q.push({s, 0});
	dis[s] = 0;
	ans[s] = 1;
	while (!q.empty()) {
		int u = q.top().v;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = 0; i < e[u].size(); i++) {
			int v = e[u][i];
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				ans[v] = ans[u];
				if (!vis[v]) q.push({v, dis[v]});
			}
			else if (dis[v] == dis[u] + 1) {
				ans[v] += ans[u];
			}
		}
	}
	return;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (a[j] - a[i] > d) break;
				e[i].push_back(j);
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			dij(i);
			for (int j = i; j <= n; j++) {
				if (ans[j] == 2) cnt++;
				ans[j] = 0;
			}
		}
		cout << cnt << '\n';
		for (int i = 1; i <= n; i++) {
			e[i].clear();
		}
	}
	return 0;
}
