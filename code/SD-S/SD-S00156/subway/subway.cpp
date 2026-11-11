#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int M = 305;
const int N = 53;
const int D = 21;
int c, n, m, d, q, w[N], a[N][M], t[N][M], vis[N];
vector<pair<int, int> > e[N * M];
int dis[M][N * M];
void dij(int s) {
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, s));
	dis[s][s] = 0;
	while (!pq.empty()) {
		int d = -pq.top().first, u = pq.top().second;
		pq.pop();
		for (int i = 0; i < (int)e[u].size(); i++) {
			int val = e[u][i].first;
			int v = e[u][i].second;
			if (dis[s][v] > dis[s][u] + val) {
				dis[s][v] = dis[s][u] + val;
				pq.push(make_pair(-dis[s][v], v));
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j];
			cin >> t[i][j];
		}
		for (int j = 2; j <= k; j++) {
			e[n * i + a[i][j - 1]].push_back(make_pair(0, n * i + a[i][j]));
		} 
		for (int j = 1; j <= k; j++) {
			for (int l = 1; l <= n; l++) {
				e[a[i][j]].push_back(make_pair(t[i][j], l * n + a[i][j]));
				e[l * n + a[i][j]].push_back(make_pair(t[i][j], a[i][j]));
			}
		}
	}
	memset(dis, 0x3f3f3f, sizeof dis);
	for (int i = 1; i <= n; i++) dij(i);
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] << '\n';
	}
	return 0; 
}
