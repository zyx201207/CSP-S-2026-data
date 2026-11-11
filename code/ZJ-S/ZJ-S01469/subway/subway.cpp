#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,d,q;
ll w[500005];
ll T[500005][25];
ll cnt[500005][25];
int D[500005];
ll dp[505][505];
void solve() {
	scanf("%d%d%d%d",&n,&m,&d,&q);
	for(int i=1; i<=m; i++) {
		scanf("%lld",&w[i]);
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			dp[i][j]=1e16;
		}
		dp[i][i]=0;
	}
	for(int i=1; i<=n; i++) {
		int k;
		scanf("%d",&k);
		for(int j=1; j<=k; j++) {
			int e;
			scanf("%d",&e);
			D[e]++;
			scanf("%lld",&T[e][D[e]]);
			cnt[e][D[e]]=i;
			for(int u=1; u<=D[e]; u++) {
				dp[i][cnt[e][u]]=dp[cnt[e][u]][i]=min(min(dp[cnt[e][u]][i],dp[i][cnt[e][u]]),
				                                      T[e][D[e]]+T[e][u]);
			}
		}
	}
	for(int u=1; u<=n; u++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				dp[j][i]=dp[i][j]=min(min(dp[i][j],dp[j][i]),
				                      min(dp[i][u],dp[u][i])+min(dp[u][j],dp[j][u]));
			}
		}
	}
	while(q--) {
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=1e16;
		for(int i=1; i<=D[x]; i++) {
			for(int j=1; j<=D[y]; j++) {
				ans=min(ans,T[x][i]+T[y][j]+dp[cnt[x][i]][cnt[y][j]]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	scanf("%d",&c);
	solve();
	return 0;
}