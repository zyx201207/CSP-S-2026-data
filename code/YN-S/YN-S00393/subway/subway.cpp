#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e4 + 5;
int mp[maxn][maxn], w[maxn], a[maxn][maxn], t[maxn][maxn], k[maxn];
int c, n, m, d, q2;
queue < pair<int, int>> q;
set<int> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q2;

	for (int i = 1; i <= m; i++) {

		cin >> w[i];
	}

	int maxa  = 0;

	for (int i = 1; i <= n; i++) {

		cin >> k[i];

		for (int j = 1; j <= k[i]; j++) {

			cin >> a[i][j] >> t[i][j];
		}


		for (int j = 1; j <= k[i]; j++) {

		}

		for (int j = 1; j <= k[i]; j++) {

			for (int l = j + 1; l <= k[i]; l++) {

				mp[a[i][j]][a[i][l]] = mp[a[i][l]][a[i][j]] = t[i][j] + t[i][l];
			}
		}
	}

	for (int i = 1; i <= q2; i++) {

		int s, f;
		cin >> s >> f;

		if (mp[s][f] != 0) {
			cout << mp[s][f] + w[s] + w[f] << "\n";
		} else {
			int ans = INT_MAX;

			while (!q.empty()) {
				q.pop();
			}

			st.clear();
			q.push({s, 0});

			while (!q.empty()) {
				pair<int, int> x = q.front();
				q.pop();

				if (st.count(x.first)) {
					continue;
				}

				if (x.first == f) {
					ans = min(ans, x.second);
					continue;
				}

				for ( int j = 1; j <= m; j++) {

					if (mp[x.first][j] != 0) {
						q.push({j, x.second + mp[j][x.first]});

					}
				}

				st.insert(x.first);
			}

			cout << ans + w[s] + w[f] << "\n";
		}
	}

	return 0;
}