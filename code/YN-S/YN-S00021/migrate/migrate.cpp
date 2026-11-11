#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5010;
typedef long long ll;
const ll INF = 2e7 + 10;
ll dp[MAXN], a[MAXN], tot[MAXN];
int q, n, c, d;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> q;
	if (c > 10) {
		cout << "CSP2026RP++";
		return 0;
	} else {
		while (q--) {
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				dp[i] = INF;
				tot[i] = 0;
			}

			dp[1] = 0;
			for (int i = 1; i <= n; i++)
				cin >> a[i];
			for (int i = 1; i < n; i++) {
				ll range = a[i] + d;
				for (int j = i + 1; j <= n && a[j] <= range; j++) {
					if (dp[j] > dp[i] + 1) {
						dp[j] = dp[i] + 1;
						tot[j] = 1;
					} else if (dp[j] == dp[i] + 1)
						tot[j]++;

				}
			}

			ll cnt = 0;
			for (int i = 2; i <= n; i++) {
				if (tot[i] == 2)
					cnt++;
			}
			cout << cnt << "\n";
		}
	}
	return 0;
}