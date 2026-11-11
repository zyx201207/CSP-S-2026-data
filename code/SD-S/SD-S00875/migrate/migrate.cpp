#include <bits/stdc++.h>

using namespace std;

long long c, t, a[2000010], dd, d, n, cnttt, cntt; 
map<long long, long long> cnt;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t --) {
		scanf("%lld %lld", &n, &d);
		for (int i = 1; i <= n; i ++) {
			scanf("%lld", &a[i]);
			if (i != 1) cnt[a[i] - a[i - 1]] ++;
		}
		if (cnt[a[2] - a[1]] == n - 1) {
			dd = a[2] - a[1];
			if (2 * dd <= d) printf("%lld\n", n - 2);
			else printf("0\n");
		} else {
			cnttt = 0;
			for (int i = 1; i <= n; i ++) {
				for (int j = i + 1; j <= n; j ++) {
					cntt = 0;
					for (int k = i; k + 2 <= j; k ++) {
						if (a[k + 2] - a[k] <= d) cntt ++;
						if (cntt > 1) {
							break;
						}	
					}
					if (cntt == 1) cnttt ++;
				}
			}
			printf("%lld\n", &cnttt);
		}
		/*memset(0, dp, sizeof(dp));
		memset(0, a, sizeof(a));
		for (int i = 1; i <= n; i ++) {
			for (int j = 4; j <= n; j ++) {
				if (dp[i][j])
			}
			0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
		}*/
	}
	return 0;
}
