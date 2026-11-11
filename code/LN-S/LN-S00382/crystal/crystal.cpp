#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	int d = a[2] - a[1],ans = 1;
	bool flag = 1;
	for (int i = 1;i < n;i++)
	{
		if (a[i + 1] - a[i] != d)
		{
			flag = 0;
		}
	}
	if (flag)
	{
		for (int i = 1;i <= n;i++)
		{
			if (m >= i * d)
			{
				m -= i * d;
				ans++;
			}
			else
			{
				break;
			}
		}
		cout << ans;
	}
	else
	{
		int d[500005];
		for (int t = a[1];t <= a[n];t++)
		{
			int w = 0,sum = 0;
			for (int i = 1;i <= n;i++)
			{
				d[i] = t - a[i];
			}
			sort(d + 1,d + n + 1);
			for (int i = 1;i <= n;i++)
			{
				if (d[i] >= 0)
				{
					if (w + d[i] > m) break;
					else
					{
						w += d[i];
						sum++;
					}
				}
			}
			ans = max(sum,ans);
		}
		cout << ans;
	}
	return 0;
}
