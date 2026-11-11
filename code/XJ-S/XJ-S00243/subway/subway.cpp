#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,ll> pr;
const int MAXN=505,MAXM=5e5+1000;
int c,n,m,d,q;
ll winto[MAXN];
vector<pr> zt[MAXM];//每个站厅所连的路线 
ll dis[MAXN][MAXN];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)dis[i][j]=1e18;
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		cin>>winto[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l;
		cin>>l;
		for(int j=1;j<=l;j++)
		{
			int v;
			ll w;
			cin>>v>>w;
			zt[v].push_back({i,w});
	
		}
	}
	//cout<<"NO.1"<<endl;
	for(int t=1;t<=m;t++)
	{
		for(int i=0;i<zt[t].size();i++)
		{
			for(int j=i+1;j<zt[t].size();j++)
			{
				int x=zt[t][i].first,y=zt[t][j].first;
				ll w1=zt[t][i].second,w2=zt[t][j].second;
				dis[x][y]=dis[y][x]=min(dis[x][y],w1+w2);
			}
		}
	}
	//cout<<"DIS "<<endl;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	//cout<<"ANS "<<endl;
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		ll ans=1e18;
		for(int i=0;i<zt[u].size();i++)
		{
			for(int j=0;j<zt[v].size();j++)
			{
				int x=zt[u][i].first,y=zt[v][j].first;
				ll w1=zt[u][i].second,w2=zt[v][j].second;
				//dis[x][y]=dis[y][x]=min(dis[x][y],w1+w2);
				ans=min(ans,dis[x][y]+w1+w2);
			}
		}
		cout<<ans+winto[u]+winto[v]<<endl;
	}
}
