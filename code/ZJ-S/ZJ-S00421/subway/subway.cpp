#include<bits/stdc++.h>
using namespace std;
const int mx=5e5+10;
long long c,n,m,d,qu;
long long w[mx],a[mx],t[mx];
long long f[510][510];
struct node
{
	long long v;
	long long ut,vt;
	long long id;
};
vector<node>g[mx];
bool vis[mx];
struct point
{
	long long v;
	long long id;
	long long vt;
};
queue<point>q;
int tot1,tot2;
point station[50][2];
void bfs(long long x)
{
	vis[x]=true;
	q.push({x,0,0});
	while(!q.empty())
	{
		point now=q.front();
		q.pop();
		for(int i=0;i<g[now.v].size();i++)
		{
			int v=g[now.v][i].v;
			int vid=g[now.v][i].id;
			if(now.id!=g[now.v][i].id)
			{
				f[now.id][vid]=min(f[now.id][vid],g[now.v][i].ut+now.vt);
				f[vid][now.id]=min(f[vid][now.id],g[now.v][i].ut+now.vt);
			}
			if(!vis[v])
			{
				q.push({v,vid,g[now.v][i].vt});
				vis[v]=true;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&qu);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		long long p=0;
		scanf("%lld",&p);
		for(int j=1;j<=p;j++)
		{
			scanf("%lld%lld",&a[j],&t[j]);
		}
		for(int j=1;j<p;j++)
		{
			g[a[j+1]].push_back({a[j],t[j+1],t[j],i});
			g[a[j]].push_back({a[j+1],t[j],t[j+1],i});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=0x3f3f3f3f3f3f3f3fll;
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int i=1;i<=m;i++)
		if(!vis[i])
			bfs(i);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(qu--)
	{
		long long x,y,ans=0x3f3f3f3f3f3f3f3fll;
		scanf("%lld%lld",&x,&y);
		tot1=0;tot2=0;
		for(int i=0;i<g[x].size();i++)
			station[++tot1][0]={g[x][i].v,g[x][i].id,g[x][i].ut};
		for(int i=0;i<g[y].size();i++)
			station[++tot2][1]={g[y][i].v,g[y][i].id,g[y][i].ut};
		for(int i=1;i<=tot1;i++)
			for(int j=1;j<=tot2;j++)
				ans=min(ans,f[station[i][0].id][station[j][1].id]+station[i][0].vt+station[j][1].vt);
		printf("%lld\n",w[x]+w[y]+ans);
	}
	return 0;
}