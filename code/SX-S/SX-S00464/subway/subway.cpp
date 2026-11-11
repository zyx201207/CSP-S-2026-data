#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, b[500005], s[500005], a[505][505];

struct node {
	long long s, t;
} e[500005][25];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i <= m; i++)
		cin >> b[i];
	for (long long i = 1; i <= n; i++)
		for (long long j = 1; j <= n; j++)
			if (i != j)
				a[i][j] = 2e18;
	for (long long i = 1; i <= n; i++) {
		long long k;
		cin >> k;
		for (long long j = 1; j <= k; j++) {
			long long x, y;
			cin >> x >> y;
			e[x][++s[x]] = node{i, y};
		}
	}
	for (long long i = 1; i <= m; i++) {
		for (long long j = 1; j < s[i]; j++) {
			for (long long k = j + 1; k <= s[i]; k++) {
				long long x = e[i][j].s, y = e[i][k].s;
				a[x][y] = a[y][x] = min(a[x][y], e[i][j].t + e[i][k].t);
			}
		}
	}
	for (long long i = 1; i <= n; i++)
		for (long long j = 1; j <= n; j++)
			for (long long k = 1; k <= n; k++)
				a[i][k] = min(a[i][k], a[i][j] + a[j][k]);
	while (q--) {
		long long x, y, ans = LLONG_MAX;
		cin >> x >> y;
		for (long long i = 1; i <= s[x]; i++)
			for (long long j = 1; j <= s[y]; j++) {
				ans = min(ans, b[x] + b[y] + a[e[x][i].s][e[y][j].s] + e[x][i].t + e[y][j].t);
			}
		cout << ans << '\n';
	}
	return 0;
}