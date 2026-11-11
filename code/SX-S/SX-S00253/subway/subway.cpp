#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, f[505][505], w[500005], a, t, k, x, y, minn;
vector<pair<long long, long long> > vt[500005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	memset(f, 0x3f, sizeof(f));
	for (long long i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
	}
	for (long long i = 1; i <= n; i++) {
		scanf("%lld", &k);
		f[i][i] = 0;
		for (long long j = 1; j <= k; j++) {
			scanf("%lld%lld", &a, &t);
			vt[a].push_back({i, t});
		}
	}
	for (long long i = 1; i <= m; i++) {
		for (long long j = 0; j < vt[i].size(); j++) {
			for (long long k = j + 1; k < vt[i].size(); k++) {
				f[vt[i][j].first][vt[i][k].first] = min(f[vt[i][j].first][vt[i][k].first], vt[i][j].second + vt[i][k].second);
				f[vt[i][k].first][vt[i][j].first] = min(f[vt[i][k].first][vt[i][j].first], vt[i][k].second + vt[i][j].second);
			}
		}
	}
	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= n; j++) {
			if (j == i) {
				continue;
			}
			for (long long k = 1; k <= n; k++) {
				f[j][k] = min(f[j][i] + f[i][k], f[j][k]);
			}
		}
	}
	for (long long i = 1; i <= q; i++) {
		minn = 1e18;
		cin >> x >> y;
		for (long long j = 0; j < vt[x].size(); j++) {
			if (minn == 0) {
				break;
			}
			for (long long k = 0; k < vt[y].size(); k++) {
//				cout << minn << ' ' << f[vt[x][j].first][vt[y][k].first] << ' ' << vt[x][j].second << ' ' << vt[y][k].second << endl;
				minn = min(minn, f[vt[x][j].first][vt[y][k].first] + vt[x][j].second + vt[y][k].second);
			}
		}
		cout << minn + w[x] + w[y] << endl;
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << f[i][j] << ' ';
//		}
//		cout << endl;
//	}
	return 0;
}