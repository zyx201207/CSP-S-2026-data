#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=0x1f1f1f1f1f1f1f1fll;
int tid,n,m,D,q;
int sta[500020];
vector<pair<int,int>> met[500020];
int dis[505][505];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>tid>>n>>m>>D>>q;
	for(int i=1;i<=m;i++) scanf("%lld",&sta[i]);
	memset(dis,0x1f,sizeof(dis));
	for(int i=1,k;i<=n;i++)
	{
		scanf("%lld",&k);dis[i][i]=0;
		for(int j=1,x,y;j<=k;j++) scanf("%lld%lld",&x,&y),met[x].push_back({i,y});
	}
	for(int i=1;i<=m;i++) for(pair<int,int> x:met[i]) for(pair<int,int> y:met[i]) dis[x.first][y.first]=min(dis[x.first][y.first],x.second+y.second);
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) if(dis[i][k]<inf) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1,x,y;i<=q;i++)
	{
		scanf("%lld%lld",&x,&y);
		int ans=inf;
		for(pair<int,int> X:met[x])for(pair<int,int> Y:met[y])
		{
			ans=min(ans,X.second+dis[X.first][Y.first]+Y.second);
		}
		printf("%lld\n",ans+sta[x]+sta[y]);
	}
}
