#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
ll C,D,n,m,q,w[500005],e[505][505];
vector<pll> v[500005];
void addedge(ll tu,ll tv,ll tw)
{
	e[tu][tv] = e[tv][tu] = min(e[tu][tv],tw);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&D,&q);
	for(ll i = 1;i <= m;i++)
		scanf("%lld",&w[i]);
	for(ll i = 1;i <= n;i++)
	{
		ll k;
		scanf("%lld",&k);
		for(ll j = 1;j <= k;j++)
		{
			ll a,t;
			scanf("%lld%lld",&a,&t);
			v[a].push_back({t,i});
		}
	}
	memset(e,0x3f,sizeof e);
	for(ll i = 1;i <= n;i++)
		e[i][i] = 0;
	for(ll i = 1;i <= m;i++)
		for(ll j = 0;j < v[i].size();j++)
			for(ll k = j + 1;k < v[i].size();k++)
				addedge(v[i][j].se,v[i][k].se,v[i][j].fi + v[i][k].fi);
	for(ll k = 1;k <= n;k++)
	{
		for(ll i = 1;i < k;i++)
			for(ll j = 1;j < k;j++)
				e[i][k] = e[k][i] = min(e[i][k],e[i][j] + e[j][k]);
		for(ll i = 1;i < k;i++)
			for(ll j = i + 1;j < k;j++)
				e[i][j] = e[j][i] = min(e[i][j],e[i][k] + e[k][j]);
	}
	for(ll i = 1;i <= q;i++)
	{
		ll x,y,ans = 0x3f3f3f3f3f3f3f3fLL;
		scanf("%lld%lld",&x,&y);
		for(auto i : v[x])
			for(auto j : v[y])
				ans = min(ans,e[i.se][j.se] + i.fi + j.fi);
		printf("%lld\n",ans + w[x] + w[y]);
	}
	return 0;
}