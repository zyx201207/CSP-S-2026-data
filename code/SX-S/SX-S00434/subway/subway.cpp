#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005], dis[5005][5005];
int num[1005];
int w[1005], a[1005], t[1005];
bool vis[5005][5005];
int c, n, m, d, q;

struct node {
	int dt1, dt2;
};

bool operator < (node x, node y) {
	return x.dt1 > y.dt1;
}

void dij(int s) {
	dis[s][s] = 0;
	vis[s][s] = 0;
	priority_queue<node>pq;
	pq.push({s, 0});
	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();
		if (vis[s][now.dt1])
			continue;
		for (int i = 1; i <= m; i++) {
			if (vis[s][i])
				continue;
			if (now.dt2 + dp[now.dt1][i] < dis[s][i])
				dis[s][i] = now.dt2 + dp[now.dt1][i], pq.push({i, dis[s][i]});
		}
		vis[s][now.dt1] = 1;
	}
}

int main() {
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dp, 0x7e, sizeof dp);
	memset(dis, 0x7e, sizeof dis);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int ttt;
		cin >> ttt;
		for (int j = 1; j <= ttt; j++)
			cin >> a[j] >> t[j];
		for (int j = 1; j <= ttt; j++) {
			for (int k = 1; k <= ttt; k++) {
				if (j == k)
					continue;
//				cout << a[j] << "," << a[k] << "," << t[j] << "," << t[k] << endl;
				dp[a[k]][a[j]] = dp[a[j]][a[k]] = min(dp[a[j]][a[k]], t[j] + t[k]);
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		dij(i);
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] << endl;
	}
	return 0;
}
