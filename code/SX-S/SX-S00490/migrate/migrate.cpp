#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
const int F = 1e18;
int x[N], dist[N];
int head[N], nxt[N], to[N], ecnt = 1;
int weight[N];
int cnt[N];
bool vis[N];

void add(int u, int v, int w) {
	to[ecnt] = v;
	nxt[ecnt] = head[u];
	head[u] = ecnt;
	weight[ecnt] = w;
	ecnt++;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n;
		int d;
		cin >> n >> d;
		cnt[1] = 1;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = 1; i <= n; i++) {
			head[i] = -1;
			dist[i] = F;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[i] <= d) {
					add(x[i], x[j], x[j] - x[i]);
				}
			}
		}
		int ans;
		for (int i = 1; i <= n; i++) {
			ans = 0;
			priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
			dist[x[i]] = 0;
			pq.push(make_pair(0, x[i]));
			while (!pq.empty()) {
				pair<int, int> cur = pq.top();
				pq.pop();
				int u = cur.second;
				if (vis[u])
					continue;
				vis[u] = 1;
				for (int e = head[u]; e != -1; e = nxt[e]) {
					int v = to[e];
					if (dist[v] > dist[u] + weight[e]) {
						dist[v] = dist[u] + weight[e];
						cnt[v] = cnt[u];
						pq.push(make_pair(dist[v], v));
					} else if (dist[v] == dist[u] + weight[e]) {
						cnt[v] += cnt[u];
						pq.push(make_pair(dist[v], v));
					}
				}
			}
			for (int k = 1; k <= n; k++) {
				if (cnt[x[k]] == 2)
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
