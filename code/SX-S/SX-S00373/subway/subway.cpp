#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5+3;
int c, n, m, d, q, w[N], k, sta, t[503][N];
LL vv[520][520];
vector<int> v[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(vv, 0x3f, sizeof vv);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];

	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> sta;
			cin >> t[i][sta];
			v[sta].push_back(i);
		}
	}

	for (int i = 1; i <= m; i++)
		for (int j = 0; j < v[i].size(); j++)
			for (int k = 0; k < v[i].size(); k++)
				if (j != k) {
					int x = v[i][j], y = v[i][k];
					LL value = t[x][i] + t[y][i];
					vv[x][y] = vv[y][x] = min(vv[x][y], value);
				}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i == j)
					vv[i][j] = 0;
				else
					vv[i][j] = min(vv[i][j], vv[i][k] + vv[k][j]);

	for (int i = 1; i <= q; i++) {
		LL s, d, ans = 8e18+3;
		cin >> s >> d;
		for (int j = 0; j < v[s].size(); j++)
			for (int k = 0; k < v[d].size(); k++)
				ans = min(vv[v[s][j]][v[d][k]] + t[v[s][j]][s] + t[v[d][k]][d], ans);
		cout << w[s] + w[d] + ans << endl;
	}
	return 0;
}