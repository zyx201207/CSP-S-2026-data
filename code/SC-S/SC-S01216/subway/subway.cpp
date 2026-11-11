#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 505;
const int MAXM = 5e5+5;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

int c, n, m, d, q, a, t;
int w[MAXM], k[MAXN];
int dis[MAXN][MAXN];

vector<pair<int, int>> G[MAXM];

void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dis[i][j] == INF)	cout << "INF ";
			else	cout << dis[i][j] << " ";
		}
		cout << "\n";
	}
}

void init() {
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++)	dis[i][i] = 0;
	for (int i = 1; i <= m; i++) {
//		cout << "Station " << i << ":\n";
		for (int p1 = 0; p1 < G[i].size(); p1++)
			for (int p2 = 0; p2 < G[i].size(); p2++) {
				if (p1 == p2) continue;
				int to1 = G[i][p1].first, to2 = G[i][p2].first;
				int t1 = G[i][p1].second, t2 = G[i][p2].second;
//				cout << to1 << " " << t1 << " " << to2 << " " << t2 << "\n";
				dis[to1][to2] = dis[to2][to1] = min(dis[to1][to2], t1 + t2);
			}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	
//	print();
}

int solve(int x, int y) {
	int ans = INF;
	for (int i = 0; i < G[x].size(); i++)
		for (int j = 0; j < G[y].size(); j++) {
			int to1 = G[x][i].first, to2 = G[y][j].first;
			int t1 = G[x][i].second, t2 = G[y][j].second;
			int tans = t1 + t2 + dis[to1][to2];
			ans = min(ans, tans);
		}
	return ans + w[x] + w[y];
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)	cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a >> t;
			G[a].push_back({i, t});
		}
	}
	init();

	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << solve(x, y) << "\n";
	}

	return 0;
}