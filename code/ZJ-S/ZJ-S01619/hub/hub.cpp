#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
const ll maxn=30;
ll c,t,cnt;
ll n,k;
vector<ll>v[maxn];
ll vis[maxn],b[maxn];
void dfs(ll u,ll fa)
{
	b[u]=0;
	for(ll i=0;i<v[u].size();i++)
	{
		if(v[u][i]==fa)
		{
			continue;
		}
		if(b[v[u][i]]==1)
			dfs(v[u][i],u);
	}
}
ll dis[maxn];
void dfs2(ll u,ll fa,ll dep)
{
	dis[u]=min(dis[u],dep);
	for(ll i=0;i<v[u].size();i++)
	{
		if(v[u][i]==fa)
		{
			continue;
		}
		dfs2(v[u][i],u,dep+1);
	}
}
ll ans=1e18;
void check()
{
	for(ll i=1;i<=n;i++)
	{
		b[i]=vis[i];
		dis[i]=1e18;
	}
	cnt=0;
	for(ll i=1;i<=n;i++)
	{
		if(b[i]==1)
		{
			dfs(i,0);
			cnt++;
		}
	}
	if(cnt>2)
	{
		return void();
	}
	for(ll i=1;i<=n;i++)
	{
		if(vis[i])
		{
			dfs2(i,0,0);
		}
	}
	ll sum=0;
	for(ll i=1;i<=n;i++)
	{
		sum=max(dis[i],sum);
	}
	ans=min(ans,sum);
}
void ddfs(ll now,ll num)
{
	if(now==n+1||num==k)
	{
		check();
		return void();
	}
	if(n-now+1+num<k)
	{
		return void();
	}
	vis[now]=1;
	ddfs(now+1,num+1);
	
	vis[now]=0;
	ddfs(now+1,num);
}
int main()
{
	fre(hub);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		ans=1e18;
		for(ll i=1;i<=n;i++)
		{
			v[i].clear();
		}
		for(ll i=1;i<n;i++)
		{
			ll aa,bb;
			cin>>aa>>bb;
			v[aa].push_back(bb);
			v[bb].push_back(aa);
		}
		ddfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}