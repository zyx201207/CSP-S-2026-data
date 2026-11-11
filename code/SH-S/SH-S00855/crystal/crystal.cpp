#include <bits/stdc++.h>
using namespace std;
#define intl long long
const intl log_n = 19;
intl n, m, a[500010], ans[500010], dp[500010][25], maxlgi[500010];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(intl i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	intl dis = 1;
	for(intl j = 1; j <= log_n; ++j)
	{
		for(intl i = 1 << j; i <= n; ++i)
		{
			dp[i][j] = dp[i][j - 1] + dp[i - (1 << (j - 1))][j - 1] + (1 << (j - 1)) * (a[i] - a[i - (1 << (j - 1))]);
			if(dp[i][j] <= m) maxlgi[i] = j;
//			cout << dp[i][j] << ' ';
		}
//		cout << '\n';
		dis *= 2;
	}
//	for(int i = 1; i <= n; ++i) cout << maxlgi[i] << '\n';
	intl tmp = 0;
	for(intl i = 1; i <= n; ++i)
	{
		tmp = m;
		for(intl j = maxlgi[i]; j >= 0; --j)
		{
			if(i - ans[i] < 1 << j) continue;
			if(tmp >= dp[i - ans[i]][j] + (1 << j) * (a[i] - a[i - ans[i]]))
			{
				tmp -= dp[i - ans[i]][j] + (1 << j) * (a[i] - a[i - ans[i]]);
				ans[i] += 1 << j;
			}
		}
//		cout << ans[i] << '\n';
	}
	sort(ans + 1, ans + n + 1);
	cout << ans[n] << '\n';
	return 0;
}
