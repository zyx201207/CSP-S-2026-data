#include <bits/stdc++.h>
using namespace std;

int n, t, c, k, cnt, d[200005], dp[2005][2005];
long long u[2000005], v[200005];
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> u[i] >> v[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				d[i] = min(dp[i][j], j);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (d[j] - d[i] <= k)
					continue;
				else {
					if (d[j] - d[i] > k)
						cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}