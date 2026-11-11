#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		sort(a+1,a+n+1);
		a[1]++;
	}
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		sum=max(a[i],sum);
	}
	for(int i=1;i<=sum;i++)
	{
		long long h=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]==i)
			{
				h++;
			}
			ans=max(ans,h);
		}
	}
	cout<<ans;
	return 0;
}
