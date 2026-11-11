#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qq,ww[500010];
vector<long long> to[500010],w[500010],too[510],wo[510];
long long INF=100000000000000000,ans;
long long dist[510][510],dis[510][510];
struct node{
	int id;
	long long dist;
	bool operator<(const node&t) const
	{
		return dist>t.dist;
	}
};
priority_queue<node> q;
void dij(int s)
{
	for(int i=1;i<=500;i++) dist[s][i]=INF;
	while(!q.empty()) q.pop();
	dist[s][s]=0;
	q.push(node{s,0});
	while(!q.empty())
	{
		node nd=q.top();
		q.pop();
		int u=nd.id,ds=nd.dist;
		for(int i=0;i<(int)too[u].size();i++)
		{
			int ws=wo[u][i],v=too[u][i];
			if(dist[s][v]>ds+ws)
			{
				dist[s][v]=ds+ws;
				q.push(node{v,dist[s][v]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&qq);
	for(int i=1;i<=m;i++) scanf("%d",&ww[i]);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a;
			long long t;
			scanf("%d %lld",&a,&t);
			to[a].push_back(i);
			w[a].push_back(t);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<(int)to[i].size();j++)
		{
			int u=to[i][j],wu=w[i][j];
			for(int k=j+1;k<(int)to[i].size();k++)
			{
				int v=to[i][k],wv=w[i][k];
				long long sum=(long long)wv+(long long)wu;
				if(dis[u][v]==0)
				{
					dis[u][v]=sum;
					dis[v][u]=sum;
				}
				else if(dis[u][v]<sum)
				{
					dis[u][v]=sum;
					dis[v][u]=sum;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(dis[i][j]==0) continue;
			else
			{
				too[i].push_back(j);
				too[j].push_back(i);
				wo[i].push_back(dis[i][j]);
				wo[j].push_back(dis[j][i]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dij(i);
	}
	while(qq--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ans=ww[x]+ww[y];
		long long sum=INF;
		for(int j=0;j<(int)to[x].size();j++)
		{
			long long u=to[x][j],wu=w[x][j];
			for(int k=0;k<(int)to[y].size();k++)
			{
				long long v=to[y][k],wv=w[y][k];
				sum=min(sum,wv+wu+dist[u][v]);
			}
		}
		printf("%lld\n",ans+sum);
	}
	return 0;
}
