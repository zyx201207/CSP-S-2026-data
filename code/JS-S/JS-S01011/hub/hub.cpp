#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int> g[N];
int dis[N][N];
void dfs(int u,int fa,int rt){
	for(int v:g[u]){
		if(v==fa) continue;
		dis[rt][v]=dis[rt][u]+1,dfs(v,u,rt);
	}
}
int mark[N],vis[N];
void dfs1(int u,int fa){
	vis[u]=1;
	for(int v:g[u]){
		if(v==fa or !mark[v] or vis[v]) continue;
		dfs1(v,u);
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,k;cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=0;
		for(int i=1,u,v;i<n;i++) cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
		for(int i=1;i<=n;i++) dfs(i,0,i);
		int ans=1e9;
		for(int i=0;i<(1<<n);i++){
			if(__builtin_popcount(i)!=k) continue;
			for(int j=1;j<=n;j++) mark[j]=0,vis[j]=0;
			for(int j=1;j<=n;j++) if(i&(1<<(j-1))) mark[j]=1;
			int cnt=0,res=0;
			for(int j=1;j<=n;j++) if(mark[j] and !vis[j]) dfs1(j,0),cnt++;
			if(cnt>2) continue; 
			for(int j=1;j<=n;j++){
				int now=1e9;
				for(int k=1;k<=n;k++) if(mark[k]) now=min(now,dis[j][k]);
				res=max(res,now);
			}ans=min(ans,res);
			/*if(res==1){
				cout<<cnt<<endl;
				for(int j=1;j<=n;j++) cout<<mark[j]<<" ";
				cout<<endl;
			}*/
		}cout<<ans<<"\n";
	}
	return 0;
}
