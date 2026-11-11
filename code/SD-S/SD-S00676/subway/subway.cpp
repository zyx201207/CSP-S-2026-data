#include <bits/stdc++.h>
#define CHECK_SIZE(x)						\
	cout<<#x<<": "              			\
		<<sizeof(x)%(1<<10)<<"B "   		\
		<<((sizeof(x)%(1<<20))>>10)<<"KB "	\
		<<sizeof(x)/(1<<20)<<"MB\n"		  
#define fi first 
#define se second
using namespace std;
using ll = long long;
const int N=507;
const int M=5e5+7;
const int D=27;
const int Q=1e5+7;
const int K=5e5+7;
const int MN=M+N;
const int MM=K<<1;
struct edge
{
	int to;
	int w;
	int nxt;
}e[MM];
int head[MN],tot;
void add(int u,int v,int w)
{
	e[++tot]={v,w,head[u]};
	head[u]=tot;
}
int n,m,d,q;
ll dis[MN],Dis[N][N];
bitset<MN>vis;
int subW[M];
vector<pair<int,int>>sub[M];
using pli=pair<ll,int>;
void dijikstra(int st)
{
	priority_queue<pli,vector<pli>,greater<pli>>q;
	
	vis.reset();
	memset(dis,0x3f,sizeof dis);
	dis[st]=0;
	q.push({0,st});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u]=true;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			ll w=e[i].w;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
//	CHECK_SIZE(e);
//	CHECK_SIZE(head);
//	CHECK_SIZE(dis);
//	CHECK_SIZE(vis);
	
	int C;
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>subW[i];
	for(int u=1;u<=n;u++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int v,w;
			cin>>v>>w;
			sub[v].push_back({u,w});
			v+=n;
			add(u,v,w);
			add(v,u,w);
		}
	}
	
//	for(int u=1;u<=n;u++)
//		for(int i=head[u];i;i=e[i].nxt)
//			cout<<u<<' '<<e[i].to<<' '<<e[i].w<<'\n';
	for(int u=1;u<=n;u++)
	{
		dijikstra(u);
//		cout<<"U: "<<u<<'\n'; 
//		for(int v=1;v<=n+m;v++)
//			cout<<"v: "<<v<<' '<<dis[v]<<'\n';
		for(int v=1;v<=n;v++)
			Dis[u][v]=dis[v];
	}
	
	while(q--)
	{
		int u,v;
		cin>>u>>v;
//		cout<<"\n\n";
//		cout<<u<<' '<<v<<'\n';
		ll ans=1e18;
		for(const auto&x:sub[u])
			for(const auto&y:sub[v])
			{
//				cout<<x.fi<<' '<<y.fi<<'\n';
				ans=min(ans,subW[u]+subW[v]+Dis[x.fi][y.fi]+x.se+y.se);
			}
		cout<<ans<<'\n'; 
	}
//	
	
	return 0;
}
