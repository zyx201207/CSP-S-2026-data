#include<iostream>
#include<vector>
using namespace std;
const int N=40;
int c,T,n,k,vis[N],x[N],dis[N][N]; 
vector<int> e[N];
void dfs2(int u,int fa,int s){
	for(auto v:e[u]){
		if(v==fa) continue;
		dis[s][v]=dis[s][u]+1;
		dfs2(v,u,s);
	}
}
void dfs(int u,int fa){
	vis[u]=1;
	for(auto v:e[u]){
		if(v==fa||!x[v]) continue;
		dfs(v,u);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=1;i<=n;i++) dfs2(i,0,i);
		int ans=0;
		for(int s=0;s<(1<<n);s++)if(__builtin_popcount(s)==k){
			for(int i=1;i<=n;i++)vis[i]=0,x[i]=((1<<i-1)&s);
			int cnt=0;
			for(int i=1;i<=n;i++)if(!vis[i])cnt++,dfs(i,0);
			int mx=0;
			for(int i=1;i<=n;i++) {
				int mn=1e9;
				for(int j=1;j<=n;j++) if(x[j]) mn=min(mn,dis[i][j]);
				mx=max(mx,mn);
			}
			ans=max(ans,mx); 
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
}
