#include <bits/stdc++.h>
using namespace std;
long long n, m, z, q, w[500005], k[505], a[1005][1005], t[1005][1005], x[10005], y[10005];
long long dp[10005][10005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> n;
	cin >> n >> m >> z >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
			cin >> a[i][j] >> t[i][j];
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= 1005; i++) {
		for (int j = 1; j <= 1005; j++) {
			if (i != j)
				dp[i][j] = 1e9;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k[i]; j++)
			for (int d = 1; d <= k[i]; d++)
				if (j != d)
					dp[a[i][j]][a[i][d]] = min(t[i][j] + t[i][d], dp[a[i][j]][a[i][d]]);
	for (int d = 1; d <= m; d++)
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				if (i != j)
					dp[i][j] = min(dp[i][j], dp[i][d] + dp[d][j]);
	for (int i = 1; i <= q; i++)
		cout << dp[x[i]][y[i]] + w[x[i]] + w[y[i]] << endl;

	return 0;
}
