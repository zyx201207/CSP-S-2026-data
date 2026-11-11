#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, ans;
int w[500005];

vector<vector<pair<int, int>>> vt(500);
vector<vector<int>> mp(500005);
int cnt;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> vt[i][j].first >> vt[i][j].second;
			if (c >= 7 && c <= 11 && j > 1) {
				mp[vt[i][j - 1].first].push_back(vt[i][j].first);

			}
		}
	}

	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;

		ans += w[x] + w[y] ;




	}
	cout << ans;

	return 0;
}