#include<bits/stdc++.h>
using namespace std;
#define maxn 500505
#define ll long long
priority_queue<pair<ll,int> > q;
struct node
{
	int to,nxt;
	ll w;
}e[maxn*20];
int c,n,m,d,qq;
ll ww[maxn],dist[maxn];
int cnt,head[maxn];
bool vis[maxn];
void add(int u,int v,ll w)
{
//	cout<<u<<" "<<v<<" "<<w<<'\n';
	e[++cnt].nxt=head[u];
	e[cnt].to=v;
	e[cnt].w=w;
	head[u]=cnt;
}
void di(int root)
{
	dist[root]=0;
	vis[root]=true;
	q.push(make_pair(0,root));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		vis[u]=true;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			ll w=e[i].w;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				if(!vis[v])q.push(make_pair(-dist[v],v));
			}
		}
	}
}
void init()
{
	memset(vis,0,sizeof vis);
	memset(dist,0x3f,sizeof dist);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)cin>>ww[i];
	for(int i=1;i<=n;i++)
	{
		int k,idx;
		ll tim;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>idx>>tim;
			add(idx,m+i,tim);
			add(m+i,idx,tim);
		}
	}
	if(qq<=2000)
	{
		while(qq--)
		{
			init();
			int x,y;
			cin>>x>>y;
			di(x);
			cout<<ww[x]+dist[y]+ww[y]<<'\n';
		}
	}
	else
	{
		ll ans[m+5][m+5];
		for(int i=1;i<=m;i++)
		{
			init();
			di(i);
			for(int j=i+1;j<=m;j++)
				ans[i][j]=ans[j][i]=ww[i]+ww[j]+dist[j];
		}
		while(qq--)
		{
			int x,y;
			cin>>x>>y;
			cout<<ans[x][y]<<'\n';
		}
	}
	return 0;
}