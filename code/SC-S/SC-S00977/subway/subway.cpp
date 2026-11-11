#include<bits/stdc++.h>
using namespace std;
long long Read() {
	int x = 0, f = 1;
	char c;
	c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x*f;
}
const int N = 5e5+5;
int dp[505][505];
int c, n, m, d, q, w[N];
int k, a[N], t[N], x, y;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp, 0x3f, sizeof dp);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		w[i] = Read();
	}
	for (int i = 1; i <= m; i++) {
		dp[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		k = Read();
		for (int j = 1; j <= k; j++) {
			a[j] = Read();
			t[j] = Read();
			for (int l = 1; l < j; l++) {
				dp[a[j]][a[l]] = min(dp[a[j]][a[l]], t[j] + t[l]);
				dp[a[l]][a[j]] = min(dp[a[l]][a[j]], t[l] + t[j]);
			}
		}
	}
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				if (i == j) {
					continue;
				}
				if (dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		x = Read();
		y = Read();
		cout << w[x] + w[y] + dp[x][y] << '\n';
	}
	return 0;
}