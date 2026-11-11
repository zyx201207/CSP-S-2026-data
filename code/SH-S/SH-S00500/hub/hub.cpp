#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,k,pos,cnt,du[4005],f[4005],fa[4005];
bool exi[4005],vis[4005];
vector<ll> e[4005];
vector<ll> a,b;
void dfs(ll x,ll faa)
{
	fa[x]=faa;
	for(ll nd:e[x])
		if(nd!=faa) dfs(nd,x);
}
void dfs2(ll x)
{
	a.push_back(x);
	for(ll nd:e[x])
		if(nd!=pos&&nd!=fa[x]) dfs2(nd);
}
void topu(ll x)
{
	for(ll i=1;i<=n;i++){vis[i]=false;exi[i]=false;du[i]=0;f[i]=0;}
	for(ll x:a) exi[x]=true;
	for(ll x:a)
		for(ll y:e[x])
			if(exi[y]) du[x]++;
	queue<ll> q;
	for(ll i=1;i<=n;i++)
		if(exi[i]&&du[i]<=1) q.push(i);
	while(!q.empty())
	{
		ll nd=q.front();
		q.pop();
		if(vis[nd]) continue;
		vis[nd]=true;
		if(f[nd]>=x) cnt++;
		for(ll x:e[nd])
			if(!vis[x]&&exi[x])
			{
				du[x]--;f[x]=max(f[x],f[nd]+1);
				if(du[x]<=1) q.push(x);
			}
	}
}
bool chk(ll x,ll y)
{
	a.clear();
	pos=x;cnt=0;
	dfs2(1);
	topu(y);
	a.clear();
	dfs2(x);
	topu(y);
	if(cnt<=k) return true;
	return false;
}
void szzakioi()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		e[i].clear();
		fa[i]=0;
	}
	for(int i=1;i<n;i++)
	{
		ll uu=0,vv=0;
		scanf("%lld%lld",&uu,&vv);
		e[uu].push_back(vv);
		e[vv].push_back(uu);
	}
	dfs(1,0);
	ll ans=n;
	for(int i=2;i<=n;i++)
	{
		ll l=0,r=n;
		while(l<r)
		{
			ll mid=((l+r)>>1);
			if(chk(i,mid)) r=mid;
			else l=mid+1;
		}
		ans=min(ans,l);
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--) szzakioi();
	return 0;
}
