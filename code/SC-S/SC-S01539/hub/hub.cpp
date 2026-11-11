#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+5,M=15;
int n,C,T,m,ans,KS,bj[N],vis[N],dis[M][M];
vector<int>e[N];
void dfs1(int u) {
	if(!vis[u]) vis[u]=1;
	for(auto v:e[u]) {
		if(!bj[v]) continue;
		if(!vis[v])dfs1(v);
	}
}
int check() {
	int sl=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++) {
		if(!vis[i]&&bj[i])++sl,dfs1(i);
	}
	if(sl>2) return n*n;
	int summ=0;
	for(int i=1;i<=n;i++){
		if(!bj[i]) {
			int minn=n;
			for(int j=1;j<=n;j++){
				if(!bj[j]) continue;
				minn=min(minn,dis[i][j]);
			}
			summ=max(minn,summ);
		}
	}
	return summ;
}
void dfs(int x,int sl) {
	// cerr<<x<<' '<<sl<<' '<<ans<<'\n';
	if(sl>m) return;
	if(x==n+1&&sl!=m) return ;
	if(x==n+1&&sl==m) {
		ans=min(ans,check());
		return ;
	}
	dfs(x+1,sl);
	bj[x]=1;
	dfs(x+1,sl+1);
	bj[x]=0;
}
void dfs2(int st,int u,int pre){
	dis[st][u]=dis[st][pre]+1;
	if(st==u) dis[st][u]=0;
	for(auto v:e[u]) 
		if(pre^v) dfs2(st,v,u);
}
void solve() {
	for(int i=1;i<=n;i++) {dfs2(i,i,0);}
	ans=1e9;
	for(int i=1;i<=n;i++) bj[i]=0;
	dfs(1,0);
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++) e[i].clear();
}

signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--) {
		cin>>n>>m;
		memset(dis,0,sizeof dis);
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(C<=3) solve();
	}
	return 0;
}