#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

inline long long read()
{
	char c=getchar();
	while(!isdigit(c)&&c!='-')
	{
		c=getchar();
	}
	bool flag=false;
	if(c=='-')
	{
		flag=true;
		c=getchar();
	}
	long long val=0;
	while(isdigit(c))
	{
		val=(val<<3)+(val<<1)+1ll*(c^48);
		c=getchar();
	}
	if(flag)
	{
		val=-val;
	}
	return val;
}

long long a[N];
long long n,m;
long long pri[N];

bool check(long long x)
{
	long long ans=LLONG_MAX;
	for(long long i=1;i<=n+1-x;i++)
	{
		long long p=x*a[i+x-1]-(pri[i+x-1]-pri[i-1]);
		ans=min(ans,p);
	}
	return ans<=m;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	
	sort(a+1,a+1+n);
	
	pri[0]=0;
	for(int i=1;i<=n;i++)
	{
		pri[i]=pri[i-1]+a[i];
	}
	
	long long l=0,r=n;
	while(l<r)
	{
		long long mid=(r-l+1)/2+l;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	printf("%lld",l);
	return 0;
}