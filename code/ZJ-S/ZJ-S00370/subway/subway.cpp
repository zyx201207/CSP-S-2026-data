#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q, w[500005], a[500005], t[500005];
int dis[6005][6005];
vector<int> idx[500005];
int cnt[505], te[500005][5];
bool v[500005];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dis, 0x3f, sizeof dis);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	if (1 <= c and c <= 6) {
		for (int i = 1; i <= m * d; i++) dis[i][i] = 0;
		for (int i = 1; i <= n; i++) {
			int k;
			cin >> k;
			for (int j = 1; j <= k; j++) {
				cin >> a[j] >> t[j];
			}
			cnt[a[1]] += 1;
			dis[cnt[a[1]] * m + a[1]][a[1]] = t[1];
			dis[a[1]][cnt[a[1]] * m + a[1]] = t[1];
			for (int j = 2; j <= k; j++) {
				cnt[a[j]] += 1;
				dis[cnt[a[j]] * m + a[j]][cnt[a[j - 1]] * m + a[j - 1]] = 0;
				dis[cnt[a[j - 1]] * m + a[j - 1]][cnt[a[j]] * m + a[j]] = 0;
				dis[cnt[a[j]] * m + a[j]][a[j]] = t[j];
				dis[a[j]][cnt[a[j]] * m + a[j]] = t[j];
			}
		}
		d++;
		for (int k = 1; k <= d * m; k++) {
			for (int i = 1; i <= d * m; i++) {
				for (int j = 1; j <= d * m; j++) {
					if (dis[i][j] > dis[i][k] + dis[k][j]) {
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
			}
		}
		while (q--) {
			int x, y;
			cin >> x >> y;
			cout << dis[x][y] + w[x] + w[y] << '\n';
		}
		return 0;
	}
	if (7 <= c and c <= 11) {
		for (int i = 1; i <= m; i++) dis[i][i] = 0;
		for (int i = 1, k; i <= n; i++) {
			cin >> k;
			for (int j = 1; j <= k; j++) cin >> a[j] >> t[j];
			if (k == 1) continue;
			dis[a[1]][a[2]] = t[1] + t[2];
			dis[a[2]][a[1]] = t[1] + t[2];
		}
		for (int k = 1; k <= m; k++) {
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= m; j++) {
					if (dis[i][j] > dis[i][k] + dis[k][j]) {
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
			}
		}
		while (q--) {
			int x, y;
			cin >> x >> y;
			cout << dis[x][y] + w[x] + w[y] << '\n';
		}
		return 0;
	}
	if (c == 21 or c == 22) {
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++) cin >> a[i] >> t[i], v[a[i]] = 1, te[a[i]][1] = t[i];
		int temp;
		cin >> temp;
		int minn = LLONG_MAX;
		while (temp > 0) {
			temp--;
			int aa, bb;
			cin >> aa >> bb;
			te[aa][0] = bb;
			if (v[aa]) {
				minn = min(te[aa][1] + bb, minn);
			}
		}
		while (q--) {
			int x, y;
			cin >> x >> y;
			if (v[x] == v[y]) {
				cout << te[x][v[x]] + te[y][v[y]] + w[x] + w[y] << '\n';
			}
			else cout << te[x][v[x]] + te[y][v[y]] + w[x] + w[y] + minn << '\n';
		}
		return 0;
	}
	if (12 <= c and c <= 19) {
		int T;
		for (int i = 1; i <= n; i++) dis[i][i] = 0;
		for (int i = 1; i <= n; i++) {
			int k;
			cin >> k;
			while (k > 0) {
				k--;
				int aa, bb;
				cin >> aa >> bb;
				idx[aa].push_back(i);
				T = bb;
			}
		}
		for (int i = 1; i <= m; i++) {
			if (idx[i].size() == 1) continue;
			for (int j = 1; j < idx[i].size(); j++) {
				dis[idx[i][j]][idx[i][j - 1]] = 1;
				dis[idx[i][j - 1]][idx[i][j]] = 1;
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (dis[i][j] > dis[i][k] + dis[k][j]) {
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
			}
		}
		while (q--) {
			int x, y;
			cin >> x >> y;
			int ans = LLONG_MAX;
			for (auto i : idx[x]) {
				for (auto j : idx[y]) {
					ans = min(ans, dis[i][j]);
				}
			}
			cout << (ans + 1) * T * 2 + w[x] + w[y] << '\n';
		}
	}
	return 0;
}
