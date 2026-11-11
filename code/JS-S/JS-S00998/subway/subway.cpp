#include <bits/stdc++.h>
#define int long long
using namespace std;
int dis[505][505],Subid,n,m,D,Q,w[500005];
vector<pair<int,int>> g[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%lld%lld%lld%lld%lld",&Subid,&n,&m,&D,&Q);
	for(int i=1;i<=m;i++) scanf("%lld",w+i);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		int siz,x,y;scanf("%lld",&siz);
		while(siz--) scanf("%lld%lld",&x,&y),g[x].emplace_back(i,y);
	}
	for(int i=1;i<=m;i++) for(auto p:g[i]) for(auto q:g[i]) if(p.first!=q.first) dis[p.first][q.first]=min(dis[p.first][q.first],p.second+q.second);
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(Q--)
	{
		int x,y;scanf("%lld%lld",&x,&y);int ans=1e18;
		for(auto p:g[x]) for(auto q:g[y]) ans=min(ans,dis[p.first][q.first]+p.second+q.second);
		printf("%lld\n",ans+w[x]+w[y]);
	}
}