#include<bits/stdc++.h>
#define i128 __int128
#define ll long long
#define Pii pair<int,int>
#define fi first
#define se second

using namespace std;
const int N=5e2+10;
const int M=5e5+10;

int n,m,q,cnt[M],p[M],b[M][21],w[M][21]; ll ans,dp[N][N];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>n>>m>>q>>q; int k,x,y;
	for(int i=1;i<=m;++i) cin>>p[i];
	for(int i=1;i<=n;++i)
	{
		cin>>k;
		while(k--) cin>>x>>y,b[x][++cnt[x]]=i,w[x][cnt[x]]=y;
	}
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;++i) dp[i][i]=0;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=cnt[i];++j)
			for(int k=j+1;k<=cnt[i];++k)
				dp[b[i][j]][b[i][k]]=dp[b[i][k]][b[i][j]]
				=min(dp[b[i][j]][b[i][k]],(ll)w[i][j]+w[i][k]);
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	while(q--)
	{
		cin>>x>>y; ans=1e18;
		for(int i=1;i<=cnt[x];++i)
			for(int j=1;j<=cnt[y];++j)
				ans=min(ans,dp[b[x][i]][b[y][j]]+w[x][i]+w[y][j]);
		cout<<ans+p[x]+p[y]<<"\n";
	}
	return 0;
}