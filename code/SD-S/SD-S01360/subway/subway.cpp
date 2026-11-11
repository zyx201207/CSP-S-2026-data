#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
const int N=510,M=5.1e5+10;
const int P=1e9+7,Inf=1e18;

int n,m,d,q,cnt;
int a[M],dis[N][N];
vector<pii> e[M];

void add(int u,int v,int w)
{
	e[u].pb({v,w});
	e[v].pb({u,w});
}

void fld()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int tmp;
	memset(dis,0x3f3f,sizeof(dis));
	cin>>tmp>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int u,t;
			cin>>u>>t;
			add(i,u+n,t);
		}
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=0;i<(int)e[k+n].size();i++)
		{
			for(int j=0;j<(int)e[k+n].size();j++)
			{
				if(i==j)continue;
				pii u=e[k+n][i],v=e[k+n][j];
				dis[u.fi][v.fi]=min(dis[u.fi][v.fi],v.se+u.se);
				dis[v.fi][u.fi]=min(dis[v.fi][u.fi],v.se+u.se);
			}
		}
	}
	fld();
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		int ans=Inf;
		for(auto x:e[u+n])
			for(auto y:e[v+n])
			{
				ans=min(ans,dis[x.fi][y.fi]+x.se+y.se);
			}
		ans+=a[u]+a[v];
		cout<<ans<<'\n';
	}
	return 0;
}


