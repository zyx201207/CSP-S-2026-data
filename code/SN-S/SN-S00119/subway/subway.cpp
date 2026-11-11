#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q;
const int N=5e5+5;
vector<int>g1[N];//每个地铁站 
vector<int>g2[505];//每条线路 
int t[N][505],w[N],y;
long long dis[N];
bool vis[N];
struct nod
{
	int id;
	long long len;
	bool operator<(const nod &a) const
	{
		if(len==a.len) return id>a.id;
		return len>a.len;
	}
};
void Dijkstra(int S)
{
	memset(vis,0,sizeof vis);
	priority_queue<nod>q;
	q.push({S,w[S]});
	for(int i=1;i<=n;i++) dis[i]=1e18;
	dis[S]=w[S];
	while(!q.empty())
	{
		int x=q.top().id;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=0;i<g1[x].size();i++)
		{
			for(int j=0;j<g2[g1[x][i]].size();j++)
			{
				int to=g2[g1[x][i]][j],len=t[x][g1[x][i]]+t[to][g1[x][i]];
				if(dis[to]>dis[x]+len)
				{
					dis[to]=dis[x]+len;
					//cout<<t[x][g1[x][i]]<<" "<<t[to][g1[x][i]]<<" "<<to<<" "<<dis[to]<<'\n';
					q.push({to,dis[to]});
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&m,&n,&d,&Q);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<=m;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a,ti;
			scanf("%d%d",&a,&ti);
			g2[i].push_back(a);
			g1[a].push_back(i);
			t[a][i]=ti;
		}
	}
	while(Q--)
	{
		int x;
		scanf("%d%d",&x,&y);
		Dijkstra(x);
		printf("%d\n",dis[y]+w[y]);
	}
	return 0;
}
