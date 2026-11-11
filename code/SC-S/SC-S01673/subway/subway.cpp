#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005];
int dis[505][505];
vector<pair<int,int> >eg[500005],eg2[505];
priority_queue<pair<int,int> >p;
void dfs(int st)
{
	for(int i=1;i<=n;i++) dis[st][i]=1e18;
	dis[st][st]=0;
	p.push({0,st});
	while(!p.empty())
	{
		int u=p.top().second,ds=p.top().first;
		p.pop();
		if(-ds!=dis[st][u]) continue;
		for(auto now:eg2[u])
		{
			int v=now.first,W=now.second;
			if(dis[st][u]+W<dis[st][v])
			{
				dis[st][v]=dis[st][u]+W;
				p.push({-dis[st][v],v});
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){cin>>k;for(int j=1,a,t;j<=k;j++){cin>>a>>t;eg[a].push_back({i,t});}}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=1e18;
	for(int i=1;i<=m;i++)
		for(int id1=0;id1<(int)eg[i].size();id1++)
			for(int id2=id1+1;id2<(int)eg[i].size();id2++)
			{
				if(id1==id2) continue;
				int u=eg[i][id1].first,v=eg[i][id2].first;
				dis[u][v]=min(dis[u][v],eg[i][id1].second+eg[i][id2].second);
			}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(dis[i][j]!=1e18||dis[j][i]!=1e18) eg2[i].push_back({j,min(dis[i][j],dis[j][i])});
	for(int i=1;i<=n;i++) dfs(i);
	while(q--)
	{
		int x,y;
		int ans=1e18;
		cin>>x>>y;
		for(auto a:eg[x])
			for(auto b:eg[y])
				ans=min(ans,dis[a.first][b.first]+a.second+b.second);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}