#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int M=5e5+5,N=505;
int c,n,m,d,q;
int w[M],k[N];
vector<pair<int,int>> a[N],p[M];
int mp[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(mp,0x3f,sizeof(mp));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;++i) mp[i][i]=0;
	for(int i=1;i<=m;++i) scanf("%lld",&w[i]);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];++j)
		{
			int x,y;
			scanf("%lld%lld",&x,&y);
			a[i].push_back(make_pair(x,y));
			p[x].push_back(make_pair(i,y));
		}
		sort(a[i].begin(),a[i].end());
	}
	for(int i=1;i<=m;++i)
	{
		int l=p[i].size();
		for(int t=0;t<l;++t)
			for(int y=t+1;y<l;++y)
			{
				auto h=p[i][t],g=p[i][y];
				mp[h.fi][g.fi]=mp[g.fi][h.fi]=min(mp[h.fi][g.fi],h.se+g.se);
			}
	}
	for(int l=1;l<=n;++l)
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				mp[i][j]=mp[j][i]=min(mp[i][j],mp[i][l]+mp[l][j]);
	while(q--)
	{
		int x,y,ans=1e18;
		scanf("%lld%lld",&x,&y);
		for(auto i:p[x])
			for(auto j:p[y])
				ans=min(ans,mp[i.fi][j.fi]+i.se+j.se);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}