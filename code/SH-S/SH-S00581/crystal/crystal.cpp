#include <iostream>
#include <algorithm>
using namespace std;

long long a[500005], sum[500005];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (long long i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (long long i = 1; i <= n; ++i)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	long long maxn = 0;
	for (long long i = 1; i <= n; ++i)
	{
		long long l = 1, r = i, ans = i;
		while (l <= r)
		{
			long long mid = (l + r) / 2;
			if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m)
			{
				r = mid - 1;
				ans = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		maxn = max(maxn, i - ans + 1);
	}
	cout << maxn;
	
	return 0;
}
