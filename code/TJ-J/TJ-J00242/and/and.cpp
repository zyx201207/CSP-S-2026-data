#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200001],maxx,cnt,f[200001],k;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(m == 1)
		{
			maxx = max(maxx,a[i]);
		}
	}
	if(m == 1)
	{
		for(int i = 1;i <= n;i++)
	    {
			maxx = max(maxx,a[i]);
		}
		cout << maxx;
		return 0;
	}
	if(m == 2)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				maxx = max(maxx,a[i]&a[j]);
			}
		}
		cout << maxx;
		return 0;
	}
	if(m == n)
	{
		int ans = a[1];
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				ans = ans & a[i+1];
			}
		}
		cout << ans;
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i + 1;j <= n;j++)
		{
			cnt = max(cnt,a[i]&a[j]);
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i + 1;j <= n;j++)
		{
			if(cnt == a[i]&a[j])
			{
				f[i] = 1;
				f[j] = 1;
			}
			if(f[i] != 1)
			{
				maxx = max(maxx,cnt&a[i]);
			}
		}
	}
	cout << maxx;
	return 0;
 } 
