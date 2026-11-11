#include <bits/stdc++.h>
using namespace std;

struct node {
	vector<long long> to, from;
};



long long c, n, m, d, q, k, a[500001] = {0}, t[500001] = {0}, x, y, b[500001] = {0};
vector<long long> w;
vector<node> station;
long long dp[501][501];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	w.resize(m + 1, 0);
	station.resize(m + 1);
	for (long long i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (long long i = 1; i <= n; i++) {
		cin >> k;
		for (long long j = 1; j <= k; j++) {
			cin >> a[i] >> t[i];
		}
		for (int j = 1; j <= k; j++) {
			for (int z = j - 1, z <= k; z++) {
				station[j].from.push_back(a[i]);
				station[j].to.push_back(a[i]);
			}
		}
	}
	for (long long i = 1; i <= q; i++) {
		long long x, y;
		cin >> x >> y;
		for (int i = 1; i < station[x].to.size(); i++) {
			if (station[x].to[i] == y) {
				cout << w[x] + station[x].to[y] + w[x] << endl;
			}
		}
	}
	return 0;
}