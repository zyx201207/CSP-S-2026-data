//SN-S00439 西安市铁一中 蒋雨曦 
#include<bits/stdc++.h>
#define ll long long 
#define maxn 500505 
using namespace std;
const ll inf=1e18;
ll c,n,m,D,Q,dis[505][505],w[maxn],ans[maxn],d[maxn],vis[505];
vector<pair<ll,ll>> edge[maxn];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
void ins(ll now,ll x)
{
	for(auto i:edge[now])
	{
		ll to=i.first,v=i.second;
		if(to<=n&&dis[x][to]!=inf) continue;
		if(d[to]>d[now]+v) d[to]=d[now]+v,q.push({d[to],to});
	}
}
void solve(ll x)
{
	for(int i=1;i<=n+m;i++) d[i]=inf;
	q.push({0,x}); d[x]=0; ll tim=0;
	for(int i=1;i<=n;i++) if(i!=x&&x!=1&&dis[x][i]==inf)
	{
		for(int j=1;j<x;j++) d[i]=min(d[i],abs(dis[j][x]-dis[j][i]));
	}
	while(!q.empty())
	{
		pair<ll,ll> now=q.top(); q.pop(); tim++;
		if(d[now.second]^now.first) continue;
		ins(now.second,x);
	}
	for(int i=1;i<=n;i++) if(dis[x][i]==inf) dis[x][i]=dis[i][x]=d[i];
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("subway.in","r",stdin); freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>D>>Q; for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		ll k; cin>>k;
		for(int j=1;j<=k;j++)
		{
			ll t,tt; cin>>t>>tt;
			edge[i].push_back({n+t,tt});
			edge[n+t].push_back({i,tt});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i^j) dis[i][j]=inf;
	for(int i=1;i<=n;i++) solve(i);
	while(Q--)
	{
		ll x,y,ans=inf; cin>>x>>y;
		for(auto i:edge[x+n]) for(auto j:edge[y+n])
		{
			ll t=i.first,tt=j.first;
			ans=min(ans,i.second+j.second+dis[t][tt]);
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
