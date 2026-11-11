#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
#define Init ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const int N = 2e6 + 5;
const ll INF = 4e18;
int c, T, n, a[N], dp[N];
ll d, x[N], dis[N];

void Dijkstra(int s, vector<int> G[]) {
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		if (i != s)
			dis[i] = INF;
		else
			dis[i] = 0;
	}
	queue<pii> q;
	q.push(make_pair(0, s));
	dp[s] = 1;
	while (!q.empty()) {
		int u = q.front().second;
		q.pop();
		int l = G[u].size();
		for (int j = 0; j < l; j++) {
			int v = G[u][j];
			if (dis[u] + 1 < dis[v]) {
				dis[v] = dis[u] + 1;
				dp[v] = dp[u];
				q.push({-dis[v], v});
			} else if (dis[u] + 1 == dis[v]) {
				dp[v] += dp[u];
			}
		}
	}
}

int main(void) {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		vector<int> G[n + 2];
		for (int i = 1; i <= n; i++) {
			G[i].clear();
			for (int j = 2; j <= n; j++) {
				if (x[j] - x[i] <= d)
					G[i].push_back(j);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			Dijkstra(i, G);
			for (int j = i + 1; j <= n; j++) {
				if (dp[j] == 2)
					ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}