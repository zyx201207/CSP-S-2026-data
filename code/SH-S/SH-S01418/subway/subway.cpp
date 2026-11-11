#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
const int maxn = 505;
const int maxm = 1005;
const ull INF = 1e9 + 5;
int c, n, m, d, q;
ull w[maxm], dis[maxm][maxm], ot[maxm][maxm], a[maxm], t[maxm];
vector<int> g[maxm];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	memset(dis, INF, sizeof(dis));
	
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	
	for (int i = 1; i <= n; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 1; j <= cnt; j++) {
			int x, y;
			cin >> x >> y;
			a[j] = x;
			t[a[j]] = y;
		}
		for (int j = 1; j <= cnt; j++) {
			for (int k = j + 1; k <= cnt; k++) {
				dis[a[j]][a[k]] = min(dis[a[j]][a[k]], t[a[j]] + t[a[k]]);
				dis[a[k]][a[j]] = min(dis[a[k]][a[j]], t[a[j]] + t[a[k]]);
			}
		}
	}
	
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] << endl;
	}
	return 0;
} 
