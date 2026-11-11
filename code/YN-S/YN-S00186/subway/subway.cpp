#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int c, n, m, d, q;
int tt[1010][1010];
int dis[5010][5010];
int w[N], a[1010][1010], t[500][400][400], st, ed, vis[N];
vector<int>e[N];
int f[N];

void bfs(int s) {
	priority_queue<pair<int, int> >q;
	q.push({0, s});
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	dis[s][s] = 0;
	while (!q.empty()) {
		int x = q.top().second;
		q.pop();
		for (auto i : e[x]) {
			if (vis[i])
				continue;
			vis[i] = 1;
			for (int j = 1; j <= n; j++) {
//				cout << "s:" << x << " " << i << " " << dis[i] << "\n";
				if (dis[s][i] > dis[s][x] + t[j][i][x] && t[j][i][x] > 0) {
					dis[s][i] = dis[s][x] + t[j][i][x];
					q.push({-dis[s][i], i});
				}
//				cout << "e:" << x << " " << i << " " << dis[i] << "\n";
			}
		}
	}
	return ;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int j = 1; j <= x; j++) {
			cin >> a[i][j] >> tt[i][j];
		}
		for (int j = 1; j <= x; j++)
			for (int k = j; k <= x; k++) {
				e[a[i][j]].push_back(a[i][k]), e[a[i][k]].push_back(a[i][j]);
				t[i][a[i][j]][a[i][k]] = t[i][a[i][k]][a[i][j]] = tt[i][j] + tt[i][k];
			}
	}
//	for (int i = 1; i <= n; i++) {
//		cout << i << "\n";
//		for (int j = 1; j <= m; j++) {
//			for (int k = 1; k <= m; k++)
//				cout << t[i][j][k] << " ";
//			cout << "\n";
//		}
//	}
	while (q--) {
		cin >> st >> ed;
		if (!f[st])
			bfs(st), f[st] = 1;
		cout << dis[st][ed] + w[st] + w[ed] << "\n";
	}
	return 0;
}//ToonoHanna