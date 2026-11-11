#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ep emplace
#define pii pair<ll,ll>

using namespace std;
const int INF=0x3f3f3f3f3f3f3f3f;
const int M=5e5+5;
const int X=1e3+5; 
const int N=505;
int c,n,m,d,q,w[M],k[N],a[N][X];
ll ans,t[N][X],kk[N][X],dis[1005][1005];
bool vis[X][X],v[1005];
vector<int> xl[N];
vector<int> tz[1005];
vector<pii>e[1005];
void dfs(int now,int y,int nowxl,ll sum)
{
	if(now==y)
	{
		ans=min(ans,sum);
		return ;
	}
//	if(sum>=dis[nowxl][now])return ;
	vis[nowxl][now]=1;
//	dis[nowxl][now]=sum;
	for(auto p:tz[now])//第P线路 
	{
		if(p==nowxl)continue;
		for(auto h:xl[p])//在h站停靠 
		{
			if(h==now||vis[p][h])continue;
	//		cout<<now<<' '<<p<<' '<<h<<' '<<kk[p][now]<<' '<<kk[p][h]<<'\n';
			dfs(h,y,p,sum+kk[p][now]+kk[p][h]);
		}
	}
}
void dij(int s)
{
	dis[s][s]=0;
	memset(v,0,sizeof v);
	priority_queue<pii>q;
	q.ep(0,s);
	while(!q.empty())
	{
		int u=q.top().se;
		q.pop();
		if(v[u])continue;
		v[u]=1;
		for(auto p:e[u])
		{
			int v;ll w;
			tie(v,w)=p;
			if(dis[s][v]>dis[s][u]+w)
			{
				dis[s][v]=dis[s][u]+w;
				q.ep(-dis[s][v],v);
			}
		}
	}
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	if(c>=7&&c<=11)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			for(int j=1;j<=k[i];j++)
				cin>>a[i][j]>>t[i][j];
			e[a[i][1]].pb({a[i][2],t[i][1]+t[i][2]});
			e[a[i][2]].pb({a[i][1],t[i][1]+t[i][2]});
		}
		memset(dis,0x3f,sizeof dis);
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			if(dis[x][y]<=INF/2)cout<<dis[x][y]+w[x]+w[y]<<'\n';
			else
			{
				dij(x);
				cout<<dis[x][y]+w[x]+w[y]<<'\n';
			}
		}
		return 0; 
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			kk[i][a[i][j]]=t[i][j];
			xl[i].pb(a[i][j]);
			tz[a[i][j]].pb(i);
		}
	}
//	memset(dis,0x3f,sizeof dis); 
	while(q--)
	{
		int x,y;ans=INF;
		memset(vis,0,sizeof vis);
		cin>>x>>y;
		for(auto p:tz[x])
		{
			for(auto h:xl[p])
			{
				if(h==x)continue;
		//		cout<<p<<' '<<h<<' '<<kk[p][x]+kk[p][h]<<'\n';
				dfs(h,y,p,kk[p][x]+kk[p][h]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}

