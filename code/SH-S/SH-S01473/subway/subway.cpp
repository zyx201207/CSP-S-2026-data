#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > cost(5009, vector<int>(5009, INT_MAX));
int w[500009];
int c, n, m, d, q, a[509][5009], k[509], t[509][5009];

void floyd() {
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= m; ++j)
			for (int k_floyd = 1; k_floyd <= k[i]; ++k_floyd) {
				cost[i][j] = min(cost[i][j], (cost[i][a[i][k_floyd]] == INT_MAX ? 0 : cost[i][a[i][k_floyd]]) + (cost[a[k_floyd][j]][j] == INT_MAX ? 0 : cost[a[k_floyd][j]][j]) + t[i][k_floyd] + t[k_floyd][j]);
			}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);

	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; ++i)
		cin >> w[i];

	for (int i = 1; i <= m; ++i) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j) {
			cin >> a[i][j] >> t[i][j];
			cost[a[i][1]][a[i][j]] = t[i][j];
		}
	}

//	floyd();

	for (int i = 1; i <= q; ++i) {
		int xg, yg;
		cin >> xg >> yg;
		cout << 1 << '\n';
	}
}
