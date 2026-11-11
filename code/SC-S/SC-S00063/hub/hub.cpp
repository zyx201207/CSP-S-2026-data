#include<bits/stdc++.h>
#define int long long 
#define ll long long 
#define ld long double
#define db double
using namespace std;
const int N=1e6+5,inf=1e18;
int c,T,n,k,fa[N],cnt,vis[N],dp[N][25],dep[N];
vector<int> vt[N];
void dfs(int u,int fa){
	for(int i=0;(1<<i)<=dep[u];i++){
		dp[u][i]=dp[dp[u][i-1]][i-1];
	}
	for(int i=0;i<(int)vt[u].size();i++){
		int v=vt[u][i];
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		dp[v][0]=u;
		dfs(v,u);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int t=dep[x]-dep[y];
	for(int i=0;(1<<i)<=t;i++){
		if((1<<i)&t){
			x=dp[x][i];
		}
	}
	if(x==y)return x;
	for(int i=20;i>=0;i--){
		if(dp[x][i]!=dp[y][i]){
			x=dp[x][i];y=dp[y][i];
		}
	}
	return dp[x][0];
}
int get(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			fa[i]=i;
			for(int j=0;j<25;j++){
				dp[i][j]=0;
			}
		}
		
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			vt[u].push_back(v);
			vt[v].push_back(u);
		}
		dfs(1,0);
		if(k==2){
			int ans=inf;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j)continue;
					int Max=0;
					for(int k=1;k<=n;k++){
						Max=max(Max,min(get(k,i),get(k,j)));
					}
					ans=min(ans,Max);
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}