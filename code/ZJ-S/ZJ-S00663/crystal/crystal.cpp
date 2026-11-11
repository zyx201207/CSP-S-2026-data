#include<bits/stdc++.h>
using namespace std;
long long rd()
{
	long long f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=(k<<1)+(k<<3)+(c^48);
		c=getchar();
	}
	return f*k;
}
long long n,ok,a[500005],m,sum[500005];
long long ck(int x)
{
	long long num=m+1;
	for(int i=x;i<=n;i++)
	{
		num=min(num,a[i]*x-sum[i]+sum[i-x]);
	}
	return num<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=n;i++)
	{
		a[i]=rd();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	long long l=0,r=n,mid;
	ok=0;
	while(l<=r)
	
	{
		mid=(l+r)>>1;
		if(ck(mid))
		{
			l=mid+1;
			ok=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ok;
}