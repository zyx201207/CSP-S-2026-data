#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+5;
ll n,a[maxn],sum[maxn],m,ans;
ll read()
{
	ll ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
		
	while(c>='0'&&c<='9')
	{
		ans=ans*10+c-48;
		c=getchar();
	}
	return ans*f;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		ll l=1,r=i,mid,tot;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(a[i]*mid-(sum[i]-sum[i-mid])<=m)
			{
				tot=mid;
				l=mid+1;
			}
			else
				r=mid-1;
		}
		ans=max(ans,tot);
	}
	printf("%lld\n",ans);
	return 0;
}//14:39
