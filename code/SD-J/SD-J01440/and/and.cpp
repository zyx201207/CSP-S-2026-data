#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[200005];
int ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n+1];
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i] & a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=(ans & a[i]);
		}
		return 0;
	}
	if(m==n-1)
	{
		ans=a[2];
		for(int i=3;i<=n;i++)
		{
			ans=(ans & a[i]);
		}
		return 0;
	}
	if(a[n]<4)
	{
		cout<<a[n];
		return 0;
	}
	ans=a[n];
	for(int i=n-1;n-i+1<=m;i++)
	{
		ans=(ans&a[i]);
	}
	cout<<ans;
	return 0;
}
