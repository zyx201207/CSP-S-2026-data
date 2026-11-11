#include <bits/stdc++.h>
#define LL long long
#define pil pair<int, LL> 
using namespace std;
const int N = 503, M = 5e5+3;
int c, n, m, d, q;
LL g[N][N]; // 线路之间的的floyd.
LL w[N];
vector<pil> line[M]; // 每个站台经过的线路 

void floyd() {
	for (int k = 1; k <= n; k++) {
		g[k][k] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
//				if (i == 1 && j == 3) {
//					cout << g[i][k] << ' ' << g[k][j] << endl;
//				}
				if (g[i][j] > g[i][k] + g[k][j]) {
					g[j][i] = g[i][j] = g[i][k] + g[k][j];
				}
			}
		}
	} // 1.25e8
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << g[i][j] << ' ';
//		}
//		cout << '\n';
//	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(g, 0x3f, sizeof g);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int t, w; cin >> t >> w;
			line[t].push_back({i, w});
		}
	} 
	
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < line[i].size(); j++) {
			for (int k = j+1; k < line[i].size(); k++) {
				LL &p = g[line[i][j].first][line[i][k].first];
				LL &pp = g[line[i][k].first][line[i][j].first];
				p = min(p, line[i][j].second + line[i][k].second);
				pp = p;
				// 2e8
				
			}
		}
	} 
	floyd();
	while (q--) {
		int x, y;
		cin >> x >> y;
		LL res = LLONG_MAX;
		for (auto i : line[x]) {
			for (auto j : line[y]) {
				res = min(res, g[i.first][j.first]+ i.second + j.second);
			}
		}
		cout << res + w[x] + w[y] << '\n';
	} // 1e7...
	return 0;
} 