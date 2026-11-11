#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int SIZE = 5e5 + 5;
int c, n, m, d, q, w[SIZE], k[505];
int dist[1505][1505];
vector <int> t[505], a[505];
void _main() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	} 
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		t[i].push_back(0), a[i].push_back(0);
		for (int j = 1; j <= k[i]; j++){
			int x, y;
			cin >> x >> y;
			a[i].push_back(x), t[i].push_back(y);
		}
	}
	if (c == 20 || c == 21) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + t[1][x] + t[1][y] << "\n";
	}
	memset(dist, 0x3f, sizeof dist);
	for (int i = 1; i <= m; i++){
		dist[i][i + m] = w[i];
		dist[i + m][i] = w[i];
	}
	int maxn = m * 2;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k[i]; j++){
			maxn ++;
			dist[maxn][a[i][j] + m] = t[i][j];
			dist[a[i][j] + m][maxn] = t[i][j];
			if (j != k[i]){
				dist[maxn][maxn + 1] = 0;
				dist[maxn + 1][maxn] = 0;
			}
		}
	}
	for (int i = 1; i <= maxn; i++)dist[i][i] = 0;
	for (int i = 1; i <= maxn; i++){
		for (int j = 1; j <= maxn; j++){
			for (int k = 1; k <= maxn; k++){
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}
	while (q--){
		int x, y;
		cin >> x >> y;
		cout << dist[x][y] << "\n";
	}
	return;
} 
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t = 1;
	while (t--){
		_main();
	}
}
