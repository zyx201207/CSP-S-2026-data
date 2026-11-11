#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 5e5 + 5;
LL n, m;
LL a[maxn], sum[maxn];
LL ans;
LL maks = 0;
LL t[505];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld", &a[i]);
		maks = max(maks, a[i]);
	}
	sort(a + 1, a + 1 + n);
	if (n <= 5000)
	{ // O(n^2)
		for (int i = 1; i <= n; ++i)
		{
			sum[i] = sum[i - 1] + a[i];
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i; j <= n; ++j)
			{
				LL len = j - i + 1;
				if (sum[j] - sum[i - 1] + m >= a[j] * len)
				{
					ans = (len > ans ? len : ans);
				} 
			}
		}
	}
	else if (maks <= 100)
	{ // O(max a_i) (?) Special Judge(???)
		for (int i = 1; i <= n; ++i)
		{
			t[a[i]]++;
		}
		for (int i = 1; i <= maks; ++i)
		{
			LL same = t[i], AFO = m;
			for (int j = i - 1;;)
			{
				if (AFO >= t[j])
				{
					AFO -= (i - j) * t[j];
					same += t[j];
				}
				else
				{
					same += AFO / (i - j);
				}
			}
			ans = max(ans, same);
		}
	}
	else
	{ // Special Judge(?) O(n)
		LL SUM = a[1];
		for (int i = 1, j = 1; j <= n;)
		{
			LL len = j - i + 1;
			if (SUM + m >= a[j] * len)
			{
				ans = (len > ans ? len : ans);
				SUM += a[++j];
			}
			else
			{
				SUM -= a[++i];
			}
		}
	}
	cout << ans;
}
// 1~9,13~18 15/20 75pts
// 距离AFO还有1小时59分钟 

// 1~18 18/20 90 pts(maybe..)
// 距离AFO还有17分钟 
