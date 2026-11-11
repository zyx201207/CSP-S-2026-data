#include<bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int ans = -1;
	if (m == 1)
	{
		for (int i = 0; i < n; i++)
		{
			long long t;
			cin >> t;
			if (t > ans)
			{
				ans = t;
			}
		}
	}
	if (m == 2)
	{
		long long a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if ((a[i] & a[j]) > ans)
				{
					ans = a[i] & a[j];
				}
			}
		}
	}
	cout << ans;
	return 0;
}
