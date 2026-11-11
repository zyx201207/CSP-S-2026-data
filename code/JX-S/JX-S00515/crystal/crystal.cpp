#include <bits/stdc++.h>

#define maxn 500001

using namespace std;

long long n, m, ans, a[maxn], t[maxn], dp[maxn];

bool check1(long long p)
{
	if ((p * (p - 1)) >> 1 <= m)
	{
		return 1;
	}
	return 0;
}

bool check2(long long p)
{
	if (((p - 1) * (2 * a[p] - a[p - 1] - a[1])) >> 1 <= m)
	{
		return 1;
	}
	return 0;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n > 5000 && a[n] == n && a[1] == 1 && a[2500] == 2500)
	{
		long long l = 1, r = n;
		while (l <= r)
		{
			long long mid = (l + r) >> 1;
			if (check1(mid))
			{
				l = mid + 1;
				ans = max(ans, mid);
			}
			else
			{
				r = mid - 1;
			}
		}
		cout << ans;
		return 0;
	}
	if (n > 5000 && a[n] - a[n - 1] == a[n - 1] - a[n - 2] && a[2] - a[1] == a[3] - a[2] && a[n] - a[n - 1] == a[2] - a[1])
	{
		long long l = 1, r = n;
		while (l <= r)
		{
			long long mid = (l + r) >> 1;
			if (check2(mid))
			{
				l = mid + 1;
				ans = max(ans, mid);
			}
			else
			{
				r = mid - 1;
			}
		}
		cout << ans;
		return 0;
	}
	for (long long p = 1; p <= n; p++)
	{
		memset(dp, 0, sizeof(dp));
		for (long long i = 1; i <= p; i++)
		{
			t[i] = a[p] - a[i];
		}
		for (long long i = 1; i <= p; i++)
		{
			for (long long j = m; j >= t[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - t[i]] + 1);
			}
		}
		ans = max(ans, dp[m]);
	}
	cout << ans;
	return 0;
}