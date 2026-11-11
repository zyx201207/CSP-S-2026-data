#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
const long long inf=1e16;
int Case,n,m,PassD,Qn,w[M],head[N];
struct Edge{int u,v;long long w;int nxt;}e[N*N];
vector<pair<int,int> >ac[N+M];
long long sdis[N][N];
bool vis[N];long long dis[N];
struct Node
{
	int nd;long long dist;
	bool operator<(const Node &ex)const{return dist>ex.dist;}
};
priority_queue<Node>q;
inline void Dijkstra(int S)
{
	for(int i=1;i<=n;i++) dis[i]=inf,vis[i]=0;
	dis[S]=0;q.push((Node){S,0});
	while(!q.empty())
	{
		Node cur=q.top();q.pop();
		int u=cur.nd;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u],v,w;~i;i=e[i].nxt)
		{
			v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push((Node){v,dis[v]});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>Case>>n>>m>>PassD>>Qn;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k,u;i<=n;i++)
	{
		cin>>k;u=i+m;
		for(int j=1,v,w;j<=k;j++)
		{
			cin>>v>>w;
			ac[u].push_back(make_pair(v,w));
			ac[v].push_back(make_pair(u,w));
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) sdis[i][j]=inf;
	for(int i=1;i<=n;i++) sdis[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		int u=i+m;
		for(int j=0;j<ac[u].size();j++)
		{
			int trans=ac[u][j].first,w1=ac[u][j].second;
			for(int k=0;k<ac[trans].size();k++)
			{
				int v=ac[trans][k].first,w2=ac[trans][k].second;
				if(v==u) continue;
				sdis[u-m][v-m]=min(sdis[u-m][v-m],1ll*(w1+w2));
			}
		}
	}
	for(int i=1;i<=n;i++) head[i]=-1;
	for(int i=1,c=0;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j||sdis[i][j]==inf) continue;
			e[c]=(Edge){i,j,sdis[i][j],head[i]},head[i]=c++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		Dijkstra(i);
		for(int j=1;j<=n;j++)
			sdis[i][j]=min(sdis[i][j],dis[j]);
	}
	while(Qn--)
	{
		int s,t;cin>>s>>t;
		long long ans=inf;
		for(int i=0;i<ac[s].size();i++)
		{
			int u=ac[s][i].first-m,w1=ac[s][i].second;
			for(int j=0;j<ac[t].size();j++)
			{
				int v=ac[t][j].first-m,w2=ac[t][j].second;
				ans=min(ans,min(sdis[u][v],sdis[v][u])+1ll*(w1+w2));
			}
		}
		cout<<ans+w[s]+w[t]<<'\n';
	}
	return 0;
}
