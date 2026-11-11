#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = -10, a[20005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(m == 1)
	{
		for(int i = 1; i <= n; i++)
		{
			ans = max(ans, a[i]);
		}
	}
	if(m == n)
	{
		ans = a[1];
		for(int i = 2; i <= n; i++)
		{
			ans = ans & a[i];
		}
	}
	if(m == 2)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				ans = max(ans, a[i] & a[j]);
			}
		}
	}
	else if(m == n - 1)
	{
		for(int i = 1; i <= n; i++)
		{
			long long ans1 = a[1];
			for(int j = 2; j <= n; j++)
			{
				if(j == i) continue;
				ans1 = ans1 & a[i];
			}
			ans = max(ans1, ans);
		}
	}
	cout << ans;
	return 0;
}
