#include <bits/stdc++.h>
using namespace std;
long long n, m, q, a[500050], p[550][550];
vector<vector<pair<int, long long>>>v(550), b(500050);
vector<vector<int> >t(500050);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> n >> n >> m >> q >> q;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int j = 1; j <= x; j++) {
			long long y, z;
			cin >> y >> z;
			b[y].push_back({i, z});
			t[y].push_back(i);
			if (b.size() != 1) {
				for (int i = 0; i < b[y].size() - 1; i++) {
					v[b[y][i].first].push_back({b[y][b[y].size() - 1].first, z + b[y][i].second});
					v[b[y][b[y].size() - 1].first].push_back({b[y][i].first, z + b[y][i].second});
				}
			}
		}
	}
	memset(p, 0x3f, sizeof p);
	while (q--) {
		int x, y;
		cin >> x >> y;
		vector<int> xx = t[x], yy = t[y];
		long long min1 = 9000000000;
		for (int i = 0; i < xx.size(); i++)
			for (int j = 0; j < yy.size(); j++)
				min1 = min(min1, p[i][j]);
		cout << a[x] + a[y] << "\n";
	}
	return 0;
}