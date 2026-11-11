#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int N=500+10;
const int M=5e5+10;
const int inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
vector<pair<int,int>> G[M];
int dis[N][N];
int t[M]; 
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(int	i=1;i<=m;i++) cin>>t[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int a,t;
			cin>>a>>t;
			G[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<G[i].size();j++)
		{
			int u=G[i][j].fi,wu=G[i][j].se;
			for(int k=j+1;k<G[i].size();k++) dis[u][G[i][k].fi]=dis[G[i][k].fi][u]=min(dis[u][G[i][k].fi],wu+G[i][k].se);
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) if(dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j];
		}
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		int res=inf;
		for(int i=0;i<G[u].size();i++)
		{
			for(int j=0;j<G[v].size();j++) res=min(res,t[u]+t[v]+G[u][i].se+G[v][j].se+dis[G[u][i].fi][G[v][j].fi]);
		}
		cout<<res<<endl;
	}
	return 0;
}
