#include <bits/stdc++.h>
using namespace std;
long long w[500005];

struct f {
	long long x, j, t;
} a[500005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	long long c, n, m, d, q, ans = 0;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		long long k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i].j >> a[i].t;
			a[i].x = i;
			ans += a[i].t;
		}
	}
	while (q--) {
		long long s, e;
		cin >> s >> e;
		cout << w[s] + w[e] + ans << endl;
	}
	return 0;
}
