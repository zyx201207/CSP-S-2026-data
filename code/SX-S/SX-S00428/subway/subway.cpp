#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+10;
ll c,n,m,d,q,w[M],k[510],s1,s2,x,y;
bool vis[20];
ll minn=LLONG_MAX,wa[510][510],pos1,pos2;
struct node{
	ll v;
	ll w,st;
};
vector<long long> a[510],t[510];
vector<node> dis[510],adj[510];
void dfs(ll u,ll v,ll ans)
{
	if(u==v)
	{
		minn=min(minn,ans+adj[v][1].st);
		return;
	}
	vis[u]=true;
	ll len=dis[u].size();
	for(int i=0;i<=len-1;i++)
	{
		for(int j=1;j<=pos1;j++)
		{
			for(int l=1;l<=pos2;l++)
			{
				if(!vis[dis[u][i].v] && (wa[u][j]==wa[dis[u][i].v][j] || wa[u][l]==wa[dis[u][i].v][l]))
					dfs(dis[u][i].v,v,ans);
				else if(!vis[dis[u][i].v])
					dfs(dis[u][i].v,v,ans+adj[u][wa[u][j]-1].st+adj[u][wa[dis[u][i].v][l]-1].st);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		pos2++;
		pos1++;
		for(int j=1;j<=k[i];j++)
		{
			cin>>s1>>s2;
			a[i].push_back(s1);
			wa[s1][pos1]=i;
			t[i].push_back(s2);
			wa[s2][pos2]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int u=0;u<=k[i]-1;u++)
		{
			for(int v=u+1;v<=k[i]-1;v++)
			{
				dis[a[i][u]].push_back({a[i][v],w[a[i][v]],t[i][v]});
				adj[a[i][u]].push_back({a[i][u],w[a[i][u]],t[i][u]});
				dis[a[i][v]].push_back({a[i][u],w[a[i][u]],t[i][u]});
				adj[a[i][v]].push_back({a[i][v],w[a[i][v]],t[i][v]});
			}
		}
	}
	while(q--)
	{
		cin>>x>>y;
		minn=LLONG_MAX;
		memset(vis,false,sizeof(vis));
		dfs(x,y,w[x]+w[y]+adj[x][1].st);
		cout<<minn<<"\n";
	}
	return 0;
}