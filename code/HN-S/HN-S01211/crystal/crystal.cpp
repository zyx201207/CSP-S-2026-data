#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long sum[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++)
	{
		if (a[i]==a[i-1])
		{
			sum[i]=sum[i-1];
			continue;
		}
		sum[i]=(i-1)*a[i]-(i-1)*a[i-1]+sum[i-1];
	}
//	for (int i=1;i<=n;i++)
//	{
//		cout<<sum[i]<<' ';
//	}
	for (int i=n;i>0;i--)
	{
		if (sum[i]<=m)
		{
			cout<<i;
			return 0;
		}
	}
	cout<<1;
}
