#include <bits/stdc++.h>
using namespace std;

struct xxx {
	long long f, l, v;
};
long long c, t;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int tt = 1; tt <= t; tt++) {
		queue<xxx>q;
		cout << 1;
		long long ans = 0, n, d, x[5005], cnt[5005][5005], mn[5005][5005];
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			q.push({i, 0, i});
			mn[i][i] = -1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j)
					mn[i][j] = 100000000;
			}
		}
		while (q.size()) {
			xxx k = q.front();
			q.pop();
			if (k.v == n)
				continue;
			for (int i = 1; x[k.v + i] - x[k.v] <= d; i++ ) {
				if (mn[k.f][k.v + i] > k.l + 1) {
					q.push({k.f, k.l + 1, k.v + i});
					mn[k.f][k.v + i] = k.l + 1;
					cnt[k.f][k.v + i] = 1;
					cout << k.f << " " << k.v + i;
				} else if (mn[k.f][k.v + i] == k.l + 1) {
					cnt[k.f][k.v + i]++;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (cnt[i][j] == 2)
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
