#include <bits/stdc++.h>

using namespace std;

int c, n, m, d, q, w[10001], a[1001][1001], t[1001][1001], dis[1001][1001];
vector<pair<int,int> > p[10001];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	memset(dis,0x3f,sizeof(dis));
	for (int i = 1; i <= m; i++) dis[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= 2 * k; j++) {
			cin >> a[i][j] >> t[i][j];
		}
		for (int x = 1; x <= n; x++) {
			for (int f = 1; f <= k; f++) {
				p[a[i][x]].push_back({a[i][f],t[i][x] + t[i][f]});
				p[a[i][f]].push_back({a[i][x],t[i][x] + t[i][f]});
			}
		}
	}
	for (int i = 1; i < m; i++) {
		for (auto [u,v] : p[i]) {
			dis[i][u] = min(dis[i][u], v + w[u] + w[i]);
		}
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		cout << dis[x][y] << endl;
	}
	return 0;
}
