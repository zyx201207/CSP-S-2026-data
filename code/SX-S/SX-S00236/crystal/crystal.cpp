//2026 CSP-S RP++
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], dp[500005];
queue<int> q;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	int ans = 1, tot = 0, sum = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		tot += dp[i - 1] * (a[i] - a[i - 1]);
		sum++;
		q.push(i);
		while (tot > m) {
			tot -= a[i] - a[q.front()];
			sum--;
			q.pop();
			if (i == n && sum <= ans)
				break;
		}
		dp[i] = sum;
		ans = max(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}
