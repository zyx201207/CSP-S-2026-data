#include<bits/stdc++.h>
using namespace std;
#define int long long 
int a[511111],n,m,maxx=-1e18-1,s[523233],fa,fb;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i) fa=1;
		if(i>3)
		{
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) fb=1;
		}
	}
	if(fa==0);
	{
		for(int i=n;i>=1;i--)
		{
			if(m>=i*i-i*(i+1)/2)
			{
				cout<<i;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	if(fb==0)
	{
		int gx=a[2]-a[1];
		for(int i=n;i>=2;i--)
		{
			if((a[1]+a[i])*i/2+m>=i*i)
			{
				cout<<i;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		s[i]+=s[i-1];
		s[i]+=a[i];
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int cnt=0;
			if(a[j]*(j-i+1)<=s[j]-s[i-1]+m) 
			{
				cnt=j-i+1;
			}
			maxx=max(cnt,maxx);
		}
	}
	cout<<maxx;
	return 0;
}

