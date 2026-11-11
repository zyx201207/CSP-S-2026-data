#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e9;
ll c,t,n,k,ans;
ll f[1000010];
vector<ll> e[1000010]; 
bool vis[1000010];
ll d[1000010];
ll dis[1000010];
ll ff(ll u)
{
	if(f[u]!=u)
		f[u]=ff(f[u]);
	return f[u];
}
bool isok()
{
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
		if(vis[i])
			for(int j=0;j<e[i].size();j++)
				if(vis[e[i][j]])
				{
					ll fi=ff(i),fj=ff(e[i][j]);
					f[fi]=fj;	
				}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(vis[i])
			if(f[i]==i)
				cnt++;
	return cnt<=2;
}
void bl(ll u,ll step)
{
	if(dis[u]!=inf)
		return;
//	cout<<u<<' '<<step<<'\n';
	dis[u]=step;
	for(int i=0;i<e[u].size();i++)
		bl(e[u][i],step+1);
}
void dfs(int i,int cnt)
{
	if(cnt>k)
		return;
	if(i>n)
	{
		if(cnt!=k)
			return;
		if(!isok())
			return;
//		for(int i=1;i<=n;i++)
//			cout<<vis[i];
//		cout<<'\n';
		for(int i=1;i<=n;i++)
			d[i]=inf;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
				continue;
			for(int j=1;j<=n;j++)
				dis[j]=inf;
			bl(i,0);
			for(int j=1;j<=n;j++)
				if(vis[j])
					dis[j]=0;
//			for(int j=1;j<=n;j++)
//				cout<<dis[j]<<" \n"[j==n];
			for(int j=1;j<=n;j++)
				d[j]=min(d[j],dis[j]);
		}
		ll mx=0;
		for(int i=1;i<=n;i++)
			mx=max(mx,d[i]);
//		cout<<mx<<'\n';
		ans=min(ans,mx);
		return;
	}
	vis[i]=1;
	dfs(i+1,cnt+1);
	vis[i]=0;
	dfs(i+1,cnt);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=inf;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			ll u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)
			e[i].clear();
	}
	return 0;
}
