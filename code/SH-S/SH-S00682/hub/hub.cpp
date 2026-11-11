#include<bits/stdc++.h>
using namespace std;
const int N=1005;
vector<int> g[N];
int ok[N],vis[N],d[N][N],dis[N];
void dfs(int u,int fa){
	vis[u]=1;
	for(int v:g[u]) if(v!=fa and ok[v]) dfs(v,u);
}
void DFS(int st,int u,int fa){
	for(int v:g[u]) if(v!=fa) d[st][v]=d[st][u]+1,DFS(st,v,u);
}
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) DFS(i,i,0);
	int ans=1e9;
	for(int S=0;S<(1<<n);S++){
		if(__builtin_popcount(S)!=k) continue;
		for(int i=1;i<=n;i++) ok[i]=(S>>i-1)&1,vis[i]=0;
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(ok[i] and !vis[i]) dfs(i,0),cnt++;
		if(cnt>2) continue;
		int res=0;
		for(int i=1;i<=n;i++){
			dis[i]=1e9;
			for(int j=1;j<=n;j++)
				if(ok[j]) dis[i]=min(dis[i],d[i][j]);
			res=max(res,dis[i]);
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
