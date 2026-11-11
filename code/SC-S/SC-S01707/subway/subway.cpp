#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn=5e5+114;
const int mxm=514;
const int mxd=25;
int n,m,d,q,Test_Case_ID;
int W[mxn],K[mxn],dis[mxm][mxm];
bool vis[mxm][mxm];
vector <pair<int,int>> g[mxn],e[mxm];
inline void dij(int st)
{
	priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
	Q.push({0,st});
	memset(dis[st],0x3f,sizeof(dis[st]));
	dis[st][st]=0;
	while (!Q.empty())
	{
		int u=Q.top().second; Q.pop();
		if (vis[st][u]) continue;
		vis[st][u]=1;
		for (auto tmp:e[u])
		{
			int v=tmp.first,w=tmp.second;
			if (dis[st][u]+w<dis[st][v])
			{
				dis[st][v]=dis[st][u]+w;
				Q.push({dis[st][v],v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>Test_Case_ID>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>W[i];
	for (int i=1;i<=n;i++)
	{
		cin>>K[i]; dis[i][i]=0;
		for (int j=1,v,w;j<=K[i];j++) cin>>v>>w,g[v].emplace_back(i,w);
	}
	for (int i=1;i<=m;i++) for (auto p1:g[i]) for (auto p2:g[i])
	{
		dis[p1.first][p2.first]=min(dis[p1.first][p2.first],p1.second+p2.second);
		dis[p2.first][p1.first]=dis[p1.first][p2.first];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (i==j) continue;
			e[i].emplace_back(j,dis[i][j]);
		}
	}
	for (int i=1;i<=n;i++) dij(i);
	int Qx,Qy;
	while (q--)
	{
		cin>>Qx>>Qy;
		int ans=LLONG_MAX;
		for (auto p1:g[Qx]) for (auto p2:g[Qy]) ans=min(ans,dis[p1.first][p2.first]+p1.second+p2.second);
		cout<<ans+W[Qx]+W[Qy]<<'\n';
	}
	return 0;
}
//AC100pts