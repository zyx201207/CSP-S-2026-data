//SN-S00226
//n:站台数 m:路线数 cnt:图点数 
#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[500010];
int k[510];
long long dp[2010][2010];
vector <int> g[600010];
bool vis[600010];
int dfs(int x,int s){
	if(x==s) return 1;
	vis[x]=1;
	int mn=1e9;
	for(auto &it:g[x]){
		if(vis[it]==0){
			mn=min(mn,dfs(it,s)+1);
		}
	}
	vis[x]=0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&m,&n,&d,&q);
	if(c>=12 && c<=19){
		int w;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=m;i++){
			scanf("%d",&k[i]);
			for(int j=1;j<=k[i];j++){
				int v;
				scanf("%d%d",&v,&w);
				g[v].push_back(n+i);
				g[n+i].push_back(v);
			}
		}
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			int t=dfs(x,y);
			printf("%lld\n",1ll*w*t);
		}
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int cnt=n+m;
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			dp[i][j]=dp[j][i]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int v,w;
			scanf("%d%d",&v,&w);
			dp[n+i][v]=dp[v][n+i]=w;
		}
	}
	for(int i=1;i<=n+m;i++) dp[i][i]=0;
	for(int k=1;k<=cnt;k++){
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=cnt;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long t=dp[x][y]+a[x]+a[y];
		printf("%lld\n",t);
	}
	return 0;
}
