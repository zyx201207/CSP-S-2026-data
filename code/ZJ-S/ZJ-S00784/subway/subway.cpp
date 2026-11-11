#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500005],k[500005];
vector<pair<int,int> > line[500005];
int dp[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			int x,y;scanf("%lld %lld",&x,&y);
			line[x].push_back({i,y});
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int i=1;i<=m;i++){
		int sz=line[i].size();
		for(int j=0;j<sz;j++){
			for(int l=0;l<j;l++){
				int u=line[i][j].first,v=line[i][l].first,W=line[i][j].second+line[i][l].second;
				dp[u][v]=dp[v][u]=min(dp[u][v],W);
			}
		}
	}
	for(int K=1;K<=n;K++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[i][K]+dp[K][j]);
	for(int i=1;i<=q;i++){
		int x,y;scanf("%lld %lld",&x,&y);
		int ans=1e18;
		for(auto j:line[x])
			for(auto K:line[y])
				ans=min(ans,dp[j.first][K.first]+w[x]+w[y]+j.second+K.second);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}