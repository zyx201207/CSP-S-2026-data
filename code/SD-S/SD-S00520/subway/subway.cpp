#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int c,n,m,d,q,w[N],dis[505][505],k,ai,ti,cnt[N],x,y,ans;
pair<int,int> to[N][22];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>ai>>ti;
			to[ai][++cnt[ai]]={i,ti};
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int k1=1;k1<=cnt[i];k1++)
			for(int k2=1;k2<=cnt[i];k2++)
				dis[to[i][k1].first][to[i][k2].first]=min(dis[to[i][k1].first][to[i][k2].first],to[i][k1].second+to[i][k2].second);
	for(int k=1;k<=n;k++)
		for(int u=1;u<=n;u++)
			for(int v=1;v<=n;v++)
				dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
	while(q--)
	{
		cin>>x>>y;
		ans=1e18;
		for(int i=1;i<=cnt[x];i++)
			for(int j=1;j<=cnt[y];j++)
				ans=min(ans,dis[to[x][i].first][to[y][j].first]+to[x][i].second+to[y][j].second);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}

