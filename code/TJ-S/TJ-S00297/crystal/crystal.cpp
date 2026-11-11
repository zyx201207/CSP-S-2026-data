#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,ans;
long long m,a[500001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	long long minn = 1000000000001,maxn = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] < minn)
		{
			minn = a[i];
		}
		if (a[i] > maxn)
		{
			maxn = a[i];
		}
	}
	sort(a+1,a+n+1);
	long long m2 = m;
	int ans2 = 0;
	for (long long i = minn+1; i <= maxn; i++)
	{
		m2 = m;
		ans2 = 0;
		for (int j = n; j >= 1; j--)
		{
			if (a[j] > i)
			{
				continue;
			}
			else if (a[j] == i)
			{
				ans2++;
				if (ans2 > ans)
				{
					ans = ans2;
				}
			}
			else
			{
				if (i - a[j] <= m2)
				{
					ans2++;
					m2 = m2 - (i-a[j]);
					if (ans2 > ans)
					{
						ans = ans2;
					}
				}
				else
				{
					if (ans2 > ans)
					{
						ans = ans2;
					}
					break;
				}
			}
		}
	} 
	cout << ans;
	return 0;
}
