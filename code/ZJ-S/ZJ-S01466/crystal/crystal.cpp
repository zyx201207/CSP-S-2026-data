#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans,s[500005],b[500005],t,c[500005],tot;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	a[n+1]=a[n]+1;
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i+1])
		{
			b[++t]=a[i];
			c[t]=i;			
		}
	for(int i=1;i<=t;i++)
	{
		ll l=1,r=c[i],maxn;
		while(l<=r)
		{
			ll mid=(l+r)/2;
			if(b[i]*(c[i]-mid+1)-(s[c[i]]-s[mid-1])<=m)
			{
				maxn=c[i]-mid+1;
				r=mid-1;
			}
			else
				l=mid+1;
		}
		ans=max(ans,maxn);
	}
	printf("%lld",ans);
	return 0;
}
