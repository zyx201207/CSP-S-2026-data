#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN=505,MAXM=5e5+5;
int c,n,m,d,Q;
ll ans;
int ww[MAXM],dep[MAXM];
ll dis[MAXM],diss[MAXM];
bool vis[MAXM];
int f[10][MAXM];
struct node
{
	int to;ll w;
	bool operator<(const node&others)const{return w>others.w;}
};
vector<node>link[MAXN],xia[MAXM];
priority_queue<node>q;
inline void dijkstra()
{
	q.emplace((node){1,0});dis[1]=0;
	while(!q.empty())
	{
		int u=q.top().to;ll w=q.top().w;q.pop();
		if(dis[u]<w)
			continue;
		for(auto&t:xia[u])
		{
			for(auto&tv:link[t.to])
			{
				int v=tv.to;ll tw=t.w,tww=tv.w;
				if(u==v)
					continue;
				if(dis[v]>dis[u]+tw+tww)
					dis[v]=dis[u]+tw+tww,q.emplace((node){v,dis[v]});
			}
		}
	}
}
inline void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1,f[u][0]=fa,vis[u]=true;
	for(auto&t:xia[u])
		for(auto&tv:link[t.to])
		{
			if(vis[tv.to])
				continue;
			dfs(tv.to,u);
		}
}
inline void init()
{
	for(int j=1;j<10;j++)
		for(int i=1;i<=n;i++)
			f[j][i]=f[j-1][f[j-1][i]];
}
inline int lca(int x,int y)
{
	if(dep[y]<dep[x])
		swap(x,y);
	while(dep[y]>dep[x])
		y=f[__lg(dep[y]-dep[x])][y];
	if(x==y)
		return x;
	for(int j=9;j>=0;j--)
		if(f[j][x]!=f[j][y])
			x=f[j][x],y=f[j][y];
	return x;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	memset(dis,0x7f,sizeof dis);memset(diss,0x7f,sizeof diss);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
		cin>>ww[i];
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		for(int j=1,a,t;j<=k;j++)
			cin>>a>>t,link[i].emplace_back((node){a,t}),xia[a].emplace_back((node){i,t});
	}
	dijkstra(),dfs(1,0),init();
	for(int i=1,x,y;i<=Q;i++)
	{
		cin>>x>>y;ans=0;
		ans+=ww[x]+ww[y]+dis[x]+dis[y];
		int ff=lca(x,y);
		if(ff!=1)
			ans-=2*dis[f[0][ff]];
		
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
