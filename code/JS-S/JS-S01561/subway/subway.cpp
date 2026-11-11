#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
using namespace std;
ll dp[505][505],w[500005];
unordered_map<int,ll>mp[505];
vector<int>G[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,0x3f,sizeof dp);
	int n,c,m,d,q; scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++)	scanf("%lld",&w[i]);
	for(int i = 1;i <= n;i++){
		dp[i][i]=0;
		int k; scanf("%d",&k); 
		while(k--){
			int x;
			ll y; scanf("%d%lld",&x,&y);
			mp[i][x]=y;
			G[x].push_back(i);
		}
	}
	for(int i = 1;i <= m;i++){
		for(auto X : G[i]){
			for(auto Y : G[i]){
				dp[X][Y]=dp[Y][X]=min(dp[X][Y],mp[X][i]+mp[Y][i]);
			}
		}
	}
	
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j){
			for(int k = 1;k <= n;++k){
				dp[i][j]=dp[j][i]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int x,y; scanf("%d%d",&x,&y);
		ll ans = 1e18;
		for(auto X : G[x]){
			for(auto Y : G[y]){
				ans=min(ans,mp[X][x]+mp[Y][y]+dp[X][Y]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}