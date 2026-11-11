#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, maxn = 0, cnt1 = 0, cnt2 = 0;
int a[500005], dp[500005], t[500005];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		t[a[i]]++;
	}

	sort(a + 1, a + 1 + n);
	int x = (1 + n) / 2;

	for (int i = 1; i <= n; i++) {

		maxn = max(maxn, t[i]);

	}

	for (int i = 1; i < x; i++) {

		cnt1 += a[i + 1] - a[i];
	}

	for (int i = x; i < n; i++) {

		cnt2 += a[i + 1] - a[i];
	}

	dp[0] = maxn;
	int b;



	if (cnt1 <= cnt2) {
		for (int i = 1; i <= m; i++) {

			for (int j = 1; j <= x; j++) {

				if (a[x] > a[j]) {
					b = a[x] - a[j];
					dp[i] = max(dp[i], dp[i - b] + 1);

				}
			}
		}
	} else {
		for (int i = 1; i <= m; i++) {

			for (int j = x; j <= n; j++) {

				if ( j != n) {
					b = a[n] - a[j];
					dp[i] = max(dp[i], dp[i - b] + 1);
				}
			}
		}
	}

	cout << dp[m];
	return 0;
}