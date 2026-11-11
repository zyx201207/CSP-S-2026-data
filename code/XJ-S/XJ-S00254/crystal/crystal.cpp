#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500005], m;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = -1;
	for (int i = 1; i <= n; i++)
	{
		for (int t = 1; t < i; t++)
		{
			long long s = 0;
			for (int j = t; j < i; j++)
			{
				s += a[i] - a[j];
				
			}
			if (s > m)
			{
				continue;
			}
			else ans = max(ans, i - t + 1);
		}
	}
	cout << ans;
	return 0;
}
