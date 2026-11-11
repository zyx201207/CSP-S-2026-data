#include <bits/stdc++.h>
using namespace std;
int n, k;
int c, T;
int dis[1000005];
bool vis[1000005];
long long d, ans;

struct path {
	int to, val;
};
vector<path> mp[1000005];

struct node1 {
	int to, val;
	friend bool operator > (const node1 a, const node1 b) {
		return a.val > b.val;
	}
};
priority_queue<node1, vector<node1>, greater<node1> > q;

void dijk(int s) {
	for (int i = 1; i <= n; i++) {
		dis[i] = 0x7fffffff;
		vis[i] = 0;
	}
	dis[s] = 0;
	node1 tmp = {s, 0};
	vis[s] = 1;
	q.push(tmp);
	while (!q.empty()) {

		int u = q.top().to;
		q.pop();
		if (!vis[u])
			continue;
		vis[u] = 1;
		//cout << mp[u].size() << " ";
		for (int i = 0; i < mp[u].size(); i++) {
			//int p = mp[u][i].to;
			//int a1 = dis[mp[u][i].to];
			//long long a2 = dis[u] + mp[u][i].val;
			if (dis[mp[u][i].to] > 1ll * (dis[u] + mp[u][i].val)) {
				dis[mp[u][i].to] = dis[u] + mp[u][i].val;
				vis[mp[u][i].to] = 1;
				q.push({mp[u][i].to, dis[mp[u][i].to]});
			}
		}
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> c >> T;
	while (T--) {

		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			mp[u].push_back({v, 1});
			mp[v].push_back({u, 1});
		}
		int sum = 0, d = 0, ans = 0x7fffffff;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				sum = 0x7fffffff;
				dijk(i);
				for (int l = 1; l <= n; l++) {
					if (l == j || l == i)
						continue;
					sum = min(sum, dis[l]) ;
				}
				dijk(j);
				for (int l = 1; l <= n; l++) {
					if (l == i || l == j)
						continue;
					sum = min(sum, dis[l]) ;
				}
				d = max(d, sum);
				ans = min(ans, d);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}