#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+100;
int c,n,m,d,qq,w[N],ans[605][605],vis[5005],dis[5005],tot=0;
struct node
{
	int v,w;
	bool operator < (const node &x) const
	{
		return x.w<w;
	}
};
struct nod
{
	int num,t;
};
priority_queue <node> q;
vector <node> graph[N];
vector <nod> book[N];
void dij(int x)
{
	while(!q.empty()) q.pop();
	memset(dis,127,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=0;q.push({x,0});
	while(!q.empty())
	{
		node k=q.top();q.pop();
		if(vis[k.v]) continue;
		vis[k.v]=1;
		for(int i=0;i<graph[k.v].size();i++)
		{
			node v=graph[k.v][i];
			if(dis[k.v]+v.w<dis[v.v])
			{
				dis[v.v]=dis[k.v]+v.w;
				q.push({v.v,dis[v.v]});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1,u,v;j<=k;j++)
		{
			cin>>u>>v;
			book[u].push_back({i,v});
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<book[i].size();j++)
			for(int g=j+1;g<book[i].size();g++)
				graph[book[i][j].num].push_back({book[i][g].num,book[i][g].t+book[i][j].t}),
				graph[book[i][g].num].push_back({book[i][j].num,book[i][g].t+book[i][j].t});
		for(int st=1;st<=n;st++)
		{
			dij(st);
			for(int en=1;en<=n;en++) ans[st][en]=dis[en];
		}
	while(qq--)
	{
		int st,en,res=1e18;cin>>st>>en;
		for(int i=0;i<book[st].size();i++)
			for(int j=0;j<book[en].size();j++)
				res=min(res,ans[book[st][i].num][book[en][j].num]+book[st][i].t+book[en][j].t);
		cout<<res+w[st]+w[en]<<"\n";
	}
	return 0;
}

