#include <bits/stdc++.h>
using namespace std;
int A[500010];
long long dis[510][510];
vector<pair<int, int>>B[500010];
vector<int>Z[510];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) {

		cin >> A[i];
	}

	for (int i = 1; i <= n; i++) {

		int a;
		cin >> a;

		for (int j = 1; j <= a; j++) {

			int u, t;
			cin >> u >> t;
			Z[i].push_back(u);
			B[u].push_back({i, t});
		}
	}

	memset(dis, 0x3f, sizeof(dis));

	for (int i = 1; i <= n; i++) {

		for (int j = 0; j < Z[i].size(); j++) {

			int a = 0;

			for (int k = 0; k < B[Z[i][j]].size(); k++) {

				if (B[Z[i][j]][k].first == i) {
					a = B[Z[i][j]][k].second;
					break;
				}
			}

			//	cout << a << '\n';

			for (int k = 0; k < B[Z[i][j]].size(); k++) {

				if (B[Z[i][j]][k].first == i)
					continue;
				dis[i][B[Z[i][j]][k].first] = a + B[Z[i][j]][k].second;
				dis[B[Z[i][j]][k].first][i] = a + B[Z[i][j]][k].second;
				//	cout << i << ' ' << B[Z[i][j]][k].first << ' ' << a << ' ' << B[Z[i][j]][k].second << ' ' << j << '\n';
			}
		}
	}

	for (int i = 1; i <= n; i++) {

		dis[i][i] = 0;
	}

	for (int k = 1; k <= n; k++) {

		for (int l = 1; l <= n; l++) {

			for (int r = 1; r <= n; r++) {

				dis[l][r] = min(dis[l][r], dis[l][k] + dis[k][r]);
			}
		}
	}

	while (q--) {
		int s, e;
		long long ans = 1e18;
		cin >> s >> e;

		for (int i = 0; i < B[s].size(); i++) {

			for (int j = 0; j < B[e].size(); j++) {

				ans = min(ans, dis[B[s][i].first][B[e][j].first] + B[s][i].second + B[e][j].second);
			}
		}

		cout << ans + A[s] + A[e] << '\n';
	}

	return 0;
}
