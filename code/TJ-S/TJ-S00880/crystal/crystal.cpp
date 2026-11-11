#include<bits/stdc++.h>
using namespace std;
long long n, m, ans, a[500010], d[500010], s[500010];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(long long i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(long long i = 1; i <= n; ++i)
	{
		d[i] = a[n] - a[i];
	}
	for(long long i = n; i > 0; --i)
	{
		s[i] = d[i] + s[i + 1];
	}
	for(long long i = n; i > 0; --i)
	{
		long long l = 0, r = i, mid;
		while(l + 1 < r)
		{
			mid = (l + r) >> 1;
			if(s[mid] - d[i] * (i - mid + 1) - s[i + 1] > m)
			{
				l = mid;
			}
			else
			{
				r = mid;
			}
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans;
	return 0;
}
