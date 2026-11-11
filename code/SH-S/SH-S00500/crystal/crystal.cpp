#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,v,ans,s[500005],a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(ll i=1;i<=n;i++)
	{
		while((i-v)*a[i]-(s[i]-s[v])>m) v++;
		ans=max(ans,i-v);
	}
	printf("%lld\n",ans);
	return 0;
}
