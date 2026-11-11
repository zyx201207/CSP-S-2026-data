#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n=0,m,nn;
ll aa[N],b[N],s[N],s2[N],a[N];
map<ll,ll> p;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&nn,&m);
	for(int i=1;i<=nn;i++) scanf("%lld",&aa[i]),p[aa[i]]++;
	for(auto y:p) a[++n]=y.first,b[n]=y.second;
	ll res=0;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i]*b[i],s2[i]=s2[i-1]+b[i];
	for(int i=1;i<=n;i++)
	{
		ll l=1,r=i,ans=1;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if((s2[i]-s2[mid-1])*a[i]-(s[i]-s[mid-1])>=m) ans=mid,l=mid+1;
			else r=mid-1;
		}
		if(ans==i)
		{
			res=max(res,b[i]);
			continue;
		}
		ll k=m-((s2[i]-s2[ans])*a[i]-(s[i]-s[ans]));
		ll sum=s2[i]-s2[ans];
		sum+=min(b[ans],k/(a[i]-a[ans]));
		res=max(res,sum);
	}
	printf("%lld",res);
	return 0;
}