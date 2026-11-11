#include <bits/stdc++.h>

using namespace std;
#define MAXN 2010000
#define LL long long

/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
LL n, d;
LL a[MAXN];
void work()
{
	scanf("%lld%lld", &n, &d);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	LL ans = 0;
	for (int x = 1; x <= n; x++)
	{
		vector<int> v(n + 10);
		vector<int> dp(n + 10);
		vector<int> cnt(n + 10);
		dp[x] = cnt[x] = 1;
		int l = x;
		int idx = 1;
		v[1] = 1;
		for (int i = x + 1; i <= n; i++)
		{
			while (a[i] - a[l] > d)
			{
				v[dp[l]] -= cnt[l];
				if (v[dp[l]] == 0)
					idx ++;
				l++;
			}
			dp[i] = idx + 1;
			cnt[i] = v[idx];
			v[dp[i]] += cnt[i];
			// cout << i << ' ' << dp[i] << ' ' << cnt[i] << ' ' << idx << endl;
			if (cnt[i] == 2)
				ans ++;
		}
	}
	cout << ans << endl;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
		work();
	return 0;
}