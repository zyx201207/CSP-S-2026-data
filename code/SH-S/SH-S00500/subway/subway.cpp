#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
ll c,n,m,d,q,w[500005],l[505];
ll cnt[500005],f[505][505];
vector<ll> p[500005],t[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(ll i=1;i<=m;i++){p[i].push_back(0);t[i].push_back(0);}
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&l[i]);
		for(ll j=1;j<=l[i];j++)
		{
			ll tt=0,ww=0;
			scanf("%lld%lld",&tt,&ww);
			cnt[tt]++;
			p[tt].push_back(i);
			t[tt].push_back(ww);
		}
	}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			if(i!=j) f[i][j]=inf;
	for(ll i=1;i<=m;i++)
		for(ll j=1;j<=cnt[i];j++)
			for(ll k=1;k<=cnt[i];k++)
			{
				ll a=p[i][j],b=p[i][k];
				f[a][b]=min(f[a][b],t[i][j]+t[i][k]);
				f[b][a]=min(f[b][a],t[i][j]+t[i][k]);
			}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			for(ll k=1;k<=n;k++) f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
	for(ll i=1;i<=q;i++)
	{
		ll a=0,b=0,ans=inf;
		scanf("%lld%lld",&a,&b);
		for(ll j=1;j<=cnt[a];j++)
			for(ll k=1;k<=cnt[b];k++) ans=min(ans,f[p[a][j]][p[b][k]]+t[a][j]+t[b][k]);
		printf("%lld\n",ans+w[a]+w[b]);
	}
	return 0;
}
