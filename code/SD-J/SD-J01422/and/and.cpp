#include <bits/stdc++.h>
using namespace std;
const long long N = 2*1e5+1000;
long long n,m,maxx = INT_MIN,ans = INT_MIN;
long long a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
		maxx = max(maxx,a[i]);
	}
	if(m==1)
	{
		cout << maxx << '\n';
		return 0;
	}
	if(m==2)
	{
		for(int i = 1;i<=n-1;i++)
		{
			for(int j = i+1;j<=n;j++)
			{
				ans = max(ans,a[i]&a[j]);
			}
		} 
		cout << ans << '\n';
		return 0;
	}
	if(m==n)
	{
		ans = a[1];
		for(int i = 2;i<=n;i++)
		{
			ans = ans&a[i];
		} 
		cout << ans << '\n';
		return 0;
	}
	if(m==n-1)
	{
		for(int i = 1;i<=n;i++)
		{
			long long y = a[1];
			if(i==1)
			{
				y = a[2];
			}
			for(int j = 2;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				y = y&a[i];
			}
			ans = max(ans,y);
		}
		cout << ans << '\n';
		return 0;
	}
	return 0;
}
