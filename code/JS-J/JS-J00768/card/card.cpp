#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[500001],ans[300001];
ll sum[300001];
bool fA=1;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;++i)
	{
		scanf("%lld",a+i);
		if(a[i]<a[i-1]) fA=0;
	}
	if(fA)
	{
		for(ll i=2;i<=n;++i)
			if(a[i]!=a[i-1]) printf("%lld ",i-1);
		printf("%lld\n",n);
		return 0;
	}
	for(ll i=1;i<=n;++i)
	{
		memset(sum,0,sizeof(sum));
		for(ll j=i;j<=n;++j)
		{
			if(!sum[a[j]]) sum[a[j]]=j;
			else
			{
				for(ll k=sum[a[j]]+1;k<j;++k)
					sum[a[k]]=0;
				sum[a[j]]=j;
			}
		}
		for(ll j=1;j<=m;++j)
			ans[j]+=bool(sum[j]);
	}
	for(ll i=1;i<=m;++i)
		printf("%lld ",ans[i]);
	return 0;
}
