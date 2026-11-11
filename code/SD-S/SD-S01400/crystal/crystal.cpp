#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0,c1[500005],c2[500005];
long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-1;
			ch=getchar();
			break;
		}
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(long long i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<n;i++)
	{
		c1[i]=a[i+1]-a[i];
	}
	for(long long i=1;i<n;i++)
	{
		c2[i]=c2[i-1]+i*c1[i];
	}
	long long l=0,r=n,ans=0;
	while(l<r)
	{
		long long mid=(l+r)>>1;
		long long t=mid-1;
		bool f=0;
		for(long long i=t;i<n;i++)
		{
			if(c2[i]-c2[i-t]-(a[i+1]-a[i-t+1])*(i-t)<=m)
			{
				f=1;
				break;
			}
		}
		if(f)
		{
			ans=max(ans,mid);
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	cout<<ans;
	return 0;
}
