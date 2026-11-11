#include <bits/stdc++.h>
using namespace std;
long long n,m,l,r,mid,ans,a[500009],d[500009];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	if(m==0||n==1)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
	}
	bool v=1;
	for(int i=2;i<n;i++)
	{
		if(d[i]!=d[i+1])
		{
			v=0;
			break;
		}
	}
	if(v==1)
	{
		long long t=d[2],c=d[2];
		for(int i=1;i<=n;i++)
		{
			if(t>m)
			{
				cout<<i;
				break;
			}
			t=t+c*(i+1);
		}
		return 0;
	}
	for(int j=n;j>0;j--)
	{
		long long z=0,s=1;
		for(int i=j-1;i>=0;i--)
		{
			long long x=a[j]-a[i];
			z+=x;
			if(z>m)
			{
				ans=max(ans,s);
				break;
			}
			s++;
		}
	}
	cout<<ans;
	return 0;
}