#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[505050],k,a,t;
struct node{
	int u,val;
};
vector<node> e[505050];
long long dis[550][550];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a>>t,e[a].push_back({i,t});
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int len=(int)(e[i].size());
		for(int x=0;x<len;x++)
		{
			for(int y=x+1;y<len;y++)
			{
				int xx=e[i][x].u,yy=e[i][y].u;
				long long zz=e[i][x].val+e[i][y].val;
				dis[xx][yy]=dis[yy][xx]=min({dis[xx][yy],dis[yy][xx],zz});
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
//	for(int i=1;i<=n;i++,cout<<"\n")
//		for(int j=1;j<=n;j++) cout<<dis[i][j]<<" ";
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(auto i:e[x])
			for(auto j:e[y])
				ans=min(ans,1ll*w[x]+w[y]+i.val+j.val+dis[i.u][j.u]);
		cout<<ans<<"\n";
	}
	return 0;
}