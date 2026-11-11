#include <bits/stdc++.h>
using namespace std;
unsigned long long m;
long long n, a[500005], maxx, minn = 1000000000005;
long long ans;
bool cmp(long long x, long long y)
{
	return x > y;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxx = max(a[i], maxx);
		minn = min(a[i], minn);
	}
	sort(a + 1, a + n + 1, cmp);
	for (long long i = minn; i <= maxx; i++)
	{
		long long j = 1, first = 1, sy = m, sum = 0;
		while (a[j] > i)
		{
			j++;
			first++;
		}
		for (long long j = first; j <= n; j++)
		{
			if (a[j] == i) sum++;
			if (a[j] < i)
			{
				sy -= (i - a[j]);
				sum++;
			}
			if (sy == 0) break;
			if (sy < 0)
			{
				sum--;
				break;
			}
		}
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}
